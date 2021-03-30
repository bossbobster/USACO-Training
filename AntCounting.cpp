#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int dp[2][100010];
int cnt[1010];
int get(int idx1, int idx)
{
    if(idx < 0) return 0;
    return dp[idx1][idx];
}
int main()
{
    int fam, n, a, b, num, sum = 0, mod = 1000000, ans = 0;
    cin >> fam >> n >> a >> b;
    for(int i = 0; i < n; i ++)
    {
        cin >> num;
        cnt[num-1] ++;
    }
    for(int i = 0; i <= cnt[0]; i ++)
        dp[0][i] = 1;
    num = cnt[0];
    for(int i = 1; i < fam; i ++)
    {
        sum = dp[(i+1)%2][0]; num += cnt[i];
        for(int j = 0; j <= num; j ++)
        {
            dp[i%2][j] = sum;
            sum -= get((i+1)%2, j - cnt[i]); sum += get((i+1)%2, j + 1);
            sum = (sum % mod);
        }
    }
    for(int i = a; i <= b; i ++)
        ans = (ans + dp[(fam-1)%2][i]) % mod;
    cout << ((ans<0)?1000000+ans:ans) << "\n";
}
