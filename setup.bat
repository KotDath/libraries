if not exist build mkdir build
cd build
cmake ..
cmake --build .
copy .\Dynamic_lib\Debug\Dynamic.dll .\Debug
start .\Debug\libraries.exe