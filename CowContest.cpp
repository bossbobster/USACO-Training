#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<int> adj[110];
int cnt[110];
bitset<110> visited;
void dfs(int cur, int start)
{
    if(visited[cur]) return;
    visited[cur] = true;
    cnt[start] ++;
    if(cur != start) cnt[cur] ++;
    for(int i = 0; i < adj[cur].size(); i ++)
        dfs(adj[cur][i], start);
}
int main()
{
    int n, m, cur1, cur2, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> cur1 >> cur2;
        adj[cur1 - 1].push_back(cur2 - 1);
    }
    for(int i = 0; i < n; i ++)
    {
        visited.reset();
        dfs(i, i);
    }
    for(int i = 0; i < n; i ++)
        if(cnt[i] == n)
            ans ++;
    cout << ans << "\n";
}
