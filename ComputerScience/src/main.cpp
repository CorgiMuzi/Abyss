#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q12942 { int solution(vector<vector<int>> matrix_sizes); }

int main()
{
    cout << pg::q12942::solution({{5,3},{3,10},{10,6}});
} 