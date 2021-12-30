//greedily make squares from top left and use lazy seg trees
//for each column (also binary search for B).
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

int nums[15];
int dp[15][5010];
const int mod = 100000000;
int main()
{
    input();
    int n, m, num, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> num;
            if(num == 0) num = 1;
            else num = 0;
            nums[i] += num * (1<<j);
        }
    for(int i = 0; i < (1<<m); i ++)
        if((i & (i>>1)) == 0 && ((i & nums[0]) == 0))
            dp[0][i] ++;
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < (1<<m); j ++)
            if((j & (j>>1)) == 0 && ((j & nums[i-1]) == 0))
                for(int k = 0; k < (1<<m); k ++)
                    if((k & (k>>1)) == 0 && ((k & nums[i]) == 0) && (k & j) == 0)
                        dp[i][k] = (dp[i][k] + dp[i-1][j]) % mod;
    for(int i = 0; i < (1<<m); i ++)
        ans = (ans + dp[n-1][i]) % mod;
    cout << ans << '\n';
}
