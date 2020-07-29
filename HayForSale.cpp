#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool dp[50010];
int bales[5010];
int main()
{
    int n, c, ans = 0;
    cin >> c >> n;
    for(int i = 0; i < n; i ++)
        cin >> bales[i];
    dp[0] = true;
    for(int i = 0; i < n; i ++)
        for(int j = c; j >= 0; j --)
            if(j - bales[i] >= 0)
                if(dp[j - bales[i]] >= 0)
                    dp[j] = max(dp[j], dp[j - bales[i]]);
    for(int i = c; i >= 0; i --)
        if(dp[i])
        {
            cout << i << "\n";
            break;
        }
}
