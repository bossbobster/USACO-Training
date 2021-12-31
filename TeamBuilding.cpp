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

const int mod = 1000000009;
vector<pii> all;
int dp[2010][11][11];
int main()
{
    int n, m, k, num;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++)
        cin >> num, all.push_back({num, 0});
    for(int i = 0; i < m; i ++)
        cin >> num, all.push_back({num, 1});
    sort(all.begin(), all.end());
    dp[0][0][0] = 1;
    for(int i = 1; i <= all.size(); i ++)
        for(int j = 0; j <= k; j ++)
            for(int p = j; p <= k; p ++)
            {
                dp[i][j][p] = (dp[i][j][p] + dp[i-1][j][p]) % mod;
                if(all[i-1].s == 0 && j != 0)
                    dp[i][j][p] = (dp[i][j][p] + dp[i-1][j-1][p]) % mod;
                if(all[i-1].s == 1 && p != 0)
                    dp[i][j][p] = (dp[i][j][p] + dp[i-1][j][p-1]) % mod;
            }
    cout << dp[all.size()][k][k] << '\n';
}
