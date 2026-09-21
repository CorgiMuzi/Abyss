#include <iostream>
#include <string>
#include <format>
#include <chrono>
#include <vector>
#include <thread>
#include <memory>

using namespace std;

namespace ch01::prime_number_errorneous
{
    const int MaxCount = 3000000;
    const int ThreadCount = 4;

    bool IsPrimeNumber(int number)
    {
        if (number == 1)
            return false;
        if (number == 2 || number == 3)
            return true;

        for (int i = 2; i * i <= number; ++i)
        {
            if (number % i == 0)
                return false;
        }

        return true;
    }

    void PrintNumbers(const vector<int> &primes)
    {
        for (int v : primes)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    int ExecMain()
    {
        int num = 1;

        vector<int> primes;
        vector<shared_ptr<thread>> threads;

        auto t0 = chrono::steady_clock::now();

        for (int i = 0; i < ThreadCount; ++i)
        {
            shared_ptr<thread> th(new thread([&]()
                                                 {
                while(true){
                    int n;
                    n = num;

                    num++;

                    if(n >= MaxCount) break;

                    if(IsPrimeNumber(n)) primes.push_back(n);
                } }));

            threads.push_back(th);
        }

        for (auto th : threads)
        {
            th->join();
        }

        auto t1 = chrono::steady_clock::now();

        auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
        cout << string(format("Took {}ms.", duration));

        return 0;
    }
}