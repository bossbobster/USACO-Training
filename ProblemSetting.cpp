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
#include <array>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <memory>
#include <cassert>
#include <chrono>
#include <type_traits>
#include <stdexcept>
#include <string_view>
#include <regex>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pis, string> piss;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<uint, uint> puint;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef pair<pll, ld> plld;
typedef pair<ld, int> pldi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define eps 1e-8
//#define eps2 1e-15
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
//#define cin fin
//#define cout fout
//#define fin cin
//#define fout cout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

/*

     ._________.
     |_________|
   ---------------
  |_____• U •_____|
 -------------------
|___________________|


 */

const ll mod = 1000000007;
ll dp[1050000][21], st[1050000];
bitset<1050000> bb;
ll ex(ll base, ll power)
{
    ll ans = 1;
    while(power)
    {
        if(power&1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        power /= 2;
    }
    return ans;
}
int main()
{
    input();
    int n, m;
    char c;
    cin >> n >> m;
    bitset<20> b[100010];
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            cin >> c;
            if(c == 'H')
                b[j][m-i-1] = 1;
        }
    }
    for(int i = 0; i < n; i ++)
        st[b[i].to_ulong()] ++, bb[b[i].to_ulong()] = 1;
    for(int i = 0; i < (1<<m); i ++)
        if(st[i] != 0)
        {
            ll fac = 1, sum = 0;
            for(ll j = 1; j <= st[i]; j ++)
                fac = (fac*j)%mod;
            for(int j = 1; j <= st[i]; j ++)
            {
                sum = (sum+fac)%mod;
                fac = (fac*ex(j, mod-2))%mod;
            }
            st[i] = sum;
        }
    ll ans = 0;
    for(int i = 0; i < (1<<m); i ++)
    {
        dp[i][0] = min(st[i], 1LL);
        for(int j = 0; j < m; j ++)
        {
            dp[i][j+1] = dp[i][j];
            if(i & (1<<j))
                dp[i][j+1] = (dp[i][j+1] + dp[i-(1<<j)][j]) % mod;
        }
        if(bb[i])
        {
            ans = (ans+dp[i][m]*st[i])%mod;
            dp[i][0] = (dp[i][m]*st[i])%mod;
            for(int j = 0; j < m; j ++)
            {
                dp[i][j+1] = dp[i][j];
                if(i & (1<<j))
                    dp[i][j+1] = (dp[i][j+1] + dp[i-(1<<j)][j]) % mod;
            }
        }
    }
    cout << ans << '\n';
}
