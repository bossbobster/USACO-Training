#include <iostream>
#include <string.h>
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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input(x) ios_base::sync_with_stdio(x); cin.tie(x);

ifstream fin("seating.in");
ofstream fout("seating.out");

int n, m, need, good;
int nums[500010];
pii seg[2000010], lazy[2000010];
void updateRec(int node, int l, int r, int lq, int rq, int val, int idx)
{
    if(lazy[node].f != -1)
    {
        seg[node] = lazy[node];
        if(l != r)
        {
            lazy[node * 2 + 1] = lazy[node];
            lazy[node * 2 + 2] = lazy[node];
        }
        lazy[node] = {-1, 0};
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[node] = {val, idx};
        if(l != r)
        {
            lazy[node * 2 + 1] = {val, idx};
            lazy[node * 2 + 2] = {val, idx};
        }
        return;
    }
    int mid = (l + r) / 2;
    updateRec(node * 2 + 1, l, mid, lq, rq, val, idx);
    updateRec(node * 2 + 2, mid + 1, r, lq, rq, val, idx);
    seg[node] = max(seg[node * 2 + 1], seg[node * 2 + 2]);
}
void update(int lq, int rq, int val, int idx, int n) { updateRec(0, 0, n - 1, lq, rq, val, idx); }
pii maxRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node].first != -1)
    {
        seg[node] = lazy[node];
        if(l != r)
        {
            lazy[node * 2 + 1] = lazy[node];
            lazy[node * 2 + 2] = lazy[node];
        }
        lazy[node] = {-1, 0};
    }
    if(l > rq || r < lq || l > r) return {-200000, -2000000};
    if(l >= lq && r <= rq)
        return seg[node];
    int mid = (l + r) / 2;
    return max(maxRec(node * 2 + 1, l, mid, lq, rq), maxRec(node * 2 + 2, mid + 1, r, lq, rq));
}
pii mx(int lq, int rq, int n)
{
    if(lq < 0 || rq >= n || lq > rq) return {0, 0};
    return maxRec(0, 0, n-1, lq, rq);
}
void makeRec(int node, int l, int r)
{
    if(l > r) return;
    if(l == r) { seg[node] = {nums[l], l}; return; }
    int mid = (l + r) / 2;
    makeRec(node * 2 + 1, l, mid);
    makeRec(node * 2 + 2, mid + 1, r);
    seg[node] = max(seg[node * 2 + 1], seg[node * 2 + 2]);
}
void make(int n) { makeRec(0, 0, n-1); }
void bs(int node, int l, int r)
{
    if(lazy[node].first != -1)
    {
        seg[node] = lazy[node];
        if(l != r)
        {
            lazy[node * 2 + 1] = lazy[node];
            lazy[node * 2 + 2] = lazy[node];
        }
        lazy[node] = {-1, 0};
    }
    if(seg[node].f < need || good < l) return;
    int mid = (l+r)/2;
    if(l==r) { good = l; return; }
    bs(node*2+1, l, mid); bs(node*2+2, mid+1, r);
}
int main()
{
    int a, b, ans = 0, l, sz;
    char type;
    input(0);
    fin >> n >> m;
    nums[0] = n;
    make(n-1);
    for(int i = 0; i < 2000010; i ++) lazy[i] = {-1, 0};
    while(m--)
    {
        fin >> type;
        if(type == 'A')
        {
            fin >> a;
            need = a; good = n;
            bs(0, 0, n-1);
            ans += (good==n);
            if(good!=n)
            {
                pii tmp = mx(good, good, n);
                if(good+a < n && good+tmp.first-1 >= good+a) update(good+a, good+tmp.f-1, tmp.f-a, good+a, n);
                update(good, good+a-1, 0, 0, n);
            }
        }
        else
        {
            fin >> a >> b; a--; b--;
            pii tmp = mx(a-1, a-1, n);
            if(tmp.first > 0) l = tmp.second;
            else l = a;
            tmp = mx(b+1, b+1, n);
            if(tmp.first > 0) sz = tmp.first + tmp.second - l;
            else sz = b - l + 1;
            update(l, l+sz-1, sz, l, n);
        }
    }
    fout << ans << "\n";
}
