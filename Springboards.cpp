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

ifstream fin("boards.in");
ofstream fout("boards.out");

struct pt
{
    ll x, y, idx, type;
    const bool operator<(const pt& other) const
    {
        if(x == other.x)
        {
            if(y == other.y) return type > other.type;
            return y < other.y;
        }
        return x < other.x;
    }
};
int n, p;
pt nums[200010];
pll tree[800010];
vector<ll> v;
void update(int l, int r, int curIdx, ll upIdx, ll val, ll id)
{
    if(l == r)
    {
        tree[curIdx] = min(tree[curIdx], {val, id});
        return;
    }
    int mid = (l+r)/2;
    if(upIdx >= v[l] && upIdx <= v[mid])
        update(l, mid, curIdx*2+1, upIdx, val, id);
    else
        update(mid+1, r, curIdx*2+2, upIdx, val, id);
    tree[curIdx] = min(tree[curIdx*2+1], tree[curIdx*2+2]);
}
pll minQ(int l, int r, int lq, ll rq, int curIdx)
{
    if(v[r] < lq || v[l] > rq)
        return {200000000000010, 200000000000010};
    if(lq <= v[l] && rq >= v[r])
        return tree[curIdx];
    int mid = (l+r)/2;
    return min(minQ(l, mid, lq, rq, curIdx*2+1), minQ(mid+1, r, lq, rq, curIdx*2+2));
}
ll ans[100010];
int main()
{
    input();
    fin >> n >> p;
    for(int i = 0; i < p; i ++)
    {
        fin >> nums[i*2].x >> nums[i*2].y >> nums[i*2+1].x >> nums[i*2+1].y;
        nums[i*2].idx = i; nums[i*2+1].idx = i; nums[i*2].type = 0; nums[i*2+1].type = 1;
    }
    sort(nums, nums+2*p);
    v.push_back(0);
    for(int i = 0; i < 2*p; i ++)
        v.push_back(nums[i].y);
    v.push_back(n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < 800010; i ++)
        tree[i] = {200000000010, 200000000010};
    update(0, (int)v.size()-1, 0, 0, 2*n, -1);
    for(int i = 0; i < 2*p; i ++)
    {
        if(nums[i].type == 0)
        {
            pll pp = minQ(0, (int)v.size()-1, 0, nums[i].y, 0);
            if(pp.s == -1) ans[nums[i].idx] = nums[i].x+nums[i].y;
            else ans[nums[i].idx] = ans[nums[pp.s].idx]-nums[pp.s].y-nums[pp.s].x+nums[i].x+nums[i].y;
            if(ans[nums[i].idx] < 0)
                cout << "hi";
        }
        else
            update(0, (int)v.size()-1, 0, nums[i].y, 2*n-nums[i].x-nums[i].y+ans[nums[i].idx], i);
    }
    pll pp = minQ(0, (int)v.size()-1, 0, n, 0);
    fout << pp.f << '\n';
}
