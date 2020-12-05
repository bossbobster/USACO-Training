#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct dsu
{
    // parent array
    int par[100010];
    // size array
    int size[100010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
        }
    }
    // find root of n
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    // return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    // connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(size[n] < size[m])
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
    }
};

struct cow
{
    int s, e, val;
};
struct st
{
    int k, s, idx;
};
bool comp1(cow c1, cow c2)
{
    return c1.val > c2.val;
}
bool comp2(st s1, st s2)
{
    return s1.k > s2.k;
}
cow nums[100010];
st que[100010];
int ans[100010];
int main()
{
    int n, q, idx = 0;
    cin >> n >> q;
    dsu d = dsu(n);
    for(int i = 0; i < n - 1; i ++)
        cin >> nums[i].s >> nums[i].e >> nums[i].val;
    for(int i = 0; i < q; i ++)
    {
        cin >> que[i].k >> que[i].s;
        que[i].idx = i;
    }
    sort(nums, nums + n - 1, comp1);
    sort(que, que + q, comp2);
    for(int i = 0; i < q; i ++)
    {
        while(nums[idx].val >= que[i].k)
        {
            d.un(nums[idx].s, nums[idx].e);
            idx ++;
        }
        ans[que[i].idx] = d.size[d.root(que[i].s)];
    }
    for(int i = 0; i < q; i ++)
        cout << ans[i] - 1 << "\n";
}
