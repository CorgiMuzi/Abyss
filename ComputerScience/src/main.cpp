#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q42897 { int solution(vector<int> money); }
namespace pg::q150365 { string solution(int n, int m, int x, int y, int r, int c, int k); }
namespace pg::q42892 { vector<vector<int>> solution(vector<vector<int>> nodeinfo); }

int main()
{
    string expected = "{{7,4,6,9,1,8,5,2,3},{9,6,5,8,1,4,3,2,7}}";
    cout << "Expected: " << expected << "\nOutput: ";
    vector<vector<int>> ans = pg::q42892::solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
    cout << "{";
    for(const vector<int>& v : ans)
    {
        cout << "{";
        for(const int vv : v)
        {
            cout << vv << ",";
        }
        cout << "}";
    }
    cout << "}";
}
