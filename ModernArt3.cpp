#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//ulng namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int nums[310];
int dp[310][310]; // start, size
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    for(int i = 2; i <= n; i ++)
        for(int j = n - i; j >= 0; j --)
        {
            for(int k = 1; k < i; k ++)
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[j + k - 1][i - k + 1]);
            if(nums[j] == nums[j + i - 1]) dp[j][i] = max(dp[j][i], dp[j + 1][i - 2] + 1);
        }
    cout << n - dp[0][n] << "\n";
}
