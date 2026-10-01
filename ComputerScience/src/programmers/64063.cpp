#include <unordered_map>
#include <vector>

using namespace std;

namespace pg::q64063 {
vector<long long> solution(long long k, vector<long long> room_number) {
    unordered_map<long long, long long> rooms;
    rooms.reserve(room_number.size());

    vector<long long> answer;
    answer.reserve(room_number.size());

    vector<long long> chain;
    for (const long long want : room_number) {
        long long room = want;
        auto it = rooms.find(room);

        chain.clear();
        while (it != rooms.end()) {
            chain.push_back(room);
            room = it->second;
            it = rooms.find(room);
        }

        rooms.emplace(room, room + 1);
        answer.push_back(room);

        for (const long long c : chain)
            rooms[c] = room + 1;
    }

    return answer;
}
} // namespace pg::q64063