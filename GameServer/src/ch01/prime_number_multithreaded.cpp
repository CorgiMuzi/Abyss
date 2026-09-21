#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <memory>
#include <mutex>
#include <format>

using namespace std;

namespace ch01::prime_number_multithreaded
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
        recursive_mutex num_mutex;
        vector<int> primes;
        recursive_mutex primes_mutex;
        vector<shared_ptr<thread>> threads;

        auto t0 = chrono::steady_clock::now();
        for (int i = 0; i < ThreadCount; ++i)
        {
            shared_ptr<thread> th(new thread([&]()
                                             {
                while(true)
                {
                    int n;
                    {
                        lock_guard<recursive_mutex> num_lock(num_mutex);
                        n = num;
                        num++;
                    }
                    
                    if(n >= MaxCount) break;

                    if(IsPrimeNumber(n)) 
                    {
                        lock_guard<recursive_mutex> primes_lock(primes_mutex);
                        primes.push_back(n);
                    }
                } }));

            threads.push_back(th);
        }

        for(auto th : threads) th->join();
        
        auto t1 = chrono::steady_clock::now();

        auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();

        cout << string(format("Took {}ms.", duration));

        return 0;
    }
}