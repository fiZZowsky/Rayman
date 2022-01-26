
# ustawienie nazwy projektu
project(Rayman1)

# dodanie pliku wykonywalnego
add_executable(Rayman1 Game.vcxproj)

# ustawienie standardu C++
set_target_properties(Rayman1 PROPERTIES LINKER_LANGUAGE CXX)