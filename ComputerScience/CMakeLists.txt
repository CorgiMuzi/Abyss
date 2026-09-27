add_library(ComputerScience STATIC 
    src/programmers/42892.cpp
    src/programmers/42897.cpp
    src/programmers/81303.cpp
    src/programmers/150365.cpp
    src/ch01/towerOfHanoi.cpp
    src/programmers/1832.cpp
)

add_library(Abyss::CS ALIAS ComputerScience)

target_include_directories(ComputerScience PUBLIC include)

add_executable(AbyssCS src/main.cpp)
target_link_libraries(AbyssCS PRIVATE Abyss::CS)