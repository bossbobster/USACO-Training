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

ifstream fin("art.in");
ofstream fout("art.out");

struct rect
{
    int x1, y1, x2, y2;
};
int n;
int seg[1010][5010];
int lazy[1010][5010];
void updateRec(int which, int node, int l, int r, int lq, int rq, int val)
{
    if(lazy[node])
    {
        seg[which][node] += lazy[which][node] * (r - l + 1);
        if(l != r)
        {
            lazy[which][node * 2 + 1] += lazy[which][node];
            lazy[which][node * 2 + 2] += lazy[which][node];
        }
        lazy[which][node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[which][node] += val * (r - l + 1);
        if(l != r)
        {
            lazy[which][node * 2 + 1] += val;
            lazy[which][node * 2 + 2] += val;
        }
        return;
    }
    int mid = (l + r) / 2;
    updateRec(which, node*2+1, l, mid, lq, rq, val);
    updateRec(which, node*2+2, mid+1, r, lq, rq, val);
    seg[which][node] = seg[which][node * 2 + 1] + seg[which][node * 2 + 2];
}
void update(int which, int lq, int rq, int val) { updateRec(which, 0, 0, n-1, lq, rq, val); }
int sumRec(int which, int node, int l, int r, int lq, int rq)
{
    if(lazy[which][node])
    {
        seg[which][node] += lazy[which][node] * (r - l + 1);
        if(l != r)
        {
            lazy[which][node * 2 + 1] += lazy[which][node];
            lazy[which][node * 2 + 2] += lazy[which][node];
        }
        lazy[which][node] = 0;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[which][node];
    int mid = (l + r) / 2;
    return sumRec(which, node*2+1, l, mid, lq, rq) + sumRec(which, node*2+2, mid+1, r, lq, rq);
}
int sum(int which, int lq, int rq) { return sumRec(which, 0, 0, n-1, lq, rq); }
bitset<1000010> b, vis;
int board[1010][1010];
rect nums[1000010];
int main()
{
    fin >> n;
    for(int i = 1; i <= n*n; i ++)
        nums[i] = {2000000000, 2000000000, -1, -1};
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            fin >> board[i][j];
            vis[board[i][j]] = 1;
            nums[board[i][j]].x1 = min(nums[board[i][j]].x1, j);
            nums[board[i][j]].x2 = max(nums[board[i][j]].x2, j);
            nums[board[i][j]].y1 = min(nums[board[i][j]].y1, i);
            nums[board[i][j]].y2 = max(nums[board[i][j]].y2, i);
        }
    vis[0] = 0;
    for(int i = 1; i <= n*n; i ++)
    {
        b[i] = 1;
        if(nums[i].x2 == -1) continue;
        update(nums[i].x1, nums[i].y1, nums[i].y2, 1);
        update(nums[i].x2+1, nums[i].y1, nums[i].y2, -1);
    }
    int cur;
    bool good = false;
    for(int i = 0; i < n; i ++)
    {
        cur = 0;
        for(int j = 0; j < n; j ++)
        {
            cur += sum(j, i, i);
            if(cur > 1) { b[board[i][j]] = 0; good = true; }
        }
    }
    fout << ((good||vis.count()>1)?b.count():b.count()-1) << '\n';
}
