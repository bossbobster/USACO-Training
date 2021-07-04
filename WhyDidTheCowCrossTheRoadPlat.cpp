#include <iostream>
#include <string.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ifstream fin("mincross.in");
ofstream fout("mincross.out");

int n;
ll cur = 0, ans = 0;
ll nums[2][100010];
ll idx[2][100010];
ll bit[100010];
ll sum(ll idx)
{
    ll ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(ll idx, ll val)
{
    idx ++;
    while(idx <= n+1)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
int main()
{
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[0][i];
        idx[0][nums[0][i]] = i;
    }
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[1][i];
        idx[1][nums[1][i]] = i;
    }
    for(int i = 0; i < n; i ++)
    {
        cur += sum(n) - sum(idx[1][nums[0][i]]);
        update(idx[1][nums[0][i]], 1);
    }
    ans = cur;
    for(int i = n-1; i >= 0; i --)
    {
        cur -= n-idx[1][nums[0][i]]-1;
        cur += idx[1][nums[0][i]];
        ans = min(ans, cur);
    }
    for(int i = n-1; i >= 0; i --)
    {
        cur -= n-idx[0][nums[1][i]]-1;
        cur += idx[0][nums[1][i]];
        ans = min(ans, cur);
    }
    fout << ans << "\n";
}
