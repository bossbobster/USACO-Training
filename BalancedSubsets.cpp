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

bitset<160> board[160];
const ll mod = 1000000007;
ll dp[2][160][160][4]; //row, l, r, (can't go right or left, can go in left, can go in right, can go in both)
bitset<160> good[160][160];
ll pre[2][160][160][4]; //prefix sums with left = i or right = i to all other indices
ll ss[160][160][4], bb[160][160][4], sb[160][160][4], bs[160][160][4]; //smaller/bigger first, smaller/bigger last
int main()
{
    input();
    int n;
    ll ans = 0;
    cin >> n;
    char c;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            cin >> c;
            if(c == 'G')
                board[i][j] = 1;
        }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            good[i][j][j] = board[i][j];
            for(int k = j+1; k < n; k ++)
                good[i][j][k] = good[i][j][k-1] & board[i][k];
        }
    for(int i = 0; i < n; i ++)
        for(int j = i; j < n; j ++)
            dp[0][i][j][3] = good[0][i][j], ans = (ans + dp[0][i][j][3]) % mod;
    for(int i = 1; i < n; i ++)
    {
        memset(pre, 0, sizeof(pre)); memset(ss, 0, sizeof(ss)); memset(sb, 0, sizeof(sb)); memset(bb, 0, sizeof(bb)); memset(bs, 0, sizeof(bs));
        for(int j = 0; j < n; j ++)
        {
            for(int cnt = 0; cnt < 4; cnt ++)
                pre[0][j][j][cnt] = dp[(i+1)%2][j][j][cnt];
            for(int k = j+1; k < n; k ++)
                for(int cnt = 0; cnt < 4; cnt ++)
                    pre[0][j][k][cnt] = (pre[0][j][k-1][cnt] + dp[(i+1)%2][j][k][cnt]) % mod;
        }
        for(int j = 0; j < n; j ++)
        {
            for(int cnt = 0; cnt < 4; cnt ++)
                pre[1][j][j][cnt] = dp[(i+1)%2][j][j][cnt];
            for(int k = j-1; k >= 0; k --)
                for(int cnt = 0; cnt < 4; cnt ++)
                    pre[1][j][k][cnt] = (pre[1][j][k+1][cnt] + dp[(i+1)%2][k][j][cnt]) % mod;
        }
        for(int j = 2; j < n; j ++)
            for(int k = 0; k < n-j; k ++)
                for(int cnt = 0; cnt < 4; cnt ++)
                    bs[k][k+j][cnt] = (bs[k+1][k+j-1][cnt] + pre[0][k+1][k+j-1][cnt]+pre[1][k+j-1][k+1][cnt] - dp[(i+1)%2][k+1][k+j-1][cnt] + mod*2) % mod;
        for(int j = n-2; j >= 0; j --)
            for(int k = 1; k < n-j-1; k ++)
                for(int cnt = 0; cnt < 4; cnt ++)
                    sb[k][k+j][cnt] = (sb[k-1][k+j+1][cnt] + pre[0][k-1][n-1][cnt]-pre[0][k-1][k+j][cnt] + pre[1][k+j+1][0][cnt]-pre[1][k+j+1][k][cnt] - dp[(i+1)%2][k-1][k+j+1][cnt] + mod*4) % mod;
        for(int j = 1; j < n-1; j ++) //right
            for(int k = j-1; k >= 0; k --) //left
                for(int cnt = 0; cnt < 4; cnt ++)
                    bb[k][j][cnt] = (bb[k+1][j][cnt] + pre[0][k+1][n-1][cnt]-pre[0][k+1][j][cnt] + mod*2) % mod;
        for(int j = n-2; j > 0; j --) //left
            for(int k = j+1; k < n; k ++) //right
                for(int cnt = 0; cnt < 4; cnt ++)
                    ss[j][k][cnt] = (ss[j][k-1][cnt] + pre[1][k-1][0][cnt]-pre[1][k-1][j][cnt] + mod*2) % mod;
        for(int j = 0; j < n; j ++)
            for(int k = j; k < n; k ++)
                if(good[i][j][k])
                {
                    dp[i%2][j][k][3] = 1; dp[i%2][j][k][0] = dp[i%2][j][k][1] = dp[i%2][j][k][2] = 0;
                    dp[i%2][j][k][0] = (dp[i%2][j][k][0] + sb[j][k][3]+sb[j][k][2]+sb[j][k][1]+sb[j][k][0]) % mod;
                    dp[i%2][j][k][1] = (dp[i%2][j][k][1] + pre[0][j][n-1][3]-pre[0][j][k][3]+pre[0][j][n-1][1]-pre[0][j][k][1] + mod*4) % mod;
                    dp[i%2][j][k][0] = (dp[i%2][j][k][0] + pre[0][j][n-1][2]-pre[0][j][k][2]+pre[0][j][n-1][0]-pre[0][j][k][0] + mod*4) % mod;
                    dp[i%2][j][k][2] = (dp[i%2][j][k][2] + pre[1][k][0][3]-pre[1][k][j][3]+pre[1][k][0][2]-pre[1][k][j][2] + mod*4) % mod;
                    dp[i%2][j][k][0] = (dp[i%2][j][k][0] + pre[1][k][0][1]-pre[1][k][j][1]+pre[1][k][0][0]-pre[1][k][j][0] + mod*4) % mod;
                    dp[i%2][j][k][3] = (dp[i%2][j][k][3] + dp[(i+1)%2][j][k][3]) % mod;
                    dp[i%2][j][k][2] = (dp[i%2][j][k][2] + dp[(i+1)%2][j][k][2]) % mod;
                    dp[i%2][j][k][1] = (dp[i%2][j][k][1] + dp[(i+1)%2][j][k][1]) % mod;
                    dp[i%2][j][k][0] = (dp[i%2][j][k][0] + dp[(i+1)%2][j][k][0]) % mod;
                    dp[i%2][j][k][1] = (dp[i%2][j][k][1] + bb[j][k][1]+bb[j][k][3]) % mod;
                    dp[i%2][j][k][3] = (dp[i%2][j][k][3] + pre[1][k][j+1][3]) % mod;
                    dp[i%2][j][k][1] = (dp[i%2][j][k][1] + pre[1][k][j+1][1]) % mod;
                    dp[i%2][j][k][2] = (dp[i%2][j][k][2] + ss[j][k][2]+ss[j][k][3]) % mod;
                    dp[i%2][j][k][3] = (dp[i%2][j][k][3] + pre[0][j][k-1][3]) % mod;
                    dp[i%2][j][k][2] = (dp[i%2][j][k][2] + pre[0][j][k-1][2]) % mod;
                    dp[i%2][j][k][3] = (dp[i%2][j][k][3] + bs[j][k][3]) % mod;
                    ans = (ans + dp[i%2][j][k][0]+dp[i%2][j][k][1]+dp[i%2][j][k][2]+dp[i%2][j][k][3]) % mod;
                }
        memset(dp[(i+1)%2], 0, sizeof(dp[(i+1)%2]));
    }
    cout << ans << '\n';
}
