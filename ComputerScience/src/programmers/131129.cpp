#include <vector>

using namespace std;

namespace pg::q131129 {
vector<int> Compare(vector<int> v1, vector<int> v2) {
    if (v1[0] == v2[0])
        return v1[1] > v2[1] ? v1 : v2;
    return v1[0] < v2[0] ? v1 : v2;
}

vector<int> solution(int target) {
    vector<vector<int>> throws;
    for (int i = 1; i <= 20; ++i) {
        throws.emplace_back(vector<int>{i, 1});
        throws.emplace_back(vector<int>{i * 2, 0});
        throws.emplace_back(vector<int>{i * 3, 0});
    }
    throws.emplace_back(vector<int>{50, 1});

    vector<vector<int>> dp(target + 1, vector<int>{(int)1e9, 0});
    dp[0] = {0, 0};

    for (int i = 1; i <= target; ++i) {
        for (const vector<int>& t : throws) {
            if (t[0] > i)
                continue;
            dp[i] = Compare(dp[i], vector<int>{dp[i - t[0]][0] + 1, dp[i - t[0]][1] + t[1]});
        }
    }

    return dp[target];
}
} // namespace pg::q131129
