#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <random>
#include <cassert>
#include <bitset>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#pragma GCC optimize("O3,Ofast,unroll-loops")

int nums[210000]; // a little bigger than N to account for last segment (I'm too lazy to handle that separately)
ll pre[210000];
bitset<200010> spot;
int* nx[200010];
int szz[200010];
int n, q, tot, sz, sz2, mxx, mx, endV, vl, cur, st, l, r, lq, rq;
ll stq;
inline int sgn(ll num)
{
    if(num > 0) return 1;
    if(num == 0) return 0;
    return -1;
}
int calc(int l, int str, int add)
{
    int r = l+add;
    for(int i = l; i < r; i ++)
    {
        if(str <= 0) str += nums[i];
        else str -= nums[i];
    }
    return str;
}
pair<int, ll> bs(int l, int r)
{
    int mid = (l+r+1)/2;
    ll num;
    if(sgn(stq) == 1) num = stq-(pre[mid]-pre[lq]);
    else num = stq+(pre[mid]-pre[lq]);
    if(l == r)
        return {mid, num};
    if(sgn(num) == sgn(stq) || sgn(num) == 0)
        return bs(mid, r);
    return bs(l, mid-1);
}
int main()
{
    input();
    cin >> n;
    pre[0] = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pre[i+1] = pre[i]+(ll)nums[i];
    }
    //precompute stuff taking advantage of nice number patterns and amortization
    tot = min(n, 170); sz = n/tot; sz2 = min(n, 400); mxx = 0;
    const int numm = 40;
    int tot = 0;
    for(int i = 0; i < n; i += sz)
    {
        spot[i] = 1;
        vl = ((i==0)?nums[i]:nums[i-1]);
        mxx = vl;
        mx = min(sz2*vl, mxx);
        szz[i] = mx;
        tot += mx*2+1;
    }
    int* all = new int[tot];
    int* curpt = all;
    for(int i = 0; i < n; i += sz)
    {
        mx = szz[i];
        curpt += mx;
        nx[i] = curpt;
        curpt += mx+1;
        endV = nums[i+sz-1];
        if(endV <= numm)
        {
            for(int j = -mx; j <= mx; j ++)
                nx[i][j] = calc(i, j, sz);
            continue;
        }
        st = -1;
        for(int j = -mx; j <= mx; j ++)
        {
            cur = calc(i, j, sz);
            nx[i][j] = cur;
            if(cur == -(endV-(numm-1)) && j < 0)
            {
                st = j;
                break;
            }
        }
        if(st == -1) continue;
        int j;
        for(j = st; cur <= 0; j ++, cur ++)
            nx[i][j] = cur;
        l = j;
        cur = endV-(numm-2);
        for(j = (-st)+1; cur >= 0; j--, cur --)
            nx[i][j] = cur;
        r = j;
        for(j = l; j <= r; j ++)
            nx[i][j] = calc(i, j, sz);
        for(j = (-st)+1; j <= mx; j ++)
            nx[i][j] = calc(i, j, sz);
    }
    // now we have a nx array which helps calculate what the value will be after a specific full segment
    cin >> q;
    while(q--)
    {
        cin >> lq >> rq >> stq; lq--; rq--;
        if(stq != 0)
        {
            pair<int, ll> p = bs(lq, rq+1);
            lq = p.first; stq = p.second;
        }
        while(lq <= rq)
        {
            if(lq+sz2-1 <= rq && abs(stq)-(pre[lq+sz2]-pre[lq]) >= 0)
            {
                stq = ((stq>0)?(stq-(pre[lq+sz2]-pre[lq])):(stq+(pre[lq+sz2]-pre[lq])));
                lq = lq+sz2;
            }
            else if(spot[lq] && lq+sz-1 <= rq)
            {
                if(abs(stq) > szz[lq])
                    stq = calc(lq, stq, sz);
                else
                    stq = nx[lq][stq]; // use pointers and negative indices
                lq = lq+sz;
            }
            else if(lq+sz-1 > rq)
            {
                stq = calc(lq, stq, rq+1-lq);
                lq = rq+1;
            }
            else
            {
                int nxx = ((lq/sz)+1)*sz;
                stq = calc(lq, stq, nxx-lq);
                lq = nxx;
            }
        }
        cout << stq << '\n';
    }
}
