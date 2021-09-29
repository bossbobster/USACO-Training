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
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

short nums[60];
short dp[51][51][51][51];
int main()
{
    input();
    short n, r, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i], nums[i]--;
    for(int i = 0; i < n; i ++)
        dp[i][i][nums[i]][nums[i]] = 1;
    for(short i = 1; i < n; i ++)
        for(short l = 0; l < n-i; l ++)
        {
            r = l+i;
            for(short lo = 0; lo < 50; lo ++)
                for(short hi = lo; hi < 50; hi ++)
                {
                    dp[l][r][lo][hi] = max(max(dp[l][r][lo][hi], dp[l+1][r][lo][hi]), dp[l][r-1][lo][hi]);
                    if(nums[l] <= lo) dp[l][r][nums[l]][hi] = max(dp[l][r][nums[l]][hi], dp[l+1][r][lo][hi]+1);
                    if(nums[r] >= hi) dp[l][r][lo][nums[r]] = max(dp[l][r][lo][nums[r]], dp[l][r-1][lo][hi]+1);
                    if(nums[r] <= lo) dp[l][r][nums[r]][hi] = max(dp[l][r][nums[r]][hi], dp[l+1][r-1][lo][hi]+1);
                    if(nums[l] >= hi) dp[l][r][lo][nums[l]] = max(dp[l][r][lo][nums[l]], dp[l+1][r-1][lo][hi]+1);
                    if(nums[r] <= lo && nums[l] >= hi) dp[l][r][nums[r]][nums[l]] = max(dp[l][r][nums[r]][nums[l]], dp[l+1][r-1][lo][hi]+2);
                }
        }
    for(int i = 0; i < 50; i ++)
        for(int j = 0; j < 50; j ++)
            ans = max(ans, dp[0][n-1][i][j]);
    cout << ans << '\n';
}
