#include <functional>
#include <queue>
#include <vector>

using namespace std;

namespace pg::q42891 {
bool cp(const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.second > rhs.second; }

int solution(vector<int> food_times, long long k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fin;

    for (int i = 0; i < food_times.size(); ++i) {
        fin.push(make_pair(food_times[i], i));
    }

    int last_time = 0;
    while (k > 0 && !fin.empty()) {
        long long total_time = (fin.top().first - last_time) * fin.size();
        if (k >= total_time) {
            k -= total_time;
            last_time = fin.top().first;
            while (!fin.empty() && last_time == fin.top().first)
                fin.pop();
        } else {
            break;
        }
    }

    if (fin.empty())
        return -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   function<bool(const pair<int, int>&, const pair<int, int>&)>>
        last(cp);
    while (!fin.empty()) {
        last.push(fin.top());
        fin.pop();
    }

    long long last_food = k % last.size();
    for (int i = 0; i < last_food; ++i)
        last.pop();
    return last.top().second + 1;
}
} // namespace pg::q42891