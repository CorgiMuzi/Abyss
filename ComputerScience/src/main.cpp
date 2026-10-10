#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace pg::q118669 { vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits); }

int main()
{
    vector<int> v = pg::q118669::solution(6, {{1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1}}, {1, 3}, {5});
    cout << v[0] << ", " << v[1] << endl;
}