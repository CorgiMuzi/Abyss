#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q42891 { int solution(vector<int> food_times, long long k); }

int main()
{
    cout << pg::q42891::solution({3, 1, 2}, 5);
}
