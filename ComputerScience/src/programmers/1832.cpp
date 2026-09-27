#include <vector>

using namespace std;

namespace pg::q1832
{
    int MOD = 20170805;

    int solution(int m, int n, vector<vector<int>> city_map)
    {
        vector<vector<int>> path(m, vector<int>(n, 0));
        path[0][0] = 1;

        for(int r = 0; r < m; ++r)
        {
            for(int c = 0; c < n; ++c)
            {
                path[r][c] %= MOD;

                if(city_map[r][c] > 0){
                    if(city_map[r][c] == 1) path[r][c] = 0;
                    continue;
                }
                
                int rr = r + 1;
                while(rr < m && city_map[rr][c] == 2) { rr++; }
                if(rr < m) path[rr][c] += path[r][c];
                int cc = c + 1;
                while(cc < n && city_map[r][cc] == 2) { cc++; }
                if(cc < n) path[r][cc] += path[r][c];
            }
        }

        int answer = path[m - 1][n - 1] % MOD;
        return answer;
    }
}