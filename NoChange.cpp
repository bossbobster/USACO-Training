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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
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
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int coins[20], nums[100010], pre[100010], dp[1<<17];
int main()
{
    input();
    int k, n, ans = -1, sum = 0;
    cin >> k >> n;
    for(int i = 0; i < k; i ++)
        cin >> coins[i];
    for(int i = 0; i < n; i ++)
        cin >> nums[i], pre[i+1] = pre[i] + nums[i];
    dp[0] = 0;
    for(int i = 1; i < (1<<k); i ++)
        for(int j = 0; j < k; j ++)
            if(i & (1<<j) && dp[i^(1<<j)] != n)
            {
                dp[i] = max(dp[i], (int)(upper_bound(pre, pre+n+1, coins[j]+pre[dp[i^(1<<j)]])-pre-1));
                if(dp[i] == n)
                {
                    sum = 0;
                    for(int l = 0; l < k; l ++)
                        if(!(i & (1<<l)))
                            sum += coins[l];
                    ans = max(ans, sum);
                }
            }
    cout << ans << '\n';
}
