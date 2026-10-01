#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q64063 { vector<long long> solution(long long k, vector<long long> room_number); }

int main()
{
    const vector<long long>& answer = pg::q64063::solution(10, {1, 3, 4, 1, 3, 1});

    for(long long ll : answer) cout << ll << " ";
    cout << endl;
}
