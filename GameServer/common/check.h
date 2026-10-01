#pragma once
#include <iostream>
#include <exception>

inline int g_failures = 0;

#define CHECK(cond) do\
{\
if(!(cond)) {\
    std::cerr << "[" << __FILE__ << "](" << __LINE__ << ") " << #cond << "\n";\
    g_failures++;\
}\
}while(0)

#define RUN_TEST(fn) do\
{\
    int failed = g_failures;\
    try{\
        fn();\
        if(g_failures > failed) std::cerr << "[FAIL] " << #fn << "\n";\
        else std::cerr << "[ OK ] " << #fn << "\n";\
    }catch(const std::exception& e)\
    {\
        g_failures++;\
        std::cerr << "[FAIL] " << #fn << "(execption: " << e.what() << "(\n";\
    }\
}while(0)

inline int TestResult()
{
    std::cerr << g_failures << " check(s) failed.\n";
    return g_failures == 0 ? 0 : 1;
}