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
//template <class T> using Tree = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
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

ifstream fin("balance.in");
ofstream fout("balance.out");

struct pt
{
    ll x, y;
    bool operator<(const pt& p1) const
    {
        if(p1.x == x) return y < p1.y;
        return x < p1.x;
    }
    const bool operator<=(const pt& other) const
    {
        if(x == other.x) return y <= other.y;
        return x <= other.x;
    }
    const bool operator>=(const pt& other) const
    {
        if(x == other.x) return y >= other.y;
        return x >= other.x;
    }
};
ld cp(pt p1, pt p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
int ccw(pt p1, pt p2, pt p3)
{
    pt p4 = {p2.x - p1.x, p2.y - p1.y};
    pt p5 = {p3.x - p1.x, p3.y - p1.y};
    if(cp(p4, p5) < 0) return -1; // cw
    else if(cp(p4, p5) == 0) return 0;
    return 1; // ccw
}
pt nums[100010];
vector<pt> upper;
plld slope[100010];
int main()
{
    input();
    int n;
    fin >> n;
    nums[0] = {0, 0};
    for(int i = 1; i <= n; i ++)
        fin >> nums[i].y, nums[i].x = i;
    nums[n+1] = {n+1, 0};
    for(int i = 0; i <= n+1; i ++)
    {
        while(upper.size() >= 2 && ccw(upper[upper.size() - 2], upper[upper.size() - 1], nums[i]) != -1)
            upper.pop_back();
        upper.push_back(nums[i]);
    }
    for(int i = 0; i < upper.size()-1; i ++)
    {
        slope[i].f = {(upper[i+1].y-upper[i].y), (upper[i+1].x-upper[i].x)};
        slope[i].s = (upper[i].y*100000LL-(upper[i].x*100000LL*(ld)slope[i].f.f/(ld)slope[i].f.s));
    }
    int idx = 0;
    for(ll i = 1; i <= n; i ++)
    {
        while(idx < upper.size() && upper[idx+1].x <= i) idx ++;
        fout << (ull)((ld)(slope[idx].f.f * i * 100000LL) / (ld)slope[idx].f.s + slope[idx].s) << '\n';
    }
}
