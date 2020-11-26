#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
using namespace std;

ifstream fin("poetry.in");
ofstream fout("poetry.out");

struct st
{
    int sy, group;
};
long long mod = 1000000007;

long long exp(long long base, long long power)
{
    if(power == 0) return 1;
    if(power == 1) return base;
    long long cur = exp(base, power / 2);
    long long ans = (cur * cur) % mod;
    if(power % 2 == 1) ans = (ans * base) % mod;
    return ans % mod;
}

 st nums[5010];
int scheme[30];
set<char> letters;
int dp[5010];
int cnt[5010];
vector<long long> letCnt;
vector<long long> groupCnt;
int main()
{
    int n, m, k;
    long long ans = 1;
    char c;
    fin >> n >> m >> k;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].sy >> nums[i].group;
    for(int i = 0; i < m; i ++)
    {
        fin >> c;
        scheme[c - 'A'] ++;
        letters.insert(c);
    }
    dp[0] = 1;
    for(int i = 0; i <= k; i ++)
        for(int j = 0; j < n; j ++)
            if(i + nums[j].sy <= k)
                dp[i + nums[j].sy] = (dp[i + nums[j].sy] + dp[i]) % mod;
    for(int i = 0; i < n; i ++)
        cnt[nums[i].group] = (cnt[nums[i].group] + dp[k - nums[i].sy]) % mod;
    for(set<char>::iterator it = letters.begin(); it != letters.end(); ++ it)
        letCnt.push_back(scheme[*it - 'A']);
    for(int i = 0; i <= n; i ++)
        if(cnt[i] != 0)
            groupCnt.push_back(cnt[i]);
    for(int i = 0; i < letCnt.size(); i ++)
    {
        long long cur = 0;
        for(int j = 0; j < groupCnt.size(); j ++)
            cur = (cur + exp(groupCnt[j], letCnt[i]) + mod) % mod;
        ans = (ans * cur + mod) % mod;
    }
    fout << ans << "\n";
}
