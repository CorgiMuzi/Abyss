#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q42897 { int solution(vector<int> money); }
namespace pg::q150365 { string solution(int n, int m, int x, int y, int r, int c, int k); }
namespace pg::q42892 { vector<vector<int>> solution(vector<vector<int>> nodeinfo); }
namespace pg::q1832 { int solution(int m, int n, vector<vector<int>> city_map);}
namespace pg::q60061 { vector<vector<int>> solution(int n, vector<vector<int>> build_frame); }

int main()
{
    vector<vector<int>> bp = pg::q60061::solution(5, {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}});

    for(int i = 0; i < bp.size(); ++i)
    {
        for(int j = 0; j < bp[i].size(); ++j)
        {
            cout << bp[i][j] << " ";
        }
        cout << endl;
    }
}
