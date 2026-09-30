#include <string>
#include <vector>

using namespace std;

namespace pg::q77886 {
vector<string> solution(vector<string> s) {
    for (string& str : s) {
        if (str.length() <= 2)
            continue;

        int token_cnt = 0;
        string without_token;

        for (int i = 0; i < str.length(); ++i) {
            without_token += str[i];
            int len = without_token.length();
            if (len >= 3 && without_token.compare(len - 3, 3, "110") == 0) {
                without_token.resize(len - 3);
                token_cnt++;
            }
        }

        size_t pos = without_token.rfind('0');
        pos = (pos == string::npos) ? 0 : pos + 1;

        string new_str;
        new_str.reserve(str.length());
        new_str.append(without_token, 0, pos);
        for(int i = 0; i < token_cnt; ++i) new_str += "110";
        new_str.append(without_token, pos, string::npos);
        str = move(new_str);
    }

    return s;
}
} // namespace pg::q77886
