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

ifstream fin("mowing.in");
ofstream fout("mowing.out");

pii nums[100010];
int idx[100010];
vector<int> bit[2][300010];
int n, t, i, j;
ll ans = 0;
vector<int> v[2][300010];
bitset<100010> wc; // 1 is vertical, 0 is horizontal
int curIdx = 1;
void update(int which, int x, int y, int val)
{
    x++;
    int idx;
    for(i = x; i <= curIdx; i += (i & (-i)))
    {
        idx = (int)(upper_bound(v[which][i].begin(), v[which][i].end(), y)-v[which][i].begin());
        for(j = idx; j < bit[which][i].size(); j += (j & (-j)))
            bit[which][i][j] += val;
    }
}
int sumUtil(int which, int x, int y)
{
    int ans = 0; x++;
    int idx;
    for(i = x; i > 0; i -= (i & (-i)))
    {
        idx = (int)(upper_bound(v[which][i].begin(), v[which][i].end(), y)-v[which][i].begin());
        for(j = idx; j > 0; j -= (j & (-j)))
            ans += bit[which][i][j];
    }
    return ans;
}
int sum(int which, int x1, int y1, int x2, int y2)
{
    return sumUtil(which, x2, y2) - sumUtil(which, x1-1, y2) - sumUtil(which, x2, y1-1) + sumUtil(which, x1-1, y1-1);
}
int dist[100010];
set<int> all;
unordered_map<int, int> hsh;
int main()
{
    input();
    fin >> n >> t;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].f >> nums[i].s;
    if(nums[0].f == nums[1].f) wc[0] = 1;
    for(int i = 1; i < n; i ++)
        wc[i] = !wc[i-1];
    for(int i = 0; i < n-1; i ++)
        dist[i] = (wc[i]?nums[i+1].s-nums[i].s:nums[i+1].f-nums[i].f);
    for(int i = 0; i < n-1; i ++)
    {
        if(wc[i])
        {
            if(dist[i] < -1)
                all.insert(nums[i].f), all.insert(nums[i].s), all.insert(nums[i+1].s+1);
            else if(dist[i] > 1)
                all.insert(nums[i].f), all.insert(nums[i].s+1), all.insert(nums[i+1].s);
        }
        else
        {
            if(dist[i] < -1)
                all.insert(nums[i].s), all.insert(nums[i].f), all.insert(nums[i+1].f+1);
            else if(dist[i] > 1)
                all.insert(nums[i].s), all.insert(nums[i].f+1), all.insert(nums[i+1].f);
        }
    }
    for(auto it : all)
        hsh[it] = curIdx++;
    for(int i = 0; i < n-1; i ++)
    {
        if(wc[i])
        {
            if(dist[i] < -1)
                for(int j = hsh[nums[i].f]+1; j <= curIdx; j += (j & (-j)))
                    v[wc[i]][j].push_back(hsh[nums[i].s]), v[wc[i]][j].push_back(hsh[nums[i+1].s+1]);
            else if(dist[i] > 1)
                for(int j = hsh[nums[i].f]+1; j <= curIdx; j += (j & (-j)))
                    v[wc[i]][j].push_back(hsh[nums[i].s+1]), v[wc[i]][j].push_back(hsh[nums[i+1].s]);
        }
        else
        {
            if(dist[i] < -1)
                for(int j = hsh[nums[i].s]+1; j <= curIdx; j += (j & (-j)))
                    v[wc[i]][j].push_back(hsh[nums[i].f]), v[wc[i]][j].push_back(hsh[nums[i+1].f+1]);
            else if(dist[i] > 1)
                for(int j = hsh[nums[i].s]+1; j <= curIdx; j += (j & (-j)))
                    v[wc[i]][j].push_back(hsh[nums[i].f+1]), v[wc[i]][j].push_back(hsh[nums[i+1].f]);
        }
    }
    for(int which = 0; which < 2; which ++)
        for(int i = 1; i <= curIdx; i ++)
            sort(v[which][i].begin(), v[which][i].end()), v[which][i].erase(unique(v[which][i].begin(), v[which][i].end()), v[which][i].end()), bit[which][i].resize(v[which][i].size()+1);
    for(int i = t; i < n-1; i ++)
    {
        if(abs(dist[i-t]) > 1)
        {
            if(wc[i-t])
            {
                if(dist[i-t] < -1)
                    update(wc[i-t], hsh[nums[i-t].f], hsh[nums[i-t].s], -1), update(wc[i-t], hsh[nums[i-t].f], hsh[nums[i-t+1].s+1], 1);
                else
                    update(wc[i-t], hsh[nums[i-t].f], hsh[nums[i-t].s+1], 1), update(wc[i-t], hsh[nums[i-t].f], hsh[nums[i-t+1].s], -1);
            }
            else
            {
                if(dist[i-t] < -1)
                    update(wc[i-t], hsh[nums[i-t].s], hsh[nums[i-t].f], -1), update(wc[i-t], hsh[nums[i-t].s], hsh[nums[i-t+1].f+1], 1);
                else
                    update(wc[i-t], hsh[nums[i-t].s], hsh[nums[i-t].f+1], 1), update(wc[i-t], hsh[nums[i-t].s], hsh[nums[i-t+1].f], -1);
            }
        }
        if(abs(dist[i]) > 1)
        {
            if(!wc[i])
            {
                if(dist[i] < -1)
                    ans += sum(!wc[i], hsh[nums[i+1].f+1], 0, hsh[nums[i].f]-1, hsh[nums[i].s]);
                else
                    ans += sum(!wc[i], hsh[nums[i].f+1], 0, hsh[nums[i+1].f]-1, hsh[nums[i].s]);
            }
            else
            {
                if(dist[i] < -1)
                    ans += sum(!wc[i], hsh[nums[i+1].s+1], 0, hsh[nums[i].s]-1, hsh[nums[i].f]);
                else
                    ans += sum(!wc[i], hsh[nums[i].s+1], 0, hsh[nums[i+1].s]-1, hsh[nums[i].f]);
            }
        }
    }
    fout << ans << '\n';
}
