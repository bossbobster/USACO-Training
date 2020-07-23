#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[110];
bitset<110> finalized;
int minDist[110];
int queries[110][110];
int map[10010];
int main()
{
    int n, m, a, b, d, curD, curN = 0, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
        cin >> map[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            cin >> d;
            adj[i].push_back(pii(j, d));
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
                minDist[adj[curN][j].first] = min(minDist[adj[curN][j].first], curD + adj[curN][j].second);
            }
        }
    }
    for(int i = 0; i < m - 1; i ++)
    {
        a = map[i]; b = map[i + 1];
        ans += queries[a - 1][b - 1];
    }
    cout << ans << "\n";
}
