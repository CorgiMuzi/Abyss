#include <vector>

using namespace std;

namespace pg::q131703 {
size_t r_max, c_max;
vector<int> b_board;
vector<int> t_board;

size_t ToIdx(size_t r, size_t c) { return r * c_max + c; }

void Flip(int mask) {
    for (int r = 0; r < r_max; ++r) {
        if ((mask & (1 << r)) == 0)
            continue;
        for (size_t c = 0; c < c_max; ++c) {
            size_t idx = ToIdx(r, c);
            b_board[idx] ^= 1;
        }
    }
}

int solution(vector<vector<int>> begining, vector<vector<int>> target) {
    r_max = begining.size();
    c_max = begining[0].size();

    b_board.clear();
    t_board.clear();

    for (size_t r = 0; r < r_max; ++r) {
        for (size_t c = 0; c < c_max; ++c) {
            b_board.push_back(begining[r][c]);
            t_board.push_back(target[r][c]);
        }
    }

    size_t idx = 0;
    int min_flip = 1e9;
    for (int mask = 0; mask < (1 << r_max); ++mask) {
        bool valid = true;
        Flip(mask);
        int v_flip = 0;
        for (size_t c = 0; c < c_max; ++c) {
            idx = ToIdx(0, c);
            int result = b_board[idx] ^ t_board[idx];
            for(size_t r = 1; r < r_max; ++r)
            {
                idx = ToIdx(r, c);
                if(result ^ (b_board[idx] ^ t_board[idx]))
                {
                    valid = false;
                    break;
                }
            }

            if(valid){
                if(b_board[idx] ^ t_board[idx]) v_flip++;
            }else break;
        }

        Flip(mask);
        if(valid){
            int h_flip = 0;
            for(int r = 1; r < (1 << r_max); r <<= 1)
            {
                if(mask & r) h_flip++;
            }

            min_flip = min(min_flip, h_flip + v_flip);
        }
    }

    return min_flip == 1e9 ? -1 : min_flip;
}
} // namespace pg::q131703