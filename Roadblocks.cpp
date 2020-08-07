#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, r, a, b, d, curN, curD, minN, ans = 2000000000;
vector<pii> adj[5010];
priority_queue<pii> nextInLine;
int len[5010][2];
short visited[5010];
void dij(int s)
{
    for(int i = 1; i <= n; i ++)
        len[i][0] = len[i][1] = 2000000000;
    nextInLine.push(pii(0, s));
    len[s][0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        if(visited[curN] == 50) continue;
        visited[curN] ++;
        for(int i = 0; i < adj[curN].size(); i ++)
        {
            len[adj[curN][i].first][1] = min(len[adj[curN][i].first][1], len[curN][1] + adj[curN][i].second);
            if(len[curN][0] + adj[curN][i].second < len[adj[curN][i].first][0])
            {
                len[adj[curN][i].first][1] = min(len[adj[curN][i].first][0], len[curN][1] + adj[curN][i].second);
                len[adj[curN][i].first][0] = len[curN][0] + adj[curN][i].second;
                nextInLine.push(pii(len[adj[curN][i].first][0], adj[curN][i].first));
            }
            if(len[curN][0] + adj[curN][i].second < len[adj[curN][i].first][1] && len[curN][0] + adj[curN][i].second != len[adj[curN][i].first][0])
            {
                len[adj[curN][i].first][1] = len[curN][0] + adj[curN][i].second;
                nextInLine.push(pii(len[adj[curN][i].first][1], adj[curN][i].first));
            }
        }
    }
}
int main()
{
    cin >> n >> r;
    for(int i = 0; i < r; i ++)
    {
        cin >> a >> b >> d;
        adj[a].push_back(pii(b, d));
        adj[b].push_back(pii(a, d));
    }
    dij(1);
    ans = len[n][1];
    cout << ans << "\n";
}
