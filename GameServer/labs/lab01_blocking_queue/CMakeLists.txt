add_executable(lab01_test test.cpp)
target_link_libraries(lab01_test PRIVATE Abyss::Common)
add_test(NAME lab01 COMMAND lab01_test)