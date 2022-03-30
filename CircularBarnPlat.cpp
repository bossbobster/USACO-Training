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

ifstream fin("cbarn.in");
ofstream fout("cbarn.out");

int n, first;
ll nums[1010], pre[3010][3010];
ll dp[2010][10]; // current index, doors used
void dc(int l, int r, int l2, int r2, int door)
{
    if(l > r) return;
    int mid = (l+r)/2;
    pair<ll, int> ans = {2000000000000000, -1};
    for(int i = l2; i <= min(mid, r2); i ++)
        ans = min(ans, {dp[i-1][door-1]+pre[i][mid-1], i});
    dp[mid][door] = ans.f;
    dc(l, mid-1, l2, ans.s, door);
    dc(mid+1, r, ans.s, r2, door);
}
int main()
{
    ll m, ans = 20000000000000000;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i <= 2*n; i ++)
        pre[i][i] = nums[i%n];
    for(int i = 0; i <= 3*n; i ++)
        for(int j = i+1; j <= 3*n; j ++)
            pre[i][j] = pre[i][j-1]+nums[j%n]*(j-i+1);
    for(first = 0; first < n; first ++)
    {
        for(int i = 0; i <= n*2; i ++)
            for(int j = 0; j <= m; j ++)
                dp[i][j] = 2000000000000000;
        dp[first][1] = 0;
        for(int i = 2; i <= m; i ++)
            dc(first+1, first+n-1, first+1, first+n-1, i);
        for(int i = first; i < first+n; i ++)
            ans = min(ans, dp[i][m]+pre[i+1][first+n-1]);
    }
    fout << ans << "\n";
}
