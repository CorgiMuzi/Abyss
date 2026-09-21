add_library(ComputerScience STATIC 
    src/ch01/towerOfHanoi.cpp
)

add_library(Abyss::CS ALIAS ComputerScience)

target_include_directories(ComputerScience PUBLIC include)

add_executable(AbyssCS src/main.cpp)
target_link_libraries(AbyssCS PRIVATE Abyss::CS)