#include <stdio.h>
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main(void)
{
    glfwSetErrorCallback(error_callback);

    int WindowWidth = 1280;
    int WindowHeight = 720;
    const char WindowName[] = "Hello World";

    /* Initialize the library */
    if (!glfwInit())
        return(1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(WindowWidth, WindowHeight, WindowName, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return(1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    /* Define shaders */
     const char *vertexShaderSource = 
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "};\0";

    const char *fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "};\0";

    /* Create shaders */
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);


    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    /* detect errors in shader compile */
    int successVertexShader;
    char infoLogVertexShader[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &successVertexShader);

    if (!successVertexShader)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLogVertexShader);
        printf("ERROR::SHADER::VERTEX::COMPILATION::FAILED::RUH-ROH-RAGGY!\n%s\n", infoLogVertexShader);
        
    }


    int successFragmentShader;
    char infoLogFragmentShader[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &successFragmentShader);

    if (!successFragmentShader)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLogFragmentShader);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION::FAILED::RUH-ROH-RAGGY!\n%s\n", infoLogFragmentShader);
        
    }

    /* Create shader program */
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    int successShaderProgram;
    char infoLogShaderProgram[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &successShaderProgram);
    if(!successShaderProgram)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLogShaderProgram);
        printf("ERROR::SHADER::PROGRAM::COMPILATION::FAILED::RUH-ROH-RAGGY!\n%s\n", infoLogShaderProgram);
    }

    /* Apply out shader program and delete indivisual shaders */
    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    /*Define vertex data */
    float vertices[] = {
        0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.0f, -0.5f, 0.0f
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    /* Initialize buffers */
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    /* Move vertex data into VBO and configure OpenGL vertex attributes */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);                

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), ((void*)0));
    glEnableVertexAttribArray(0);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT); 
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return(0);
}
