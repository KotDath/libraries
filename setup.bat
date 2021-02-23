if not exist build mkdir build
cd build
if not exist build mkdir Dynamic_explicit
cd Dynamic_explicit
cmake .\..\..\Dynamic_explicit
cmake --build .
cd .\..
cmake ..
cmake --build .
move .\Dynamic_Implicit\Debug\Dimplicit.dll .\Debug
start .\Debug\libraries.exe