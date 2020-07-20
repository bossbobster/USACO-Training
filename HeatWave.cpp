#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int s, e, val;
};
struct edge2
{
    int e, val;
};
vector<edge2> adj[10000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nextInLine;
bool visited[10000];
int vals[10000];
edge edges[10000];
int main()
{
    int n, m, start, end, cur;
    cin >> n >> m >> start >> end;
    for(int i = 0; i < m; i ++)
        cin >> edges[i].s >> edges[i].e >> edges[i].val;
    for(int i = 1; i <= n; i ++)
        vals[i] = 2000000000;
    for(int i = 0; i < m; i ++)
    {
        adj[edges[i].s].push_back({edges[i].e, edges[i].val});
        adj[edges[i].e].push_back({edges[i].s, edges[i].val});
    }
    nextInLine.push(pair<int, int>(0, start));
    vals[start] = 0;
    while(!nextInLine.empty())
    {
        cur = nextInLine.top().second;
        if(visited[cur] || cur == end)
        {
            nextInLine.pop(); continue;
        }
        nextInLine.pop();
        for(int i = 0; i < adj[cur].size(); i ++)
        {
            if(!visited[adj[cur][i].e] && vals[cur] + adj[cur][i].val < vals[adj[cur][i].e])
            {
                vals[adj[cur][i].e] = vals[cur] + adj[cur][i].val;
                nextInLine.push(pair<int, int>(vals[adj[cur][i].e], adj[cur][i].e));
            }
        }
        visited[cur] = true;
    }
    cout << vals[end] << "\n";
}
