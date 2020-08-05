#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pii;

pii adj[1010][1010];
pii minDist[1010];
bool finalized[1010];
int route[110];
long long minL(long long l1, long long l2)
{
    if(l1 < l2) return l1;
    return l2;
}
int main()
{
    long long a, b, n, n2, c, curD, curN, f, s;
    cin >> a >> b >> n;
    for(int i = 0; i < 1010; i ++)
        for(int j = 0; j < 1010; j ++)
            adj[i][j].first = adj[i][j].second = 200000000000000;
    for(int i = 0; i < 1010; i ++)
        minDist[i].first = minDist[i].second = 200000000000000;
    for(int i = 0; i < n; i ++)
    {
        cin >> c >> n2;
        for(int j = 0; j < n2; j ++)
            cin >> route[j];
        for(int j = 0; j < n2 - 1; j ++)
            for(int k = j + 1; k < n2; k ++)
            {
                f = route[j]; s = route[k];
                if(adj[f][s].first > c) { adj[f][s].first = c; adj[f][s].second = k - j; }
                if(adj[f][s].first == c) { adj[f][s].second = minL(adj[f][s].second, k - j); }
            }
    }
    minDist[a].first = minDist[a].second = 0;
    for(int i = 1; i <= 1000; i ++)
    {
        curD = 200000000000000;
        for(int j = 1; j <= 1000; j ++)
            if(minDist[j].first < curD)
            {
                if(finalized[j]) continue;
                curD = minDist[j].first;
                curN = j;
            }
        finalized[curN] = true;
        for(int j = 1; j <= 1000; j ++)
        {
            if(finalized[j]) continue;
            if(minDist[j].first > curD + adj[curN][j].first)
            {
                minDist[j].first = curD + adj[curN][j].first;
                minDist[j].second = minDist[curN].second + adj[curN][j].second;
            }
            if(minDist[j].first == curD + adj[curN][j].first)
                minDist[j].second = minL(minDist[j].second, minDist[curN].second + adj[curN][j].second);
        }
    }
    if(minDist[b].first == 200000000000000) { cout << "-1 -1\n"; return 0; }
    cout << minDist[b].first << " " << minDist[b].second << "\n";
}
