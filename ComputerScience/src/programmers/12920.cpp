#include <algorithm>
#include <vector>

using namespace std;

namespace pg::q12920 {
int solution(int n, vector<int> cores) {
    if(n <= cores.size()) return n;

    int l = 0, r = n * (*min_element(cores.begin(), cores.end()));
    int m = 0, task = 0;
    while(l < r)
    {
        m = (l + r) / 2;
        task = 0;
        for(int core : cores)
        {
            task += (m / core) + 1;
            if(task >= n) break;
        }

        if(task >= n)
        {
            r = m;
        }else{
            l = m + 1;
        }
    }

    task = 0;
    int T = l;
    for(int core : cores)
    {
        task += ((T - 1) / core) + 1;
    }

    int remains = n - task;
    for(size_t i = 0; i < cores.size(); ++i)
    {
        if(T % cores[i] == 0) {
            remains--;
            if(remains == 0) return i + 1;
        }
    }

    return -1;
}
} // namespace pg::q12920