#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int nums[2010];
int len[2010];
priority_queue<pii, vector<pii>, less<pii>> nextInLine;
vector<pii> adj[2010];
bool finalized[2010];
int main()
{
    long long n, curN, curD, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n - 1; i ++)
        for(int j = i + 1; j < n; j ++)
        {
            adj[i].push_back(pii(j, nums[i] ^ nums[j]));
            adj[j].push_back(pii(i, nums[i] ^ nums[j]));
        }
    for(int i = 0; i < n; i ++)
        len[i] = -2000000000;
    nextInLine.push(pii(0, 0));
    len[0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        if(finalized[curN]) continue;
        if(curD > len[curN]) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(adj[curN][i].second > len[adj[curN][i].first] && !finalized[adj[curN][i].first])
            {
                len[adj[curN][i].first] = adj[curN][i].second;
                nextInLine.push(pii(len[adj[curN][i].first], adj[curN][i].first));
            }
        finalized[curN] = true;
    }
    for(int i = 0; i < n; i ++)
        ans += len[i];
    cout << ans << "\n";
}
