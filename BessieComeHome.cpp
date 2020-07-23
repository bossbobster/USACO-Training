#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[100];
bitset<100> finalized;
int minDist[100];
int main()
{
    int n, d, curD, curN = 0, ans2 = 2000000000;
    char a, b, ans1;
    cin >> n;
    for(int i = 0; i < 100; i ++)
        minDist[i] = 2100000000;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b >> d;
        adj[a - 'A'].push_back(pii(b - 'A', d));
        adj[b - 'A'].push_back(pii(a - 'A', d));
    }
    minDist[25] = 0;
    for(int i = 0; i < 60; i ++)
    {
        curD = 2000000000;
        for(int j = 0; j < 100; j ++)
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
            minDist[adj[curN][j].first] = min(minDist[adj[curN][j].first], curD + adj[curN][j].second);
        }
    }
    for(int i = 0; i < 25; i ++)
        if(minDist[i] < ans2)
        {
            ans2 = minDist[i];
            ans1 = 'A' + i;
        }
    cout << ans1 << " " << ans2 << "\n";
}
