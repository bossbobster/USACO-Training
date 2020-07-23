#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[310];
bitset<310> finalized;
int minDist[310];
int queries[310][310];
int main()
{
    int n, m, t, d, a, b, curD, curN = 0;
    cin >> n >> m >> t;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b >> d;
        adj[a - 1].push_back(pii(b - 1, d));
    }
    for(int k = 0; k < n; k ++)
    {
        for(int i = 0; i < n; i ++)
        {
            minDist[i] = 2000000000;
            finalized[i] = false;
        }
        minDist[k] = 0;
        for(int i = 0; i < n; i ++)
        {
            curD = 2000000000;
            for(int j = 0; j < n; j ++)
                if(minDist[j] < curD)
                {
                    if(finalized[j]) continue;
                    curD = minDist[j];
                    curN = j;
                }
            finalized[curN] = true;
            queries[k][curN] = minDist[curN];
            for(int j = 0; j < adj[curN].size(); j ++)
            {
                if(finalized[adj[curN][j].first]) continue;
                minDist[adj[curN][j].first] = min(minDist[adj[curN][j].first], max(curD, adj[curN][j].second));
            }
        }
    }
    for(int i = 0; i < t; i ++)
    {
        cin >> a >> b;
        if(queries[a - 1][b - 1] != 0) cout << queries[a - 1][b - 1] << "\n";
        else cout << -1 << "\n";
    }
}
