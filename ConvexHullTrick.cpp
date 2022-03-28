//This is the implementation for the following problem: https://codeforces.com/contest/1083/problem/E
//which is a simple example of the Convex Hull Trick

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

struct rect
{
    ll x, y, a;
    const bool operator<(const rect& other) const
    {
        return x < other.x;
    }
};
struct line
{
    ll m, b;
};
deque<line> dq;
rect all[1000010];
ll dp[1000010];
double inter(line l1, line l2)
{
    return ((double)(l1.b-l2.b))/((double)(l2.m-l1.m));
}
ll query(ll x)
{
    while(dq.size() > 1 && x*dq.back().m+dq.back().b < x*dq[dq.size()-2].m+dq[dq.size()-2].b) dq.pop_back();
    if(dq.empty()) return 0;
    return max(0LL, x*dq.back().m+dq.back().b);
}
void insert(int idx)
{
    ll m = -all[idx].x, b = dp[idx];
    while(dq.size() > 1 && inter(dq.front(), dq[1]) < inter(dq.front(), {m, b})) dq.pop_front();
    dq.push_front({m, b});
}
int main()
{
    input();
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> all[i].x >> all[i].y >> all[i].a;
    sort(all, all+n);
    for(int i = 0; i < n; i ++)
    {
        dp[i] = all[i].x*all[i].y-all[i].a+query(all[i].y);
        ans = max(ans, dp[i]);
        insert(i);
    }
    cout << ans << '\n';
}
