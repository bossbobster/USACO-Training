#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int len[50010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[50010];
int cows[10010];
int par[10010];
int paths[10010];
int main()
{
    long long n, m, t, curN, curD, one, two, three, ans = 0;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i ++)
        cin >> cows[i];
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
        adj[two - 1].push_back(pii(one - 1, three));
    }
    for(int i = 0; i < n; i ++)
        len[i] = par[i] = 2000000000;
    nextInLine.push(pii(0, 0));
    len[0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len[curN] + adj[curN][i].second < len[adj[curN][i].first] || (len[curN] + adj[curN][i].second == len[adj[curN][i].first] && curN < par[adj[curN][i].first]))
            {
                len[adj[curN][i].first] = len[curN] + adj[curN][i].second;
                nextInLine.push(pii(len[adj[curN][i].first], adj[curN][i].first));
                par[adj[curN][i].first] = curN;
            }
    }
    for(int i = 0; i < n; i ++)
    {
        curN = i;
        while(par[curN] != 2000000000)
        {
            paths[curN] += cows[i];
            curN = par[curN];
        }
    }
    for(int i = 1; i < n; i ++)
        ans = max(ans, paths[i] * (len[i] - t));
    cout << ans << "\n";
}
