#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q131703 { int solution(vector<vector<int>> begining, vector<vector<int>> target); }

int main()
{
    cout << pg::q131703::solution({{0, 1, 0, 0, 0}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}}, {{0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}});
} 