#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

int n, q, a, b, d, cur = 0;
bool done = false;
bitset<1010> visited;
vector<pii> adj[1010];
void dfs(int node, int curD, int e)
{
    if(visited[node] || done) return;
    visited[node] = true;
    if(node == e) { cur = curD; done = true; return; }
    for(int i = 0; i < adj[node].size(); i ++)
        dfs(adj[node][i].first, curD + adj[node][i].second, e);
}
int main()
{
    cin >> n >> q;
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> a >> b >> d;
        adj[a].push_back(pii(b, d));
        adj[b].push_back(pii(a, d));
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b;
        visited.reset();
        cur = 0;
        done = false;
        dfs(a, 0, b);
        cout << cur << "\n";
    }
}
