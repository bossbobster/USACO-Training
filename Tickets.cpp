#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, ll> pll;
#define f first
#define s second

const ll inf = 2000000000000000000;
struct tic
{
    int c; ll p; int a, b;
};
bool comp(tic t1, tic t2)
{
    return t1.c < t2.c;
}
int n, k;
tic tics[100010];
pll seg[200010]; // only to 1, only to n, able to go to both
void updateAll(int i, pll val)
{
    i += n;
    seg[i] = {{min(seg[i].f.f, val.f.f), min(seg[i].f.s, val.f.s)}, min(seg[i].s, val.s)};
    for(; i > 1; i >>= 1)
        seg[i>>1] = {{min(seg[i].f.f, seg[i^1].f.f), min(seg[i].f.s, seg[i^1].f.s)}, min(seg[i].s, seg[i^1].s)};
}
pll minAll(int lq, int rq)
{
    rq ++;
    pll ans = {{inf, inf}, inf};
    lq += n; rq += n;
    for(; lq < rq; lq >>= 1, rq >>= 1)
    {
        if(lq&1)
            ans = {{min(ans.f.f, seg[lq].f.f), min(ans.f.s, seg[lq].f.s)}, min(ans.s, seg[lq++].s)};
        if(rq&1)
            ans = {{min(ans.f.f, seg[--rq].f.f), min(ans.f.s, seg[rq].f.s)}, min(ans.s, seg[rq].s)};
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    ll a;
    pll p;
    for(int i = 0; i < k; i ++)
    {
        cin >> tics[i].c >> tics[i].p >> tics[i].a >> tics[i].b;
        tics[i].c--; tics[i].a--; tics[i].b--;
    }
    sort(tics, tics+k, comp);
    for(int i = 0; i < n*2+10; i ++)
        seg[i] = {{inf, inf}, inf};
    //idxRec(0, 0, n-1);
    updateAll(0, {{0, inf}, inf}); updateAll(n-1, {{inf, 0}, inf});
    for(int cnt = 0; cnt < 20; cnt ++)
        for(int i = 0; i < k; i ++)
        {
            p = minAll(tics[i].a, tics[i].b);
            updateAll(tics[i].c, {{p.f.f+tics[i].p, p.f.s+tics[i].p}, min({p.f.f+p.f.s, seg[tics[i].c+n].f.f+p.f.s, p.f.f+seg[tics[i].c+n].f.s, p.s})+tics[i].p});
        }
    for(int i = 0; i < n; i ++)
    {
        a = seg[i+n].s;
        if(a >= inf) cout << "-1\n";
        else cout << a << '\n';
    }
}
