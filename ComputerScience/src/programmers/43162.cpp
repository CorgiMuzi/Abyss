#include <queue>
#include <vector>

using namespace std;

namespace pg::q43162 {
int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    queue<int> q;

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i])
            continue;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt = 0; nxt < n; ++nxt) {
                if (computers[cur][nxt] == 0)
                    continue;
                if (visited[nxt])
                    continue;

                q.push(nxt);
                visited[nxt] = true;
            }
        }
        answer++;
    }

    return answer;
}
} // namespace pg::q43162