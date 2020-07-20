#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct haybale
{
    int a, c;
};
haybale bales[110];
int dp[55010];
int big = 2000000000;
int main()
{
    int n, h, ans = 2000000001;
    cin >> n >> h;
    for(int i = 0; i < n; i ++)
        cin >> bales[i].a >> bales[i].c;
    dp[0] = 0;
    for(int i = 1; i <= h + 5010; i ++)
    {
        dp[i] = big;
        for(int j = 0; j < n; j ++)
            if(i - bales[j].a >= 0)
            {
                if(dp[i - bales[j].a] == big) continue;
                dp[i] = min(dp[i], dp[i - bales[j].a] + bales[j].c);
            }
    }
    for(int i = h; i <= h + 5010; i ++)
        ans = min(ans, dp[i]);
    cout << ans << "\n";
}
