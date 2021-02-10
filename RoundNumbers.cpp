#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int dp[110][110];
vector<pii> line;
int cnt;
string decToBin(int n)
{
    string ans = "";
    while(n > 0)
    {
        ans += to_string(n % 2);
        n /= 2;
    }
    for(int i = 0; i < ans.length() / 2; i ++)
        swap(ans[i], ans[ans.length() - i - 1]);
    return ans;
}
int roundTo(int n)
{
    if(n <= 1) return 1;
    int ans = 0;
    for(int i = 0; i < 100; i ++)
        for(int j = 0; j < 100; j ++)
            dp[i][j] = 0;
    string mx = decToBin(n);
    dp[1][0] = dp[1][1] = 1;
    for(int i = 1; i < max(1, mx.length() - 1); i ++)
        for(int j = 0; j < i; j ++)
        {
            dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j] += dp[i][j];
        }
    cnt = 0;
    line.clear();
    for(int i = 1; i < mx.length(); i ++)
    {
        if(mx[i] == '1')
            line.push_back({mx.length() - i - 1, cnt + 1});
        else
            cnt ++;
    }
    for(int i = 1; i <= mx.length(); i ++)
        for(int j = ceil((double)i / 2.0); j < mx.length(); j ++)
            ans += dp[i][j];
    for(int i = 0; i < line.size(); i ++)
    {
        for(int k = line[i].f; k >= 1; k --)
        {
            for(int j = 0; j < k; j ++)
                if((j + line[i].s) * 2 >= mx.length())
                    ans += dp[k][j];
            line[i].s ++;
        }
        if(line[i].s * 2 >= mx.length()) ans ++;
    }
    cnt = 0;
    for(int i = 0; i < mx.length(); i ++)
        if(mx[i] == '0')
            cnt ++;
    if(cnt * 2 >= mx.length()) ans ++;
    return ans;
}
int main()
{
    int st, en;
    cin >> st >> en;
    cout << roundTo(en) - roundTo(st - 1) << "\n";
}
