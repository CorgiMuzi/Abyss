#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace pg::q60062 {
int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    sort(weak.begin(), weak.end());

    vector<int> flatten{weak.begin(), weak.end()};
    for(int i = 0; i < weak.size(); ++i) flatten.push_back(weak[i] + n);

    int answer = 1e9;
    do
    {
        for(int start = 0; start < weak.size(); ++start)
        {
            int fr = 0;
            int last = flatten[start] + dist[fr];

            for(int j = start; j < start + weak.size(); ++j)
            {
                if(flatten[j] > last){
                    fr++;
                    if(fr >= dist.size()) break;
                    last = flatten[j] + dist[fr];
                }
            }

            answer = min(answer, fr + 1);
        }
    }while(next_permutation(dist.begin(), dist.end()));

    return answer > dist.size() ? -1 : answer;
}
} // namespace pg::q60062