#include <cmath>
#include <queue>
#include <vector>

using namespace std;

namespace pg::q87694 {
vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Comparer
{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const
    {
        if(lhs[0] == rhs[0]) 
        {
            return lhs[1] == rhs[1] ? lhs[2] > rhs[2] : lhs[1] > rhs[1];
        }
        return lhs[0] > rhs[0];
    }
};

int Manhattan(int cx, int cy, int ix, int iy)
{
    return abs(ix - cx) + abs(iy - cy);
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<bool>> grid(102, vector<bool>(102, false));

    for (const vector<int>& rect : rectangle) {
        int xl = 2 * rect[0], yl = 2 * rect[1], xr = 2 * rect[2], yr = 2 * rect[3];
        for (int x = xl; x <= xr; ++x) {
            for (int y = yl; y <= yr; ++y) {
                grid[x][y] = true;
            }
        }
    }

    for (const vector<int>& rect : rectangle) {
        int xl = 2 * rect[0], yl = 2 * rect[1], xr = 2 * rect[2], yr = 2 * rect[3];
        for (int x = xl + 1; x < xr; ++x) {
            for (int y = yl + 1; y < yr; ++y) {
                grid[x][y] = false;
            }
        }
    }

    int sx = 2 * characterX, sy = 2 * characterY;
    int ix = 2 * itemX, iy = 2 * itemY;

    vector<vector<bool>> visited(102, vector<bool>(102, false));
    vector<vector<int>> g(102, vector<int>(102, (int)1e9));
    g[sx][sy] = 0;

    priority_queue<vector<int>, vector<vector<int>>, Comparer> pq;
    pq.push(vector<int>{Manhattan(sx, sy, ix, iy), sx, sy});

    while(!pq.empty())
    {
        const vector<int> cur = pq.top();
        pq.pop();

        int cx = cur[1], cy = cur[2];
        if(visited[cx][cy]) continue;
        visited[cx][cy] = true;

        if(cx == ix && cy == iy) return g[cx][cy] / 2;

        for(const pair<int, int>& dir : dirs)
        {
            int nx = cx + dir.first, ny = cy + dir.second;
            if(nx < 0 || ny < 0 || nx > 101 || ny > 101) continue;
            if(visited[nx][ny] || !grid[nx][ny]) continue;

            int ng = g[cx][cy] + 1;
            if(ng >= g[nx][ny]) continue;
            g[nx][ny] = ng;
            int nf = ng + Manhattan(nx, ny, ix, iy);
            pq.push(vector<int>{nf, nx, ny});
        }
    }

    return -1;
}
} // namespace pg::q87694