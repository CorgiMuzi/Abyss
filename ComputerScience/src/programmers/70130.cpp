#include <algorithm>
#include <vector>

using namespace std;

namespace pg::q70130 {
using pii = pair<int, int>;
int solution(vector<int> a) {
    vector<pii> b;
    b.reserve(a.size() + 1);
    for (int i = 0; i <= a.size(); ++i)
        b.push_back(make_pair(0, i));
    for (int aa : a)
        b[aa].first++;
    sort(b.begin(), b.end(), [](const pii& lhs, const pii& rhs) {
        return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first > rhs.first;
    });

    int answer = 0;
    for (const pii& bb : b) {
        if (2 * bb.first <= answer)
            break;
        size_t idx = 0;
        int p = 0;
        while (idx + 1 < a.size()) {
            if ((a[idx] == bb.second || a[idx + 1] == bb.second) && a[idx] != a[idx + 1]) {
                p++;
                idx += 2;
            } else {
                idx++;
            }
        }

        answer = max(answer, 2 * p);
    }

    return answer;
}
} // namespace pg::q70130