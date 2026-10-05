#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q150367 { vector<int> solution(vector<long long> numbers); }

int main()
{
    const vector<int>& v = pg::q150367::solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    for(int i : v)
    {
        cout << i << " ";
    }
}
