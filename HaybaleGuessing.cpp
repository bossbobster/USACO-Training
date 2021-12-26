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

struct query
{
    int l, r, a;
    const bool operator<(const query& other) const
    {
        return a < other.a;
    }
    const bool operator>(const query& other) const
    {
        return a > other.a;
    }
};

int n, q;
query og[25010];
vector<query> qs;
bitset<4000010> seg;
bitset<4000010> lazy;
void updateRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        seg[node] = 1;
        if(l != r)
        {
            lazy[node*2+1] = 1;
            lazy[node*2+2] = 1;
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[node] = 1;
        if(l != r)
        {
            lazy[node*2+1] = 1;
            lazy[node*2+2] = 1;
        }
        return;
    }
    int mid = (l+r)/2;
    updateRec(node*2+1, l, mid, lq, rq); updateRec(node*2+2, mid+1, r, lq, rq);
    seg[node] = seg[node*2+1] & seg[node*2+2];
}
void update(int lq, int rq) { updateRec(0, 0, n-1, lq, rq); }
bool minRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        seg[node] = 1;
        if(l != r)
        {
            lazy[node*2+1] = 1;
            lazy[node*2+2] = 1;
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return true;
    if(l >= lq && r <= rq)
        return seg[node];
    int mid = (l+r)/2;
    return minRec(node*2+1, l, mid, lq, rq) & minRec(node*2+2, mid+1, r, lq, rq);
}
int minQ(int lq, int rq) { return minRec(0, 0, n-1, lq, rq); }
int bs(int l, int r)
{
    int mid = (l+r)/2, lq, rq, idx;
    qs.clear();
    if(l >= r) return mid;
    for(int i = 0; i <= mid; i ++)
        qs.push_back(og[i]);
    sort(qs.begin(), qs.end(), greater<query>()); //easier to process them in decreasing order of A
    seg.reset(); lazy.reset();
    bool good = true;
    for(int i = 0; i < qs.size(); i ++)
    {
        lq = qs[i].l; rq = qs[i].r;
        idx = i;
        while(++idx < qs.size() && qs[idx].a == qs[i].a)
            lq = max(lq, qs[idx].l), rq = min(rq, qs[idx].r);
        if(lq > rq || minQ(lq, rq)) { good = false; break; }
        for(int j = i; j < idx; j ++) update(qs[j].l, qs[j].r);
        i = idx-1;
    }
    if(good) return bs(mid+1, r);
    return bs(l, mid);
}
int main()
{
    input();
    cin >> n >> q;
    for(int i = 0; i < q; i ++)
        cin >> og[i].l >> og[i].r >> og[i].a, og[i].l--, og[i].r--;
    int ans = bs(1, q);
    cout << ((ans==q)?0:ans+1) << '\n';
}
