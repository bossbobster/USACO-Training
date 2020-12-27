#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[210];
long long dist[210][210];
long long minL(long long l1, long long l2)
{
    if(l1 < l2) return l1;
    return l2;
}
int main()
{
    long long n, m, k, q, one, two, three, ans = 0, sum = 0, cur;
    cin >> n >> m >> k >> q;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            dist[i][j] = 2000000000000000;
    for(int i = 0; i < n; i ++)
        dist[i][i] = 0;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
        dist[one - 1][two - 1] = minL(dist[one - 1][two - 1], three);
    }
    for(int k = 0; k < n; k ++)
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                dist[i][j] = minL(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i = 0; i < q; i ++)
    {
        cin >> one >> two;
        cur = 2000000000000000;
        for(int j = 0; j < k; j ++)
            cur = minL(cur, dist[one - 1][j] + dist[j][two - 1]);
        if(cur != 2000000000000000)
        {
            ans ++;
            sum += cur;
        }
    }
    cout << ans << "\n" << sum << "\n";
}
