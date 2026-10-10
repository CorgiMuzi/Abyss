#include <queue>
#include <vector>

using namespace std;

namespace pg::q118669 {
using pii = pair<int, int>;
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int g : gates) pq.push(make_pair(0, g));

    vector<bool> isSummit(n + 1, false);
    for(int s : summits) isSummit[s] = true;

    vector<vector<pii>> edges(n + 1);
    for(const vector<int>& v : paths)
    {
        edges[v[0]].push_back(make_pair(v[2], v[1]));
        edges[v[1]].push_back(make_pair(v[2], v[0]));
    }

    vector<int> intensity(n + 1, -1);
    while(!pq.empty())
    {
        const pii cur = pq.top();
        pq.pop();

        if(intensity[cur.second] >= 0) continue;
        intensity[cur.second] = cur.first;
        if(isSummit[cur.second]) continue;

        for(const pii& nxt : edges[cur.second])
        {
            if(intensity[nxt.second] >= 0) continue;
            pq.push(make_pair(max(intensity[cur.second], nxt.first), nxt.second));
        }
    }

    vector<int> answer{(int)1e9, (int)1e9};
    for(int s : summits)
    {
        if(intensity[s] < 0) continue;
        if(intensity[s] < answer[1])
        {
            answer[0] = s;
            answer[1] = intensity[s];
        }else if(intensity[s] == answer[1]){
            answer[0] = min(answer[0], s);
        }
    }

    return answer;
}
} // namespace pg::q118669