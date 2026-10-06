#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q60062 { int solution(int n, vector<int> weak, vector<int> dist); }

int main()
{
    cout << pg::q60062::solution(12, {1, 3, 4, 9, 10}, {3, 5, 7});
}