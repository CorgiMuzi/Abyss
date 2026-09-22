#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q81303 { string solution(int n, int k, vector<string> cmd); }

int main()
{
    int n = 8;
    int k = 2;
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};

    cout << pg::q81303::solution(n, k, cmd);

    return 0;
}
