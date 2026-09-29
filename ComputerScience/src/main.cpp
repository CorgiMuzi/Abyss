#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q72414 { string solution(string play_time, string adv_time, vector<string> logs); }

int main()
{
    string ans = pg::q72414::solution("02:03:55", "00:14:15", {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"});

    cout << "01:30:59\n" << ans << endl;
}
