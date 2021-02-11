#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int cnt[26][26];
set<char> used;
long long dp[1100000];
vector<int> let;
int main()
{
    int n;
    long long cur;
    string st;
    cin >> st;
    for(int i = 0; i < st.length(); i ++)
        used.insert(st[i]);
    cur = 0;
    for(char c : used)
    {
        let.push_back(c - 'a'); cur ++;
    }
    for(int i = 1; i < st.length(); i ++)
        cnt[st[i - 1] - 'a'][st[i] - 'a'] ++;
    n = (int)used.size();
    for(int i = 0; i < 1100000; i ++)
        dp[i] = 2000000000;
    dp[0] = 1;
    for(int i = 0; i < (1 << n); i ++)
        for(int j = 0; j < n; j ++)
            if((i & (1 << j)) != 0)
            {
                cur = dp[i ^ (1 << j)];
                for(int k = 0; k < n; k ++)
                    if((i & (1 << k)) != 0)
                        cur += cnt[let[j]][let[k]];
                dp[i] = min(dp[i], cur);
            }
    cout << dp[(1 << n) - 1] << "\n";
}
