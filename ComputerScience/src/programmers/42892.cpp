#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

/*
    - 트리를 구성하는 모든 노드의 x, y 좌표 값은 정수이다.
    - 모든 노드는 서로 다른 x값을 가진다.
    - 같은 레벨(level)에 있는 노드는 같은 y 좌표를 가진다.
    - 자식 노드의 y 값은 항상 부모 노드보다 작다.
    - 임의의 노드 V의 왼쪽 서브 트리(left subtree)에 있는 모든 노드의 x값은 V의 x값보다 작다.
    - 임의의 노드 V의 오른쪽 서브 트리(right subtree)에 있는 모든 노드의 x값은 V의 x값보다 크다.
 */
namespace pg::q42892
{
    struct Node
    {
        int x, y, z;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    void link(Node* parent, Node* child)
    {
        if(child->x < parent->x) {
            if(parent->left != nullptr) link(parent->left, child);
            else parent->left = child;
        }else
        {
            if(parent->right != nullptr) link(parent->right, child);
            else parent->right = child;
        }
    }

    void pre(Node* n, vector<int>& v)
    {
        if(n == nullptr) return;
        v.push_back(n->z);
        pre(n->left, v);
        pre(n->right, v);
    }

    void post(Node* n, vector<int>& v)
    {
        if(n == nullptr) return;
        post(n->left, v);
        post(n->right, v);
        v.push_back(n->z);
    }

    vector<vector<int>> solution(vector<vector<int>> nodeinfo)
    {
        vector<Node> nodes;
        for (int i = 0; i < nodeinfo.size(); ++i)
        {
            nodes.emplace_back(Node{nodeinfo[i][0], nodeinfo[i][1], i + 1});
        }

        sort(nodes.begin(), nodes.end(), [](const Node& lhs, const Node& rhs){
            if(lhs.y == rhs.y) return lhs.x < rhs.x;
            return lhs.y > rhs.y;
        });
        
        for(int i = 1; i < nodes.size(); ++i) link(&nodes[0], &nodes[i]);

        vector<vector<int>> answer(2);
        pre(&nodes[0], answer[0]);
        post(&nodes[0], answer[1]);
        return answer;
    }
}
