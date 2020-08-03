#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

int cows[110];
vector<int> adj[1010];
int cnt[1010];
bitset<1010> visited;
queue<int> nextInLine;
int main()
{
    int k, n, m, one, two, cur, ans = 0;
    cin >> k >> n >> m;
    for(int i = 0; i < k; i ++)
        cin >> cows[i];
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        adj[one].push_back(two);
    }
    for(int i = 0; i < k; i ++)
    {
        visited.reset();
        nextInLine.push(cows[i]);
        while(!nextInLine.empty())
        {
            cur = nextInLine.front();
            nextInLine.pop();
            if(visited[cur]) continue;
            visited[cur] = true;
            cnt[cur] ++;
            for(int i = 0; i < adj[cur].size(); i ++)
                nextInLine.push(adj[cur][i]);
        }
    }
    for(int i = 1; i <= n; i ++)
        if(cnt[i] == k)
            ans ++;
    cout << ans << "\n";
}
