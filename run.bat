cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\kursiokai.txt Debug\kursiokai.txt
cd Debug\
Work_with_Files.exe
pause