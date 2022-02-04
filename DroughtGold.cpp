#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef pair<pll, ld> plld;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define eps 1e-9
//#define cin fin
//ifstream fin("/Users/bobby/prob1_platinum_feb21/20.in");

short nums[110];
const int mod = 1000000007;
int dp[110][1010], pre[110][1010];
int main()
{
    input();
    short n, mx = 0, mn = 2000, chk;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i], mx = max(mx, nums[i]), mn = min(mn, nums[i]);
    if(n & 1)
        for(int i = 0; i <= mn; i ++) //target
        {
            memset(dp, 0, sizeof(dp)); memset(pre, 0, sizeof(pre));
            for(int k = 0; k <= min(nums[0]-i, nums[1]-i); k ++)
                dp[0][k] = 1, pre[0][k] = k+1;
            for(int k = min(nums[0]-i, nums[1]-i)+1; k <= mx; k ++)
                pre[0][k] = pre[0][k-1];
            for(int j = 1; j < n-1; j ++) //loop through positions
            {
                chk = min(nums[j]-i, nums[j+1]-i);
                for(int k = 0; k <= chk; k ++)
                {
                    dp[j][k] = (dp[j][k] + pre[j-1][nums[j]-i-k]) % mod;
                    if(j == n-2) ans = (ans + dp[j][k]) % mod;
                    if(k == 0) pre[j][0] = dp[j][0];
                    else pre[j][k] = (pre[j][k-1] + dp[j][k]) % mod;
                }
                for(int k = chk+1; k <= mx; k ++)
                    pre[j][k] = pre[j][k-1];
            }
        }
    else
    {
        memset(dp, 0, sizeof(dp)); memset(pre, 0, sizeof(pre));
        for(int k = 0; k <= min(nums[0], nums[1]); k ++)
            dp[0][k] = 1, pre[0][k] = k+1;
        for(int k = min(nums[0], nums[1])+1; k <= mx; k ++)
            pre[0][k] = pre[0][k-1];
        for(int j = 1; j < n-1; j ++) //loop through positions
        {
            chk = min(nums[j], nums[j+1]);
            for(int k = 0; k <= chk; k ++)
            {
                dp[j][k] = (dp[j][k] + pre[j-1][nums[j]-k]) % mod;
                if(j == n-2) ans = (ans + dp[j][k]) % mod;
                if(k == 0) pre[j][0] = dp[j][0];
                else pre[j][k] = (pre[j][k-1] + dp[j][k]) % mod;
            }
            for(int k = chk+1; k <= mx; k ++)
                pre[j][k] = pre[j][k-1];
        }
    }
    cout << ans << '\n';
}
