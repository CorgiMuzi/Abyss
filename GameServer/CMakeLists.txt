add_library(GameServer STATIC
    src/ch01/prime_number.cpp
    src/ch01/prime_number_errorneous.cpp
    src/ch01/prime_number_multithreaded.cpp
    src/ch01/deadlock-example.cpp
)

add_library(Abyss::Server ALIAS GameServer)

target_include_directories(GameServer PUBLIC include)

add_executable(AbyssServer src/main.cpp)
target_link_libraries(AbyssServer PRIVATE Abyss::Server)