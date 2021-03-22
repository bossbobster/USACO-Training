#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//ulng namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("haybales.in");
ofstream fout("haybales.out");

ll seg[1000010];
ll mn[1000010];
ll lazy[1000010];
ll nums[200010];
void updateRec(int node, int l, int r, int lq, int rq, ll val) //current node, left val of node, right val of node, left val of update range, right val of update range (inclusive of both), value to add to range
{
    if(lazy[node]) //if there is pending lazy update on this node
    {
        seg[node] += lazy[node] * (r - l + 1); mn[node] += lazy[node]; //update the range by adding val the correct amt of times
        if(l != r) //if not leaf node, store lazy updates for its children
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return; //if update range not in current nodes range, return
    if(l >= lq && r <= rq) //if current node range completely inside of update range, update all
    {
        seg[node] += val * (r - l + 1); mn[node] += val;
        if(l != r) //if not leaf node, store lazy updates for its children with the update value
        {
            lazy[node * 2 + 1] += val;
            lazy[node * 2 + 2] += val;
        }
        return;
    }
    int mid = (l + r) / 2; //if current node range and update range overlap, recurse to both children
    updateRec(node * 2 + 1, l, mid, lq, rq, val);
    updateRec(node * 2 + 2, mid + 1, r, lq, rq, val);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2]; //use children to update current
    mn[node] = min(mn[node * 2 + 1], mn[node * 2 + 2]);
}
void update(int lq, int rq, ll val, int n) { updateRec(0, 0, n - 1, lq, rq, val); }
ll queryRec(int node, int l, int r, int lq, int rq, char type)
{
    if(lazy[node]) //if there is pending lazy update on this node
    {
        seg[node] += lazy[node] * (r - l + 1); mn[node] += lazy[node]; //update the range by adding val the correct amt of times
        if(l != r) //if not leaf node, store lazy updates for its children
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return ((type=='S')?0:40000000000000); //if update range not in current nodes range, return 0
    if(l >= lq && r <= rq) //if current node range completely inside of update range, add all from range to answer
        return ((type=='S')?seg[node]:mn[node]);
    int mid = (l + r) / 2; //if current node range and update range overlap, recurse to both children and add them to answer
    if(type == 'S') return queryRec(node * 2 + 1, l, mid, lq, rq, type) + queryRec(node * 2 + 2, mid + 1, r, lq, rq, type);
    return min(queryRec(node * 2 + 1, l, mid, lq, rq, type), queryRec(node * 2 + 2, mid + 1, r, lq, rq, type));
}
ll query(int lq, int rq, int n, char type) { return queryRec(0, 0, n-1, lq, rq, type); }
void makeRec(int node, int l, int r)
{
    if(l > r) return;
    if(l == r) { seg[node] = mn[node] = nums[l]; return; }
    int mid = (l + r) / 2;
    makeRec(node * 2 + 1, l, mid);
    makeRec(node * 2 + 2, mid + 1, r);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
    mn[node] = min(mn[node * 2 + 1], mn[node * 2 + 2]);
}
void make(int n) { makeRec(0, 0, n-1); }
int main()
{
    int n, q, a, b, c;
    char type;
    fin >> n >> q;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    make(n);
    for(int i = 0; i < q; i ++)
    {
        fin >> type;
        if(type == 'P')
        {
            fin >> a >> b >> c;
            update(a-1, b-1, c, n);
        }
        else
        {
            fin >> a >> b;
            fout << query(a-1, b-1, n, type) << "\n";
        }
    }
}
