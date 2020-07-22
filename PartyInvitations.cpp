#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
using namespace std;

set<int> parties[125000];
map<int, vector<int>> adj;
map<int, bool> visited;
queue<int> nextInLine;
int main()
{
    int n, g, cur, size, ans = 0;
    cin >> n >> g;
    for(int i = 0; i < g; i ++)
    {
        cin >> size;
        for(int j = 0; j < size; j ++)
        {
            cin >> cur;
            parties[i].insert(cur);
            adj[cur].push_back(i);
        }
    }
    nextInLine.push(1);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(visited[cur]) continue;
        ans ++;
        visited[cur] = true;
        for(int i = 0; i < adj[cur].size(); i ++)
        {
            parties[adj[cur][i]].erase(cur);
            if(parties[adj[cur][i]].size() == 1)
                nextInLine.push(*parties[adj[cur][i]].begin());
        }
    }
    cout << ans << "\n";
}
