#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q42897 { int solution(vector<int> money); }

int main()
{
    vector<int> money = {2,3,2};
    int expected = 4;

    cout << "Expected: " << expected << "\nOutput: " << pg::q42897::solution(money) << endl;
}
