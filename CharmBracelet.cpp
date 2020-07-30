#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int dp[13000];
pii bales[3500];
int main()
{
    int n, c, ans = 0;
    cin >> n >> c;
    for(int i = 0; i < n; i ++)
        cin >> bales[i].first >> bales[i].second;
    for(int i = 1; i < c; i ++)
        dp[i] = -2000000000;
    for(int i = 0; i < n; i ++)
        for(int j = c; j >= 0; j --)
            if(j - bales[i].first >= 0)
                if(dp[j - bales[i].first] >= 0)
                    dp[j] = max(dp[j], dp[j - bales[i].first] + bales[i].second);
    for(int i = 0; i <= c; i ++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}
