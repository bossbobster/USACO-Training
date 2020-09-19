#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

vector<int> adj[100010];
vector<int> leaf;
queue<int> nextInLine;
int distB[100010];
int distL[100010];
bitset<100010> visited;
int main()
{
    int n, k, one, two, cur, ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> one >> two;
        adj[one - 1].push_back(two - 1);
        adj[two - 1].push_back(one - 1);
    }
    for(int i = 0; i < n; i ++)
        if(adj[i].size() == 1)
            leaf.push_back(i);
    for(int i = 0; i < n; i ++)
        distB[i] = distL[i] = 2000000000;
    distB[k - 1] = 0;
    nextInLine.push(k - 1);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(int i = 0; i < adj[cur].size(); i ++)
            if(distB[adj[cur][i]] > distB[cur] + 1)
            {
                distB[adj[cur][i]] = distB[cur] + 1;
                nextInLine.push(adj[cur][i]);
            }
    }
    visited.reset();
    for(int i = 0; i < leaf.size(); i ++)
    {
        nextInLine.push(leaf[i]);
        distL[leaf[i]] = 0;
    }
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(int i = 0; i < adj[cur].size(); i ++)
            if(distL[adj[cur][i]] > distL[cur] + 1)
            {
                distL[adj[cur][i]] = distL[cur] + 1;
                nextInLine.push(adj[cur][i]);
            }
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < adj[i].size(); j ++)
            if(distB[i] >= distL[i] && distB[adj[i][j]] < distL[adj[i][j]])
                ans ++;
    }
    cout << ans << "\n";
}
