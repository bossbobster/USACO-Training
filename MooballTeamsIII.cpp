#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second

int n, x, y;
const ll mod = 1000000007, half = 500000004;
ll pw[400010];
int idx[200010];
vector<pii> nums;
int bit[200010];
int sumBit(int idx)
{
    idx ++;
    int ans = 0;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx&(-idx);
    }
    return ans;
}
void upBit(int idx, int val)
{
    idx ++;
    while(idx <= n)
    {
        bit[idx] += val;
        idx += idx&(-idx);
    }
}
ll sumPwInc(int a, int b)
{
    ll ans = pw[b+1]-1;
    ans -= pw[a]-1;
    return (ans+mod)%mod;
}
ll seg[2][800010];
ll lazy[2][800010];
void multRec(int which, int node, int l, int r, int lq, int rq, ll val)
{
    if(lazy[which][node] != 1)
    {
        seg[which][node] = (seg[which][node]*lazy[which][node])%mod;
        if(l != r)
        {
            lazy[which][node*2+1] = (lazy[which][node*2+1]*lazy[which][node])%mod;
            lazy[which][node*2+2] = (lazy[which][node*2+2]*lazy[which][node])%mod;
        }
        lazy[which][node] = 1;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[which][node] = (seg[which][node]*val)%mod;
        if(l != r)
        {
            lazy[which][node*2+1] = (lazy[which][node*2+1]*val)%mod;
            lazy[which][node*2+2] = (lazy[which][node*2+2]*val)%mod;
        }
        return;
    }
    int mid = (l+r)/2;
    multRec(which, node*2+1, l, mid, lq, rq, val); multRec(which, node*2+2, mid+1, r, lq, rq, val);
    seg[which][node] = (seg[which][node*2+1] + seg[which][node*2+2])%mod;
}
void mult(int which, int lq, int rq, ll val) { multRec(which, 0, 0, n-1, lq, rq, val); }
ll sumRec(int which, int node, int l, int r, int lq, int rq)
{
    if(lazy[which][node] != 1)
    {
        seg[which][node] = (seg[which][node]*lazy[which][node])%mod;
        if(l != r)
        {
            lazy[which][node*2+1] = (lazy[which][node*2+1]*lazy[which][node])%mod;
            lazy[which][node*2+2] = (lazy[which][node*2+2]*lazy[which][node])%mod;
        }
        lazy[which][node] = 1;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[which][node];
    int mid = (l+r)/2;
    return (sumRec(which, node*2+1, l, mid, lq, rq) + sumRec(which, node*2+2, mid+1, r, lq, rq))%mod;
}
ll sum(int which, int lq, int rq) { return sumRec(which, 0, 0, n-1, lq, rq); }
void makeRec(int which, ll* arr, int node, int l, int r)
{
    if(l > r) return;
    if(l == r) { seg[which][node] = arr[l]; return; }
    int mid = (l+r)/2;
    makeRec(which, arr, node*2+1, l, mid); makeRec(which, arr, node*2+2, mid+1, r);
    seg[which][node] = (seg[which][node*2+1] + seg[which][node*2+2])%mod;
}
void make(int which, ll* arr) { makeRec(which, arr, 0, 0, n-1); }
void ptRec(int which, int node, int l, int r, int q, ll val)
{
    if(lazy[which][node] != 1)
    {
        seg[which][node] = (seg[which][node]*lazy[which][node])%mod;
        if(l != r)
        {
            lazy[which][node*2+1] = (lazy[which][node*2+1]*lazy[which][node])%mod;
            lazy[which][node*2+2] = (lazy[which][node*2+2]*lazy[which][node])%mod;
        }
        lazy[which][node] = 1;
    }
    if(q < l || q > r) return;
    if(l == r)
    {
        seg[which][node] = val;
        return;
    }
    int mid = (l+r)/2;
    ptRec(which, node*2+1, l, mid, q, val); ptRec(which, node*2+2, mid+1, r, q, val);
    seg[which][node] = (seg[which][node*2+1] + seg[which][node*2+2])%mod;
}
void pt(int which, int q, ll val) { ptRec(which, 0, 0, n-1, q, val); }
ll arr[200010], later[200010];
int main()
{
    input();
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> x >> y;
        idx[y] = x-1;
        nums.push_back({x, y});
    }
    sort(nums.begin(), nums.end());
    pw[0] = 1;
    for(int i = 1; i <= 2*n; i ++)
        pw[i] = (pw[i-1]*2LL)%mod;
    ll ans = 0;
    for(int i = 0; i < n-1; i ++)
        ans = (ans+((pw[i]*(pw[n-1-i]-1))*2LL))%mod; // the final *2 is for vertical + horizontal
    ll sub = 0;
    
    // first add the it.s == i cases to the sub, and subtract other inconvenient terms
    int u = 0, d = 0, t, b;
    bool lef;
    for(int i = 1; i < n; i ++)
    {
        upBit(idx[i], 1);
        t = sumBit(idx[i]);
        d = n-i;
        b = idx[i]+1-t;
        sub = (sub+pw[t-1]*(pw[d-b]-1))%mod;
        if(t == 1)
            later[i] = (half*pw[d-b])%mod;
        else
            later[i] = (pw[t-2]*pw[d-b])%mod;
        if(i != 1)
            sub = (sub-sumPwInc(t-1, i-2)+mod)%mod;
    }
    
    fill(lazy[0], lazy[0]+800010, 1);
    fill(lazy[1], lazy[1]+800010, 1);
    
    for(int i = 1; i <= 1; i ++) // do the first row to have all the numbers
    {
        u = i; d = n-i;
        t = 0; b = 0;
        lef = false;
        for(auto it : nums)
        {
            if(it.s == i) lef = true;
            if(it.s <= i)
            {
                t ++;
                if(lef && it.s != i)
                    sub = (sub+pw[t-2]*pw[d-b])%mod;
            }
            else
            {
                b ++;
                if(!lef)
                    sub = (sub+pw[b-1]*pw[u-t-1])%mod;
                if(u == t)
                    arr[it.f-1] = (pw[b-1]*half)%mod;
                else
                    arr[it.f-1] = (pw[b-1]*pw[u-t-1])%mod;
            }
        }
    }
    //make the seg trees (0 is for top, 1 is for bottom)
    make(1, arr);
    pt(0, idx[1], later[1]);
    int id;
    for(int i = 2; i < n; i ++) //loop through the rows
    {
        id = idx[i];
        
        u ++; d --; //both of these operations will multiply/divide everything through by 2
        mult(0, 0, n-1, half); mult(1, 0, n-1, 2LL);
        
        // extra t++
        mult(0, id, n-1, 2LL); mult(1, id, n-1, half);
        
        // removed b++
        mult(0, id, n-1, 2LL); mult(1, id, n-1, half);
        
        // set the stuff
        pt(0, id, later[i]);
        pt(1, id, 0);
        
        // add to sub
        if(id < n-1)
            sub = (sub+sum(0, id+1, n-1))%mod;
        if(id > 0)
            sub = (sub+sum(1, 0, id-1))%mod;
    }
    ans = (ans-sub+mod*10LL)%mod;
    cout << (ans*2LL)%mod << '\n'; // last *2 for red/blue
}
