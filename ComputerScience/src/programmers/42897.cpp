#include <vector>
#include <string>

using namespace std;

namespace pg::q42897
{
    int solution(vector<int> money)
    {
        vector<int> from0(money.size(), 0), from1(money.size(), 0);
        
        from0[0] = money[0];
        from0[1] = max(from0[0], money[1]);

        from1[0] = 0;
        from1[1] = money[1];

        for(int i = 2; i < money.size(); ++i)
        {
            if(i + 1 < money.size()) from0[i] = max(from0[i - 1], from0[i - 2] + money[i]);
            if(i < money.size()) from1[i] = max(from1[i - 1], from1[i - 2] + money[i]);
        }

        int answer = max(from0[money.size() - 2], from1[money.size() - 1]);
        return answer;
    }
}