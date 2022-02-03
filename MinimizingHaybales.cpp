#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
#define input() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, k, cur;
int nums[100010];
vector<int> adj[100010];
int in[100010];
unordered_map<int, int> bit;
int sum(int idx)
{
    idx ++;
    int ans = 0;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void up(int idx, int val)
{
    idx ++;
    while(idx <= 1000000000)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
vector<int> zeros;
unordered_map<int, vector<int>> m;
unordered_map<int, int> mIdx;
vector<int> og;
int sorted[100010];
int seg[400010], lazy[400010];
void updateRec(int node, int l, int r, int lq, int rq)
{
    if(r < lq || l > rq || l > r)
        return;
    if(lazy[node])
    {
        seg[node] -= lazy[node];
        if(l != r)
            lazy[node*2+1] += lazy[node], lazy[node*2+2] += lazy[node];
        lazy[node] = 0;
    }
    if(l >= lq && r <= rq)
    {
        seg[node] --;
        if(l != r)
            lazy[node*2+1] ++, lazy[node*2+2] ++;
        return;
    }
    int mid = (l+r)/2;
    updateRec(node*2+1, l, mid, lq, rq); updateRec(node*2+2, mid+1, r, lq, rq);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}
void update(int lq, int rq)
{
    updateRec(0, 0, n-1, lq, rq);
}
void findZerosRec(int node, int l, int r)
{
    if(l > r) return;
    if(lazy[node])
    {
        seg[node] -= lazy[node];
        if(l != r)
            lazy[node*2+1] += lazy[node], lazy[node*2+2] += lazy[node];
        lazy[node] = 0;
    }
    if(seg[node] != 0) return;
    if(l == r)
    {
        zeros.push_back(l);
        seg[node] = 2000000000;
        return;
    }
    int mid = (l+r)/2;
    findZerosRec(node*2+1, l, mid); findZerosRec(node*2+2, mid+1, r);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}
void findZeros()
{
    findZerosRec(0, 0, n-1);
}
void make(int node, int l, int r)
{
    if(l > r) return;
    if(l == r)
    {
        seg[node] = og[l];
        return;
    }
    int mid = (l+r)/2;
    make(node*2+1, l, mid); make(node*2+2, mid+1, r);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}
struct idx
{
    int id;
    const bool operator<(const idx &other) const
    {
        return sorted[id] > sorted[other.id];
    }
};
priority_queue<idx> q;
int main()
{
    input();
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i], sorted[i] = nums[i];
    sort(sorted, sorted+n);
    for(int i = 0; i < n; i ++)
    {
        in[i] = i - (sum(min(999999999, nums[i]+k)) - sum(max(0, nums[i]-k-1)));
        up(nums[i], 1);
    }
    for(int i = 0; i < n; i ++)
        m[nums[i]].push_back(in[i]);
    for(auto it : m)
        sort(it.second.begin(), it.second.end());
    for(int i = 0; i < n; i ++)
    {
        og.push_back(m[sorted[i]][mIdx[sorted[i]]]);
        mIdx[sorted[i]] ++;
        if(og.back() == 0)
            og[og.size()-1] = 2000000000;
    }
    make(0, 0, n-1);
    for(int i = 0; i < n; i ++)
        if(og[i] == 2000000000)
            q.push({i});
    while(!q.empty())
    {
        cur = q.top().id;
        q.pop();
        cout << sorted[cur] << '\n';
        int idx1 = (int)(upper_bound(sorted, sorted+n, sorted[cur]-k-1)-sorted-1),
            idx2 = (int)(upper_bound(sorted, sorted+n, sorted[cur]+k)-sorted);
        if(idx1 > -1) update(0, idx1);
        if(idx2 < n) update(idx2, n-1);
        zeros.clear();
        findZeros();
        for(auto it : zeros)
            q.push({it});
    }
}
