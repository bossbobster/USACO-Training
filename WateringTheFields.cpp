#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[2010];
bitset<2010> finalized;
int minDist[2010];
pii nums[2010];
int main()
{
    long long n, c, d, curD, curN = 0, ans = 0;
    cin >> n >> c;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].first >> nums[i].second;
        for(int j = i; j >= 0; j --)
        {
            d = (nums[i].first - nums[j].first) * (nums[i].first - nums[j].first) + (nums[i].second - nums[j].second) * (nums[i].second - nums[j].second);
            if(d >= c) { adj[j].push_back(pii(i, d)); adj[i].push_back(pii(j, d)); }
        }
    }
    for(int i = 0; i < n; i ++)
    {
        minDist[i] = 2000000000;
        finalized[i] = false;
    }
    minDist[0] = 0;
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
        for(int j = 0; j < adj[curN].size(); j ++)
        {
            if(finalized[adj[curN][j].first]) continue;
            minDist[adj[curN][j].first] = min(minDist[adj[curN][j].first], adj[curN][j].second);
        }
    }
    for(int i = 0; i < n; i ++)
    {
        if(minDist[i] == 2000000000) { cout << -1 << "\n"; return 0; }
        ans += minDist[i];
    }
    if(ans != 0) cout << ans << "\n";
}
