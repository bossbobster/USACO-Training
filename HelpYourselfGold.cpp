#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("help.in");
ofstream fout("help.out");

int mod = 1000000007;
pii nums[100010];
int pows[100010];
int pre[200010];
int main()
{
    int n, ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].first >> nums[i].second;
    pows[0] = 1;
    for(int i = 1; i < n; i ++)
        pows[i] = pows[i - 1] * 2 % mod;
    for(int i = 0; i < n; i ++)
    {
        pre[nums[i].first] ++;
        pre[nums[i].second] --;
    }
    for(int i = 2; i < 2 * n + 1; i ++)
        pre[i] += pre[i - 1];
    for(int i = 0; i < n; i ++)
        ans = (ans + pows[n - 1 - pre[nums[i].first - 1]]) % mod;
    fout << ans << "\n";
}
