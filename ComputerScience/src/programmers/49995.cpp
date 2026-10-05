#include <vector>

using namespace std;

namespace pg::q49995 {
int solution(vector<int> cookie) {
    int answer = 0;

    for (int m = 0; m < cookie.size() - 1; ++m) {
        int l = m, r = m + 1;
        int lsum = cookie[l], rsum = cookie[r];
        while (l >= 0 && r < cookie.size()) {
            if (lsum == rsum)
                answer = max(answer, lsum);

            if (lsum <= rsum) {
                --l;
                if (l >= 0)
                    lsum += cookie[l];
            } else {
                ++r;
                if (r < cookie.size())
                    rsum += cookie[r];
            }
        }
    }

    return answer;
}
} // namespace pg::q49995