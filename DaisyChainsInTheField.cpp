#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

queue<int> nextInLine;
vector<int> adj[300];
bool visited[300];
set<int> l;
int main()
{
    int n, m, one, two, cur;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        l.insert(i + 1);
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    nextInLine.push(1);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        l.erase(cur);
        for(int i = 0; i < adj[cur].size(); i ++)
            nextInLine.push(adj[cur][i]);
    }
    for(set<int>::iterator it = l.begin(); it != l.end(); ++ it)
        cout << *it << "\n";
    if(l.empty()) cout << 0 << "\n";
}
