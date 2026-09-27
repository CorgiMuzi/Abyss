#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q42897 { int solution(vector<int> money); }
namespace pg::q150365 { string solution(int n, int m, int x, int y, int r, int c, int k); }
namespace pg::q42892 { vector<vector<int>> solution(vector<vector<int>> nodeinfo); }
namespace pg::q1832 { int solution(int m, int n, vector<vector<int>> city_map);}

int main()
{
    cout << pg::q1832::solution(3, 3, {{0, 0, 1}, {0, 0, 2}, {1, 2, 0}}) << endl;
    // cout << pg::q1832::solution(3,6, {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}) << endl;
}
