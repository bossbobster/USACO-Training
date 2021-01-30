#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define max(n, m) ((n>m)?n:m)
typedef pair<int, int> pii;

pii nums[1010];
vector<int> adj[1010];
int len[1010][1010];
queue<pii> nextInLine;
bitset<1010> visited;
int dp[1010];
int main()
{
    int n, e, d, cur, curN, curD, ans = 0;
    cin >> n >> e;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].first >> d;
        nums[i].second = i;
        for(int j = 0; j < d; j ++)
        {
            cin >> cur;
            adj[i].push_back(cur - 1);
        }
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
            len[i][j] = 2000000000;
        visited.reset();
        nextInLine.push({i, 0});
        len[i][i] = 0;
        while(!nextInLine.empty())
        {
            curN = nextInLine.front().first;
            curD = nextInLine.front().second;
            nextInLine.pop();
            if(visited[curN]) continue;
            len[i][curN] = curD;
            visited[curN] = true;
            for(int j = 0; j < adj[curN].size(); j ++)
                if(!visited[adj[curN][j]])
                    nextInLine.push({adj[curN][j], curD + 1});
        }
    }
    sort(nums, nums + n);
    dp[0] = nums[0].first; ans = dp[0];
    for(int i = 1; i < n; i ++)
    {
        dp[i] = nums[i].first;
        for(int j = 0; j < i; j ++)
            if(len[nums[i].second][nums[j].second] != 2000000000)
                dp[i] = max(dp[i], dp[j] + nums[i].first - (len[nums[i].second][nums[j].second] * e));
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
