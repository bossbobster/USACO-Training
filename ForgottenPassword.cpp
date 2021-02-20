#include <iostream>
#include <algorithm>
using namespace std;

string dp[1010];
string nums[1010];
int main()
{
    int l, n;
    string st;
    bool good;
    cin >> l >> n >> st;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i <= l; i ++)
    {
        dp[i].reserve(l + 5);
        dp[i] = "{}";
    }
    dp[0] = "";
    for(int i = 0; i < l; i ++)
        for(int j = 0; j < n; j ++)
            if(i + nums[j].length() <= l)
            {
                good = true;
                for(int k = 0; k < nums[j].length(); k ++)
                    if(nums[j][k] != st[i + k] && st[i + k] != '?')
                    {
                        good = false;
                        break;
                    }
                if(!good) continue;
                if(dp[i] + nums[j] < dp[i + nums[j].length()])
                    dp[i + nums[j].length()] = dp[i] + nums[j];
            }
    cout << dp[l] << "\n";
}
