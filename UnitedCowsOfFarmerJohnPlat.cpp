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
int nums[200010];
vector<int> pos[200010];
int l[200010];
int r[200010]; //l and r store first occurence of the number to its left and right
int seg[1000010];
int lazy[1000010];
int arr[1000010];
int bit[200010];
int sumB(int idx)
{
    int ans = 0;
    idx ++;
    if(idx <= 0) return 0;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void updateB(int idx, int val)
{
    idx ++;
    if(idx <= 0) return;
    while(idx <= n)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
void updateRec(int node, int l, int r, int lq, int rq, int val)
{
    if(lazy[node])
    {
        seg[node] += lazy[node] * (r - l + 1 - sumB(r) + sumB(l-1));
        if(l != r)
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[node] += val * (r - l + 1 - sumB(r) + sumB(l-1));
        if(l != r)
        {
            lazy[node * 2 + 1] += val;
            lazy[node * 2 + 2] += val;
        }
        return;
    }
    int mid = (l + r) / 2;
    updateRec(node * 2 + 1, l, mid, lq, rq, val);
    updateRec(node * 2 + 2, mid + 1, r, lq, rq, val);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
}
void update(int lq, int rq, int val) { updateRec(0, 0, n - 1, lq, rq, val); }
int sumRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        seg[node] += lazy[node] * (r - l + 1 - sumB(r) + sumB(l-1));
        if(l != r)
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[node];
    int mid = (l + r) / 2;
    return sumRec(node * 2 + 1, l, mid, lq, rq) + sumRec(node * 2 + 2, mid + 1, r, lq, rq);
}
int sum(int lq, int rq) { return sumRec(0, 0, n-1, lq, rq); }
int main()
{
    input();
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i]; nums[i] --;
        pos[nums[i]].push_back(i);
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < pos[i].size(); j ++)
        {
            if(j == 0) l[pos[i][j]] = -1;
            else l[pos[i][j]] = pos[i][j - 1];
        }
    for(int i = 2; i < n; i ++)
    {
        if(l[i-1] != -1)
            update(l[i-1], l[i-1], -sum(l[i-1], l[i-1])), updateB(l[i-1], 1);
        update(l[i-1]+1, i-2, 1);
        if(l[i-1] != -1)
            update(l[l[i-1]]+1, l[i-1]-1, -1);
        if(l[i]+2 < i)
            ans += sum(l[i]+1, i-2);
    }
    cout << ans << "\n";
}
