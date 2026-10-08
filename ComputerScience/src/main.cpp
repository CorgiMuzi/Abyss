#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q131129 { vector<int> solution(int target); }

int main()
{
    int input = 58;
    vector<int> v = pg::q131129::solution(input);
    cout << input << ": {" << v[0] << ", " << v[1] <<"}";
}