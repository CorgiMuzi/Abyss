#include <string>
#include <vector>

using namespace std;

namespace pg::q17685 {
struct Node
{
    Node* child[26] = {};
    int count = 0;
};

int solution(vector<string> words) {
    Node* root = new Node();

    for(const string& word : words)
    {
        Node* n = root;
        for(const char c : word)
        {
            int ci = c - 'a';
            if(!n->child[ci]) n->child[ci] = new Node();
            n = n->child[ci];
            n->count++;
        }
    }

    int answer = 0;
    for(const string& word : words)
    {
        Node* n = root;

        int len = word.size();
        for(int i = 0; i < word.size(); ++i)
        {
            n = n->child[word[i] - 'a'];
            if(n->count == 1){
                len = i + 1;
                break;
            }
        }
        answer += len;
    }

    return answer;
}
} // namespace pg::q17685