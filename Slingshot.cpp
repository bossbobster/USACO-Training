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
typedef pair<uint, uint> puint;
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
//#define cout fout

ifstream fin("slingshot.in");
ofstream fout("slingshot.out");

const ll inf = 2000000000000000000;
struct sling
{
    ll x, y, d;
    const bool operator<(const sling& other) const
    {
        return x < other.x;
    }
};
struct query
{
    ll x, y;
    int id;
    const bool operator<(const query& other) const
    {
        return x < other.x;
    }
};
sling nums[100010];
query qs[100010];
set<ll> all;
vector<ll> v;
vector<ll> seg[4][200010];
inline ll mnV(vector<ll>& v)
{
    ll ans = inf;
    for(ll it : v)
        ans = min(ans, it);
    return ans;
}
void update(int which, int idx, ll val)
{
    idx = (int)(lower_bound(v.begin(), v.end(), idx)-v.begin()+v.size());
    if(val >= inf/10)
    {
        for(int i = 0; i < seg[which][idx].size(); i ++)
            if(seg[which][idx][i] == val-inf)
            {
                seg[which][idx].erase(seg[which][idx].begin()+i);
                break;
            }
    }
    else seg[which][idx].push_back(val);
    for(int i = idx; i > 1; i >>= 1)
    {
        if(mnV(seg[which][i]) < mnV(seg[which][i^1])) seg[which][i>>1] = seg[which][i];
        else seg[which][i>>1] = seg[which][i^1];
    }
}
ll minQ(int which, int l, int r) // inclusive l, exclusive r
{
    ll ans = inf;
    l = (int)(lower_bound(v.begin(), v.end(), l)-v.begin()); r = (int)(upper_bound(v.begin(), v.end(), r)-v.begin());
    for(l += (int)v.size(), r += (int)v.size(); l < r; l >>= 1, r >>= 1)
    {
        if(l&1)
            ans = min(ans, mnV(seg[which][l])), l++;
        if(r&1)
            r--, ans = min(ans, mnV(seg[which][r]));
    }
    return ans;
}
ll ans[100010];
int main()
{
    int n, m;
    input();
    fin >> n >> m;
    int idx = 0;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].x >> nums[i].y >> nums[i].d;
    for(int i = 0; i < m; i ++)
        fin >> qs[i].x >> qs[i].y, qs[i].id = i;
    for(int cnt = 0; cnt < 2; cnt ++)
    {
        all.clear(); v.clear();
        for(int i = 0; i < n; i ++)
            all.insert(nums[i].y);
        for(auto it : all)
            v.push_back(it);
        sort(qs, qs+m); sort(nums, nums+n);
        for(int i = 0; i < 200010; i ++)
            for(int j = 0; j < 4; j ++)
                seg[j][i].clear(), seg[j][i].push_back(inf);
        idx = 0;
        for(int i = 0; i < n; i ++)
        {
            if(nums[i].x > nums[i].y) continue;
            if(nums[i].x <= qs[0].x)
            {
                idx = i+1;
                update(0, (int)nums[i].y, -nums[i].x-nums[i].y+nums[i].d);
                update(1, (int)nums[i].y, -nums[i].x+nums[i].y+nums[i].d);
            }
            else
            {
                update(2, (int)nums[i].y, nums[i].x-nums[i].y+nums[i].d);
                update(3, (int)nums[i].y, nums[i].x+nums[i].y+nums[i].d);
            }
        }
        ll pl1, pl2, pr1, pr2;
        for(int i = 0; i < m; i ++)
        {
            if(qs[i].x > qs[i].y) continue;
            while(idx < n && (nums[idx].x <= qs[i].x || nums[idx].x > nums[idx].y))
            {
                if(nums[idx].x > nums[idx].y) { idx++; continue; }
                update(0, (int)nums[idx].y, -nums[idx].x-nums[idx].y+nums[idx].d);
                update(1, (int)nums[idx].y, -nums[idx].x+nums[idx].y+nums[idx].d);
                update(2, (int)nums[idx].y, inf+nums[idx].x-nums[idx].y+nums[idx].d);
                update(3, (int)nums[idx].y, inf+nums[idx].x+nums[idx].y+nums[idx].d);
                idx ++;
            }
            pl1 = minQ(0, 0, (int)qs[i].y); pl2 = minQ(1, (int)qs[i].y, 2000000000);
            pr1 = minQ(2, 0, (int)qs[i].y); pr2 = minQ(3, (int)qs[i].y, 2000000000);
            ans[qs[i].id] = min({qs[i].y-qs[i].x, qs[i].x+qs[i].y+pl1, qs[i].x-qs[i].y+pl2, -qs[i].x+qs[i].y+pr1, -qs[i].x-qs[i].y+pr2});
        }
        for(int i = 0; i < n; i ++)
            swap(nums[i].x, nums[i].y);
        for(int i = 0; i < m; i ++)
            swap(qs[i].x, qs[i].y);
    }
    for(int i = 0; i < m; i ++)
        fout << ans[i] << '\n';
}
