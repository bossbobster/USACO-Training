#include <iostream>
#include <fstream>
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
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("248.in");
ofstream fout("248.out");

int dp[250][250];
int nums[250];
int main()
{
    int n, ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i < n; i ++)
        dp[i][1] = nums[i];
    for(int i = 2; i <= n; i ++)
        for(int j = 0; j < n - i + 1; j ++)
            for(int k = 1; k < i; k ++)
                if(dp[j][k] == dp[j + k][i - k])
                {
                    dp[j][i] = max(dp[j][i], dp[j][k] + 1);
                    ans = max(ans, dp[j][i]);
                }
    fout << ans << "\n";
}
