#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q77886 { vector<string> solution(vector<string> s); }

int main()
{
    const vector<string>& answer = pg::q77886::solution({"10101010110","00000011100011111","01110"});
    for(int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }
    cout <<endl;
}
