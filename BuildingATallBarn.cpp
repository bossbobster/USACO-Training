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
#include <array>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <memory>
#include <cassert>
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
typedef unsigned short ushort;
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
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
//#define cin fin
//#define cout fout

ifstream fin("tallbarn.in");
ofstream fout("tallbarn.out");

ll n, k;
double ans2 = 0;
ll nums[100010], ans[100010];
priority_queue<pair<double, int>> pq;

//for a specific nums[i] value and a penalty value, find how many cows we can add to reach that penalty
ll calc(double a, double num)
{
    return (ll)((sqrt(4*a/num+1)-1)/2.0)+1;
}
ll tot = 0;
void bs(double l, double r)
{
    double mid = (l+r)/2;
    if(abs(l-r) < 1e-12) return;
    tot = ans2 = 0;
    //mid represents the penalty until which we keep adding cows
    for(int i = 0; i < n; i ++)
        ans[i] = calc(nums[i], mid), tot += ans[i], ans2 += (double)(nums[i])/(ans[i]);
    if(tot >= k) return bs(mid, r);
    return bs(l+1e-12, mid);
}
int main()
{
    input();
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    bs(0, 1e15);
    for(int i = 0; i < n; i ++)
        pq.push({(double)nums[i]/ans[i]/(ans[i]+1), i});
    for(int i = 0; i < k-tot; i ++)
    {
        pair<double, int> p = pq.top();
        pq.pop();
        ans[p.s]++;
        pq.push({(double)nums[p.s]/ans[p.s]/(ans[p.s]+1), p.s});
    }
    ans2 = 0;
    for(int i = 0; i < n; i ++)
        ans2 += (double)nums[i]/ans[i];
    fout << (int)round(ans2) << '\n';
}
