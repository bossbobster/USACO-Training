#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int nums[15];
int dp[100010][15];
int add()
{
    int sum = 0;
    for(int i = 0; i < n; i ++)
        sum += nums[i] * nums[i];
    return sum;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i <= 100005; i ++)
        for(int j = 0; j <= n; j ++)
            dp[i][j] = 2000000000;
    dp[add()][0] = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= 100000; j ++)
            if(dp[j][i] != 2000000000)
                for(int k = 1; k <= 100; k ++)
                    if(j + (k * k) - (nums[i] * nums[i]) <= 100000)
                        dp[j + (k * k) - (nums[i] * nums[i])][i + 1] = min(dp[j + (k * k) - (nums[i] * nums[i])][i + 1], dp[j][i] + (nums[i] - k) * (nums[i] - k));
    cout << ((dp[m][n]==2000000000)?-1:dp[m][n]) << "\n";
}
