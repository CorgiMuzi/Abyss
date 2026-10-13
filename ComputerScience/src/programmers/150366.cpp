#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q150366 {
constexpr int N = 51;
int parent[N * N];
string content[N * N];

int ToIndex(int r, int c) { return r * N + c; }

int GetParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = GetParent(parent[x]);
}

void Update(int r, int c, const string& value) { content[GetParent(ToIndex(r, c))] = value; }

void Update(const string& oldContent, const string& newContent) {
    for (int r = 1; r <= 50; ++r) {
        for (int c = 1; c <= 50; ++c) {
            int i = ToIndex(r, c);
            if (content[i] == oldContent)
                content[i] = newContent;
        }
    }
}

void Merge(int r1, int c1, int r2, int c2) {
    int p1 = GetParent(ToIndex(r1, c1));
    int p2 = GetParent(ToIndex(r2, c2));
    if (p1 == p2)
        return;
    if (content[p1].empty()) {
        parent[p1] = p2;
    } else {
        parent[p2] = p1;
        content[p2] = "";
    }
}

void Unmerge(int r, int c) {
    int p = GetParent(ToIndex(r, c));
    string value = content[p];

    vector<int> cells;
    for (int x = 1; x <= 50; ++x) {
        for (int y = 1; y <= 50; ++y) {
            if (GetParent(ToIndex(x, y)) == p)
                cells.push_back(ToIndex(x, y));
        }
    }
    for (int cell : cells) {
        parent[cell] = cell;
        content[cell] = "";
    }
    content[ToIndex(r, c)] = value;
}

vector<string> solution(vector<string> commands) {
    for (int i = 0; i < N * N; ++i) {
        parent[i] = i;
        content[i] = "";
    }

    stringstream ss;
    string token;
    vector<string> tokens;
    tokens.reserve(5);

    vector<string> answer;
    for (const string& cmd : commands) {
        ss.clear();
        ss.str(cmd);

        tokens.clear();

        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }

        string cmdType = tokens[0];
        if (cmdType == "UPDATE") {
            if (tokens.size() == 4)
                Update(stoi(tokens[1]), stoi(tokens[2]), tokens[3]);
            else
                Update(tokens[1], tokens[2]);
        } else if (cmdType == "MERGE") {
            Merge(stoi(tokens[1]), stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]));
        } else if (cmdType == "UNMERGE") {
            Unmerge(stoi(tokens[1]), stoi(tokens[2]));
        } else if (cmdType == "PRINT") {
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            const string& o = content[GetParent(ToIndex(r, c))];
            if (o.empty())
                answer.push_back("EMPTY");
            else
                answer.push_back(o);
        }
    }

    return answer;
}
} // namespace pg::q150366