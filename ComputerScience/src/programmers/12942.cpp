#include <vector>

using namespace std;

namespace pg::q12942 {
int solution(vector<vector<int>> matrix_sizes) {
    vector<vector<int>> dp(matrix_sizes.size(), vector<int>(matrix_sizes.size(), 1e9));
    for (size_t i = 0; i < matrix_sizes.size(); ++i) {
        dp[i][i] = 0;
    }

    for (int span = 1; span < matrix_sizes.size(); ++span) {
        for (size_t l = 0; l + span < matrix_sizes.size(); ++l) {
            for (size_t m = l; m < l + span; ++m) {
                dp[l][l + span] = min(dp[l][l + span], dp[l][m] + dp[m + 1][l + span] +
                                                           matrix_sizes[l][0] * matrix_sizes[m][1] *
                                                               matrix_sizes[l + span][1]);
            }
        }
    }

    return dp[0][matrix_sizes.size() - 1];
}
} // namespace pg::q12942