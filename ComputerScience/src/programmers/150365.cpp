#include <string>
#include <vector>

using namespace std;

namespace pg::q150365
{
    string dir_s = "dlru";
    vector<pair<int, int>> dir_ii = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    string final_path = "";

    string pathfinding(int x, int y, int k, const int r, const int c, const int n, const int m, const string& path)
    {
        if(k == 0) {
            if(x != r || y != c) return "";
            return path;
        }

        for(int i = 0; i < 4; ++i)
        {
            int cx = x + dir_ii[i].first;
            if(cx < 1 || cx > n) continue;
            int cy = y + dir_ii[i].second;
            if(cy < 1 || cy > m) continue;
            int dist = abs(r - cx) + abs(c - cy);
            if(k < dist) continue;

            string result = pathfinding(cx, cy, k - 1, r, c, n, m, path + dir_s[i]);
            if(result.length() > 0) return result;
        }

        return "";
    }

    /// @brief 미로 탈출 경로 찾기
    /// 왼(l), 오(r), 위(u), 아래(d) 방향으로 이동 경로 표시, 사전순으로 경로 우선순위 \n
    /// 아래(d) > 왼(l) > 오(r) > 위(u)
    /// @param n 미로 높이
    /// @param m 미로 너비
    /// @param x 시작행
    /// @param y 시작열
    /// @param r 출구행
    /// @param c 출구열
    /// @param k 이동 가능 횟수
    /// @return 이동 경로를 표시한 문자열. 탈출 불가능한 경우 "impossible".
    string solution(int n, int m, int x, int y, int r, int c, int k)
    {
        int dist = abs(r - x) + abs(c - y);
        if(k < dist || (k - dist) % 2 != 0) return "impossible";

        string result = pathfinding(x, y, k, r, c, n, m, "");
        if(result.length() == 0) result = "impossible";
        return result;
    }
}
