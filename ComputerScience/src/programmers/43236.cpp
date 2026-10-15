#include <vector>
#include <algorithm>

using namespace std;

namespace pg::q43236 {
int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int l = 1, r = distance;
    int answer = 0;
    while(l <= r)
    {
        int m = (l + r) / 2;

        int cnt = 0, prev = 0;
        for(int rock : rocks)
        {
            if(rock - prev < m) cnt++;
            else prev = rock;
        }

        if(cnt <= n){
            answer = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }

    return answer;
}
} // namespace pg::q43236