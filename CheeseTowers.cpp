#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

struct st
{
    int v, h;
};

int dp[1010][1010];
st nums[110];
queue<pii> nextInLine;
int main()
{
    int n, t, k, curReg, curComp, ans = 0;
    cin >> n >> t >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].v >> nums[i].h;
    dp[0][0] = 0;
    nextInLine.push(pii(0, 0));
    while(!nextInLine.empty())
    {
        curReg = nextInLine.front().first;
        curComp = nextInLine.front().second;
        nextInLine.pop();
        if(curReg + curComp > t + 200) continue;
        if(curReg + curComp <= t) ans = max(ans, dp[curReg][curComp]);
        for(int i = 0; i < n; i ++)
        {
            if(nums[i].h < k)
            {
                if(dp[curReg][curComp] + nums[i].v > dp[curReg + nums[i].h][curComp])
                {
                    dp[curReg + nums[i].h][curComp] = dp[curReg][curComp] + nums[i].v;
                    nextInLine.push(pii(curReg + nums[i].h, curComp));
                }
            }
            else
            {
                if(dp[curReg][curComp] + nums[i].v > dp[nums[i].h][curComp + (int)((double)curReg * 0.8)])
                {
                    dp[nums[i].h][curComp + (int)((double)curReg * 0.8)] = dp[curReg][curComp] + nums[i].v;
                    nextInLine.push(pii(nums[i].h, curComp + (int)((double)curReg * 0.8)));
                }
            }
        }
    }
    cout << ans << "\n";
}
