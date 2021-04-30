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

ifstream fin("optmilk.in");
ofstream fout("optmilk.out");

struct st
{
    ll l, r, b, n; //which locations are used
};
int n, d;
ll nums[40010];
st seg[200010];
void update(int l, int r, int curIdx, int upIdx, ll val)
{
    if(l == r)
    {
        seg[curIdx].b = val;
        nums[upIdx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(upIdx >= l && upIdx <= mid)
        update(l, mid, curIdx * 2 + 1, upIdx, val);
    else
        update(mid + 1, r, curIdx * 2 + 2, upIdx, val);
    int ln = curIdx*2+1, rn = curIdx*2+2;
    seg[curIdx].b = max({seg[ln].b + seg[rn].r, seg[ln].l + seg[rn].b, seg[ln].l + seg[rn].r});
    seg[curIdx].r = max({seg[ln].r + seg[rn].r, seg[ln].n + seg[rn].r, seg[ln].n + seg[rn].b});
    seg[curIdx].l = max({seg[ln].l + seg[rn].l, seg[ln].l + seg[rn].n, seg[ln].b + seg[rn].n});
    seg[curIdx].n = max({seg[ln].n + seg[rn].n, seg[ln].r + seg[rn].n, seg[ln].n + seg[rn].l});
}
ll maxQ(int l, int r, int lq, int rq, int curIdx)
{
    if(lq == rq)
        return nums[lq];
    if(r < lq || l > rq)
        return 0;
    if(lq <= l && rq >= r)
        return max({seg[curIdx].l, seg[curIdx].r, seg[curIdx].b, seg[curIdx].n});
    int mid = (l + r) / 2;
    if(rq <= mid) return maxQ(l, mid, lq, rq, curIdx * 2 + 1);
    if(lq > mid) return maxQ(mid + 1, r, lq, rq, curIdx * 2 + 2);
    return max(maxQ(l, mid, lq, rq, curIdx * 2 + 1), maxQ(mid + 1, r, lq, rq, curIdx * 2 + 2));
}
void makeTree(int l, int r, int curIdx)
{
    if(l == r) { seg[curIdx].b = nums[l]; return; }
    int mid = (l + r) / 2;
    makeTree(l, mid, curIdx * 2 + 1); makeTree(mid + 1, r, curIdx * 2 + 2);
    int ln = curIdx*2+1, rn = curIdx*2+2;
    seg[curIdx].b = max({seg[ln].b + seg[rn].r, seg[ln].l + seg[rn].b, seg[ln].l + seg[rn].r});
    seg[curIdx].r = max({seg[ln].r + seg[rn].r, seg[ln].n + seg[rn].r, seg[ln].n + seg[rn].b});
    seg[curIdx].l = max({seg[ln].l + seg[rn].l, seg[ln].l + seg[rn].n, seg[ln].b + seg[rn].n});
    seg[curIdx].n = max({seg[ln].n + seg[rn].n, seg[ln].r + seg[rn].n, seg[ln].n + seg[rn].l});
}
int main()
{
    input(0);
    int a, b;
    ll ans = 0;
    fin >> n >> d;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    makeTree(0, n-1, 0);
    while(d--)
    {
        fin >> a >> b; a--;
        update(0, n-1, 0, a, b);
        ans += maxQ(0, n-1, 0, n-1, 0);
    }
    fout << ans << "\n";
}
