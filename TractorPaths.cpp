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
typedef pair<pis, string> piss;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
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
typedef pair<ld, int> pldi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define eps 1e-8
//#define eps2 1e-15
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
//#define cin fin
//#define cout fout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

int n, q;
int which[400010];
pii nums[200010];
int first[200010], last[200010], nextL[200010], prevL[200010], revF[200010], pre[200010];
pair<int, ll> binr[200010][20], binl[200010][20];
int main()
{
    input();
    cin >> n >> q;
    string st, st2;
    cin >> st >> st2;
    int idx1 = 0, idx2 = 0, ii = 0, a, b;
    int prL = -1;
    pre[0] = 0;
    for(int i = 1; i <= n; i ++)
        pre[i] = pre[i-1]+((st2[i-1]=='1')?1:0);
    for(auto it : st)
    {
        if(it == 'L')
        {
            nums[idx1].f = ii, which[ii] = idx1++;
            if(prL != -1)
            {
                nextL[prL] = ii;
                prevL[ii] = prL;
            }
            prL = ii;
        }
        else
        {
            prevL[ii] = prL;
            nums[idx2].s = ii, which[ii] = idx2++;
        }
        ii++;
    }
    int ls = 1;
    for(int i = 0; i < n-1; i ++)
    {
        first[i] = which[nextL[nums[i].f]];
        last[i] = which[prevL[nums[i].s]];
        while(last[i] >= ls)
            revF[ls++] = i;
    }
    last[n-1] = n-1;
    revF[0] = 0;
    for(int i = 0; i < n; i ++)
        binr[i][0] = {last[i], pre[last[i]+1]};
    for(int i = 1; i < 20; i ++)
        for(int j = 0; j < n; j ++)
            binr[j][i] = {binr[binr[j][i-1].f][i-1].f, binr[j][i-1].s+binr[binr[j][i-1].f][i-1].s};
    for(int i = 0; i < n; i ++)
        binl[i][0] = {revF[i], -pre[revF[i]]};
    for(int i = 1; i < 20; i ++)
        for(int j = 0; j < n; j ++)
            binl[j][i] = {binl[binl[j][i-1].f][i-1].f, binl[j][i-1].s+binl[binl[j][i-1].f][i-1].s};
    while(q--)
    {
        cin >> a >> b; a--; b--;
        int aa = a, bb = b;
        int pw = 19, ans1 = 0;
        ll ans2 = pre[b+1]-pre[b]+pre[a+1]-pre[a];
        while(pw >= 0)
        {
            if(binr[aa][pw].f < b)
            {
                ans1 += (1<<pw);
                ans2 += binr[aa][pw].s;
                aa = binr[aa][pw].f;
            }
            pw--;
        }
        cout << ans1+1 << ' ';
        pw = 19;
        while(pw >= 0)
        {
            if(binl[bb][pw].f > a)
            {
                ans2 += binl[bb][pw].s;
                bb = binl[bb][pw].f;
            }
            pw--;
        }
        cout << ans2 << '\n';
    }
}
