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
#include <chrono>
#include <type_traits>
#include <stdexcept>
#include <regex>
#include <numeric>
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
#define pi 3.14159265358979323846
//#define cin fin
//#define cout fout
//#define fin cin
//#define fout cout
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#pragma GCC target("avx2") // remember to remove if runtime error
//#pragma GCC ivdep // only add this if nothing else works (since it might break stuff)

/*

     ._________.
     |_________|
   ---------------
  |_____• U •_____|
 -------------------
|___________________|


 */

vector<pil> adj[400010]; // make the max N here be 3 * (smallest power of 2 >= N)
ll len[400010];
priority_queue<pli, vector<pli>, greater<pli>> pq;
int n, bt;
int ff[20];
vector<int> get(int l, int r)
{
    vector<int> ans;
    while(l <= r)
    {
        bt = (l&(-l)); // smallest bit in l
        if(!bt) bt = n;
        bt = min((31-__builtin_clz(bt)), (31-__builtin_clz(r-l+1)));
        ans.push_back(ff[bt]+l/(1<<bt));
        l += (1<<bt);
    }
    return ans;
}
void up(int lf, int rf, int lt, int rt, ll w)
{
    vector<int> fr = get(lf, rf), to = get(lt, rt);
    for(int i = 0; i < fr.size(); i ++)
        if(fr[i] >= n)
            fr[i] += n-1;
    for(auto it : fr)
        for(auto it2 : to)
            adj[it].push_back({it2, w});
}
int main()
{
    int q, ss, num, t, a, b, c, d, ogn;
    cin >> n >> q >> ss; ss--; ogn = n;
    if((n&(n-1))) n = (int)(0x80000000>>(__builtin_clz(n)-1)); // set n to (smallest power of 2 >= n)
    int pw = (31-__builtin_clz(n));
    ff[0] = 0; num = n;
    for(int i = 1; i <= pw; i ++)
        ff[i] = ff[i-1]+num, num >>= 1;
    for(int i = 0; i < pw; i ++) // adding 0 edges
    {
        int nn = ff[i]+(n/(1<<i)), nx = ff[i+1], jj;
        for(int j = ff[i]; j < nn; j += 2)
        {
            jj = ((j<n)?j:(j+n-1));
            adj[jj].push_back({nx+n-1, 0}); adj[jj+1].push_back({nx+n-1, 0});
            adj[nx].push_back({j, 0}); adj[nx].push_back({j+1, 0});
            nx ++;
        }
    }
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> a >> b >> c; a--; b--;
            up(a, a, b, b, c);
        }
        else if(t == 2)
        {
            cin >> a >> b >> c >> d; a--; b--; c--;
            up(a, a, b, c, d);
        }
        else
        {
            cin >> a >> b >> c >> d; a--; b--; c--;
            up(b, c, a, a, d);
        }
    }
    pli cur;
    for(int i = 0; i < n*3; i ++)
        len[i] = 2e18;
    len[ss] = 0;
    pq.push({0, ss});
    while(!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if(len[cur.s] < cur.f) continue;
        for(auto it : adj[cur.s])
            if(cur.f+it.s < len[it.f])
            {
                len[it.f] = cur.f+it.s;
                pq.push({len[it.f], it.f});
            }
    }
    for(int i = 0; i < ogn; i ++)
        cout << ((len[i]==2e18)?-1:len[i]) << ((i==ogn-1)?'\n':' ');
}
