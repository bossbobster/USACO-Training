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

int n, m;
int seg[1000010];
bitset<1000010> lazy;
void updateRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        seg[node] = r-l+1 - seg[node];
        if(l != r)
            lazy[node*2+1] = !lazy[node*2+1], lazy[node*2+2] = !lazy[node*2+2];
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[node] = r-l+1 - seg[node];
        if(l != r)
            lazy[node*2+1] = !lazy[node*2+1], lazy[node*2+2] = !lazy[node*2+2];
        return;
    }
    int mid = (l+r)/2;
    updateRec(node*2+1, l, mid, lq, rq);
    updateRec(node*2+2, mid+1, r, lq, rq);
    seg[node] = seg[node*2+1] + seg[node*2+2];
}
void update(int lq, int rq) { updateRec(0, 0, n-1, lq, rq); }
int sumRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        seg[node] = r-l+1 - seg[node];
        if(l != r)
            lazy[node*2+1] = !lazy[node*2+1], lazy[node*2+2] = !lazy[node*2+2];
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[node];
    int mid = (l+r)/2;
    return sumRec(node*2+1, l, mid, lq, rq) + sumRec(node*2+2, mid+1, r, lq, rq);
}
int sum(int lq, int rq) { return sumRec(0, 0, n-1, lq, rq); }
int main()
{
    input();
    int type, a, b;
    cin >> n >> m;
    while(m--)
    {
        cin >> type >> a >> b; a--; b--;
        if(type == 0)
            update(a, b);
        else
            cout << sum(a, b) << '\n';
    }
}
