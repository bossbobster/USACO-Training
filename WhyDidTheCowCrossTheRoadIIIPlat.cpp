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
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

ifstream fin("friendcross.in");
ofstream fout("friendcross.out");

int nums[2][100010];
int idx[100010];
vector<int> bit[100010];
int n, k, i, j;
ll ans = 0;
vector<int> v[100010];
void update(int x, int y)
{
    x++;
    int idx;
    for(i = x; i <= n; i += (i & (-i)))
    {
        idx = (int)(upper_bound(v[i].begin(), v[i].end(), y)-v[i].begin());
        for(j = idx; j < bit[i].size(); j += (j & (-j)))
            bit[i][j] ++;
    }
}
int sumUtil(int x, int y)
{
    int ans = 0; x++;
    int idx;
    for(i = x; i > 0; i -= (i & (-i)))
    {
        idx = (int)(upper_bound(v[i].begin(), v[i].end(), y)-v[i].begin());
        for(j = idx; j > 0; j -= (j & (-j)))
            ans += bit[i][j];
    }
    return ans;
}
int sum(int x1, int y1, int x2, int y2)
{
    return sumUtil(x2, y2) - sumUtil(x1-1, y2) - sumUtil(x2, y1-1) + sumUtil(x1-1, y1-1);
}
int main()
{
    input();
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
        fin >> nums[0][i], nums[0][i]--;
    for(int i = 0; i < n; i ++)
        fin >> nums[1][i], nums[1][i]--, idx[nums[1][i]] = i;
    for(int i = 0; i < n; i ++)
        for(int j = nums[0][i]+1; j <= n; j += (j & (-j)))
            v[j].push_back(idx[nums[0][i]]);
    for(int i = 0; i <= n; i ++)
        sort(v[i].begin(), v[i].end()), bit[i].resize(v[i].size()+1);
    for(int i = 0; i < n; i ++)
    {
        update(nums[0][i], idx[nums[0][i]]);
        if(nums[0][i]-k-1 >= 0)
            ans += sum(0, idx[nums[0][i]], nums[0][i]-k-1, n-1);
        if(nums[0][i]+k+1 < n)
            ans += sum(nums[0][i]+k+1, idx[nums[0][i]], n-1, n-1);
    }
    fout << ans << '\n';
}
