/**
 * U X : 현재 선택된 행에서 X칸 위에 있는 행 선택
 * D X : 현재 선택된 행에서 X칸 아래 ..
 * C : 현재 행 삭제, 아래 행 선택. 마지막 행인 경우 윗 행
 * Z : 복구(선택된 행 변동 X)
 *
 * n : 행 개수
 * k : 선택된 행 위치
 * cmd : 명령어들
 * O : 최종적으로 삭제 안된 행
 * X : 최종적으로 삭제된 행
 */
#include <vector>
#include <string>

using namespace std;

namespace pg::q81303
{
    /// @brief 2021 카카오 채용연계형 인턴십 > 표 편집
    /// @param n 행 개수
    /// @param k 처음 선택된 행 위치
    /// @param cmd 명령어 모음
    /// @return 삭제 안된 행은 O, 삭제된 행은 X로 순차적으로 표시된 문자열
    string solution(int n, int k, vector<string> cmd)
    {
        vector<int> prv(n), nxt(n);
        for(int i = 0; i < n; ++i) {
            prv[i] = i - 1;
            nxt[i] = (i + 1 < n) ? i + 1 : -1;
        }

        string answer(n, 'O');
        vector<int> undo;
        undo.reserve(cmd.size());
        int cur = k;
        
        for (const string &msg : cmd)
        {
            const char c = msg[0];
            if (c == 'U' || c == 'D')
            {
                int m = 0;
                for(int i = 2; i < msg.size(); ++i) m = m * 10 + (msg[i] - '0');
                if(c == 'U') while(m--) cur = prv[cur];
                else while(m--) cur = nxt[cur];
            }
            else if (c == 'C')
            {
                answer[cur] = 'X';
                undo.push_back(cur);
                if(prv[cur] != -1) nxt[prv[cur]] = nxt[cur];
                if(nxt[cur] != -1) prv[nxt[cur]] = prv[cur];
                cur = (nxt[cur] != -1) ? nxt[cur] : prv[cur];
            }
            else if (c == 'Z')
            {
                const int u = undo.back();
                undo.pop_back();
                answer[u] = 'O';
                if(prv[u] != -1) nxt[prv[u]] = u;
                if(nxt[u] != -1) prv[nxt[u]] = u;
            }
        }

        return answer;
    }
}
