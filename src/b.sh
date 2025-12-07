cd ..
cd build

if [ "$1" == "-d" ]; then
    cmake -DCMAKE_BUILD_TYPE=Debug ../src
    make
    gdb ./Engine
else
    cmake ../src
    make
    ./Engine
fi

cd ..
cd src
