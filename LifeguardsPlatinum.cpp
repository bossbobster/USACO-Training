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
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
typedef pair<uint, uint> puint;
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
//#define cout fout

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

pii nums[100010];
bitset<100010> bad;
vector<pii> v;
vector<int> r;
int dp[100010][110];
int l[100010];
int main()
{
    int n, k;
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].f >> nums[i].s;
    if(n == k)
    {
        fout << "0\n";
        return 0;
    }
    sort(nums, nums+n);
    int mx = 0;
    for(int i = 0; i < n; i ++)
    {
        if(nums[i].s <= mx) bad[i] = 1;
        mx = max(mx, nums[i].s);
    }
    for(int i = 0; i < n; i ++)
        if(!bad[i])
            v.push_back(nums[i]), r.push_back(nums[i].s);
    k -= (n-(int)v.size());
    n = (int)v.size();
    memset(dp, -1, sizeof(dp));
    dp[0][0] = v[0].s-v[0].f;
    l[0] = 0;
    for(int i = 1; i < n; i ++)
        l[i] = (int)(upper_bound(r.begin(), r.end(), v[i].f)-r.begin());
    for(int i = 1; i < n; i ++)
    {
        for(int j = min(i, k); j >= 0; j --)
        {
            dp[i][j] = dp[i][j+1];
            if(dp[i-1][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i-1][j]+v[i].s-max(v[i].f, v[i-1].s));
            if(j > 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            if(l[i] != i && dp[l[i]][max(0, j-(i-l[i]-1))] != -1)
                dp[i][j] = max(dp[i][j], dp[l[i]][max(0, j-(i-l[i]-1))]+v[i].s-v[l[i]].s);
            if(l[i] > 0 && dp[l[i]-1][max(0, j-(i-l[i]))] != -1)
                dp[i][j] = max(dp[i][j], dp[l[i]-1][max(0, j-(i-l[i]))]+v[i].s-v[i].f);
            if(j <= i)
                dp[i][j] = max(dp[i][j], v[i].s-v[i].f);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++)
        ans = max(ans, dp[i][max(0, k-(n-i-1))]);
    fout << ans << '\n';
}
