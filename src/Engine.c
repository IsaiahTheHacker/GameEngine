#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


int main(void)
{
    int WindowWidth = 600;
    int WindowHeight = 480;
    const char WindowName[] = "Hello World";
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WindowWidth, WindowHeight, WindowName, NULL, NULL);
    if (!window)
void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    gladLoadGL(glfwGetProcAddress);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
