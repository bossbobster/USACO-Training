#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int mod = 1000000007;
long long dp[1000010];
int main()
{
    long long n, m, k, sum = 0, ans = 1;
    cin >> n >> m >> k;
    dp[0] = 1; sum = 1;
    for(int i = 1; i <= n; i ++)
    {
        dp[i] = (sum * (m - 1) + ((i < k)?1:0)) % mod;
        sum += dp[i];
        if(i - k + 1 >= 0) sum -= dp[i - k + 1];
        sum = (sum % mod);
    }
    for(int i = 0; i < n; i ++)
        ans = (ans * m) % mod;
    cout << (ans - dp[n]) % mod << "\n";
}
