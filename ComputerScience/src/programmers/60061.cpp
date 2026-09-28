#include <string>
#include <vector>

using namespace std;

namespace pg::q60061
{
    vector<vector<vector<bool>>> build;

    enum Material
    {
        Column = 0,
        Floor,
        Blank
    };

    bool CanPlaceColumn(int x, int y)
    {
        if(y == 0) return true;
        if(build[x][y][Floor] || build[x][y - 1][Column]) return true;
        if(x > 0 && build[x - 1][y][Floor]) return true;

        return false;
    }

    bool CanPlaceFloor(int x, int y)
    {
        if(build[x][y - 1][Column] || build[x + 1][y - 1][Column]) return true;
        if((x > 0 && build[x - 1][y][Floor]) && (x < build.size() - 1 && build[x + 1][y][Floor])) return true;

        return false;
    }

    bool CanPlace(int x, int y, Material mat)
    {
        switch(mat)
        {
            case Column:
                return CanPlaceColumn(x, y);
            case Floor:
                return CanPlaceFloor(x, y);
            default:
                return false;
        }
    }

    bool IsValid()
    {
        int n = build.size();
        for(int x = 0; x < n; ++x)
        {
            for(int y = 0; y < n; ++y)
            {
                if(build[x][y][Column] && !CanPlaceColumn(x, y)) return false;
                if(build[x][y][Floor] && !CanPlaceFloor(x, y)) return false;
            }
        }

        return true;
    }

    vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
    {
        build = vector<vector<vector<bool>>>(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false)));

        for(const vector<int>& bp : build_frame)
        {
            int x = bp[0], y = bp[1];
            Material mat = (Material)bp[2];
            bool shouldPlace = bp[3];

            if(shouldPlace)
            {
                build[x][y][mat] = CanPlace(x, y, mat);
            }else
            {
                build[x][y][mat] = 0;
                build[x][y][mat] = !IsValid();
            }
        }

        vector<vector<int>> answer;
        for(int x = 0; x <= n; ++x)
        {
            for(int y = 0; y <= n; ++y)
            {
                if(build[x][y][Column]) answer.emplace_back(vector<int>{x, y, Column});
                if(build[x][y][Floor]) answer.emplace_back(vector<int>{x, y, Floor});
            }
        }

        return answer;
    }
}