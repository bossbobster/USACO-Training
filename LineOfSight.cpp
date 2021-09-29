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

ifstream fin("sight.in");
ofstream fout("sight.out");

const ld pi = 3.1415926535897932384626433;
int n;
ld r;
pld nums[50010];
ld dist(pld p)
{
    return sqrt(p.f * p.f + p.s * p.s);
}
pld tans[50010], tana[50010];
int main()
{
    ll ans = 0, num;
    ld a, b;
    fin >> n >> r;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].f >> nums[i].s;
    for(int i = 0; i < n; i ++)
    {
        tans[i] = {atan2(nums[i].s, nums[i].f)+acos(r/dist(nums[i])), atan2(nums[i].s, nums[i].f)-acos(r/dist(nums[i]))};
        if(tans[i].f > pi) tans[i].f -= 2*pi;
        if(tans[i].s < -pi) tans[i].s += 2*pi;
        tana[i] = {tans[i].s, tans[i].f};
    }
    sort(tans, tans+n); sort(tana, tana+n);
    for(int i = 0; i < n; i ++)
    {
        a = tana[i].s; b = tana[i].f;
        if(a > b) swap(a, b);
        num = lower_bound(tans, tans+n, pld(b, 1000)) - lower_bound(tans, tans+n, pld(a, -1000));
        if(abs(a-b) > pi) num = n-num;
        else num--;
        ans += num;
    }
    fout << ans << '\n';
}
