#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q42897 { int solution(vector<int> money); }
namespace pg::q150365 { string solution(int n, int m, int x, int y, int r, int c, int k); }

int main()
{
    string expected = "impossible";

    cout << "Expected: " << expected << "\nOutput: " << pg::q150365::solution(3, 3, 1, 2, 3, 3, 4) << endl;
}
