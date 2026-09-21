#include <vector>
#include <iostream>
#include <chrono>
#include <string>
#include <format>

using namespace std;
const int MaxCount = 15000;

namespace ch01
{
    bool IsPrimeNumber(int number)
    {
        if (number == 1)
            return false;
        if (number == 2 || number == 3)
            return true;

        for (int i = 2; i * i <= number; ++i)
        {
            if ((number % i) == 0)
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
        vector<int> primes;

        auto t0 = chrono::system_clock::now();

        for (int i = 1; i <= MaxCount; ++i)
        {
            if (IsPrimeNumber(i))
                primes.push_back(i);
        }

        auto t1 = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
        const string msg{format("Took: {}ms", duration)};
        cout << msg << endl;

        return 0;
    }
}
