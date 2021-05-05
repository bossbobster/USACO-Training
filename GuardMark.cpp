#include <iostream>
#include <string.h>
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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input(x) ios_base::sync_with_stdio(x); cin.tie(x);

ifstream fin("guard.in");
ofstream fout("guard.out");

struct st
{
    ll h, w, s;
};
struct st2
{
    ll h, s;
};
st nums[30];
st2 dp[1050000];
int main()
{
    ll n, h, ans = -1;
    fin >> n >> h;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i].h >> nums[i].w >> nums[i].s;
        dp[1 << i] = {nums[i].h, nums[i].s};
    }
    for(int i = 1; i < (1 << n); i ++)
    {
        if(bitset<20>(i).count() == 1) continue;
        for(int j = 0; j < n; j ++)
        {
            if((1 << j) & i && dp[i].s < dp[i^(1<<j)].s - nums[j].w)
            {
                dp[i].h = dp[i^(1<<j)].h + nums[j].h;
                dp[i].s = min(dp[i^(1<<j)].s - nums[j].w, nums[j].s);
            }
        }
        if(dp[i].h >= h) ans = max(ans, dp[i].s);
    }
    if(ans == -1) fout << "Mark is too tall\n";
    else fout << ans << "\n";
}
