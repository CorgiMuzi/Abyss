#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q87694 { int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY); }

int main()
{
    cout << pg::q87694::solution({{2,2,5,5},{1,3,6,4},{3,1,4,6}}, 1, 4, 6, 3);
}