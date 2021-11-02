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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
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
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
const int sz = 1000001;
const ld eps = 0.000000000001;
ll speed[100010], bit[1000010];
pair<pair<ld, ll>, ld> lap[100010];
ll sum(int idx)
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
void update(int idx, ll val)
{
    idx ++;
    while(idx <= sz)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
int main()
{
    input();
    ld l, c, mx = 0, t;
    ll ans = 0, cur = -1;
    cin >> n >> l >> c;
    for(int i = 0; i < n; i ++)
        cin >> speed[i], mx = max(mx, (ld)speed[i]);
    t = l*c/mx;
    for(int i = 0; i < n; i ++)
        lap[i] = {{speed[i]*t/c - (int)(speed[i]*t/c), 0}, (int)(speed[i]*t/c)};
    sort(lap, lap+n);
    for(int i = 0; i < n; i ++)
    {
        if(i != 0 && abs(lap[i].f.f-lap[i-1].f.f) < eps)
            lap[i].f.s = cur;
        else
            lap[i].f.s = ++cur;
    }
    for(int i = 0; i < n; i ++)
        swap(lap[i].f.f, lap[i].s);
    sort(lap, lap+n);
    cur = 0;
    for(ll i = 0; i < n; i ++)
    {
        ans += i*lap[i].f.f - cur - i + sum(lap[i].f.s);
        cur += lap[i].f.f;
        update(lap[i].f.s, 1);
    }
    cout << ans << '\n';
}
