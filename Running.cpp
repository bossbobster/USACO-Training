#include <iostream>
#include <algorithm>
using namespace std;

int dp[510][510];
int nums[10010];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    dp[0][1] = nums[0]; 
    for(int i = 0; i < n - 1; i ++)
        for(int j = 0; j <= m; j ++)
        {
            if(j < m) dp[(i + 1) % (m + 1)][j + 1] = max(dp[(i + 1) % (m + 1)][j + 1], dp[i % (m + 1)][j] + nums[i + 1]);
            dp[(i + max(1, j)) % (m + 1)][0] = max(dp[(i + max(1, j)) % (m + 1)][0], dp[i % (m + 1)][j]);
        }
    cout << dp[(n - 1) % (m + 1)][0] << "\n";
}
