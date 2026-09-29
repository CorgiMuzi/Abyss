#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <format>

using namespace std;

namespace pg::q72414 {
int stos(const string& s_time) {
    stringstream ss(s_time);
    string token;
    int seconds = 0;
    while (getline(ss, token, ':')) {
        seconds *= 60;
        seconds += stoi(token);
    }
    return seconds;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int pt_sec = stos(play_time);
    int ad_sec = stos(adv_time);

    vector<vector<int>> logs_sec(logs.size(), vector<int>(2, 0));
    for (int i = 0; i < logs.size(); ++i) {
        logs_sec[i][0] = stos(logs[i].substr(0, 8));
        logs_sec[i][1] = stos(logs[i].substr(9, 8));
    }

    vector<int> viewer(pt_sec + 1, 0);
    for(const vector<int>& sec : logs_sec)
    {
        viewer[sec[0]]++;
        viewer[sec[1]]--;
    }

    for(int i = 1; i <= pt_sec; ++i) viewer[i] += viewer[i - 1];

    vector<long long> elapsed(pt_sec + 1, 0);

    for(int i = 1; i <= pt_sec; ++i)
    {
        elapsed[i] = elapsed[i - 1] + viewer[i - 1];
    }

    long long best = -1;
    int start = 0;
    for(int i = 0; i + ad_sec <= pt_sec; ++i)
    {
        long long sum = elapsed[i + ad_sec] - elapsed[i];
        if(sum > best) 
        {
            best = sum;
            start = i;
        }
    }

    string answer = std::format("{:02d}:{:02d}:{:02d}", start / 3600, start / 60 % 60, start % 60);
    return answer;
}
} // namespace pg::q72414
