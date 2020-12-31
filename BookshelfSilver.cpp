// THIS PROBLEM IS FROM THE OLD SILVER (now gold)
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct book
{
    int w, h;
};

book nums[2010];
int dp[2010];
int main()
{
    int n, l, maxN, sum;
    cin >> n >> l;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].h >> nums[i].w;
    dp[0] = 0;
    for(int i = 1; i <= n; i ++)
    {
        maxN = nums[i - 1].h; sum = nums[i - 1].w;
        dp[i] = dp[i - 1] + maxN;
        for(int j = i - 1; j >= 1; j --)
        {
            maxN = max(maxN, nums[j - 1].h);
            sum += nums[j - 1].w;
            if(sum <= l)
                dp[i] = min(dp[i], maxN + dp[j - 1]);
        }
    }
    cout << dp[n] << "\n";
}
