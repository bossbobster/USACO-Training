#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

int nums[2010];
int dp[2010][2010];
int main()
{
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = n - 1; i >= 0; i --)
    {
        sum += nums[i];
        for(int j = 1; j <= n - i; j ++)
        {
            if(j >= n - i)
                dp[i][j] = sum;
            else
                dp[i][j] = max(sum - dp[i + j][min(n - i - j, j * 2)], dp[i][j - 1]);
        }
    }
    cout << max(dp[0][1], dp[0][2]) << "\n";
}
