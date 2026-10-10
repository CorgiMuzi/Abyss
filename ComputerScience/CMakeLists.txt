add_library(ComputerScience STATIC 
    src/programmers/1832.cpp
    src/programmers/17685.cpp
    src/programmers/42891.cpp
    src/programmers/42892.cpp
    src/programmers/42897.cpp
    src/programmers/43162.cpp
    src/programmers/49995.cpp
    src/programmers/60061.cpp
    src/programmers/60062.cpp
    src/programmers/64063.cpp
    src/programmers/70130.cpp
    src/programmers/72414.cpp
    src/programmers/77886.cpp
    src/programmers/81303.cpp
    src/programmers/118669.cpp
    src/programmers/131129.cpp
    src/programmers/150365.cpp
    src/programmers/150367.cpp
    src/ch01/towerOfHanoi.cpp
)

add_library(Abyss::CS ALIAS ComputerScience)

target_include_directories(ComputerScience PUBLIC include)

add_executable(AbyssCS src/main.cpp)
target_link_libraries(AbyssCS PRIVATE Abyss::CS)