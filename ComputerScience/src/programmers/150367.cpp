#include <string>
#include <vector>

using namespace std;

namespace pg::q150367 {
string binary = "";

bool IsValid(int l, int r) {
    if (l == r)
        return true;
    int m = (l + r) / 2;
    if (binary[m] == '0') {
        for (int i = l; i <= r; ++i)
            if (binary[i] == '1')
                return false;
    }

    return IsValid(l, m - 1) && IsValid(m + 1, r);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    answer.reserve(numbers.size());

    for (long long number : numbers) {
        binary = "";
        while (number > 0) {
            int bit = number % 2;
            binary = char(bit + '0') + binary;
            number /= 2;
        }

        int k = 1;
        while (k < binary.size())
            k = 2 * k + 1;

        binary = string(k - binary.size(), '0') + binary;
        answer.push_back(IsValid(0, binary.size() - 1));
    }

    return answer;
}
} // namespace pg::q150367
