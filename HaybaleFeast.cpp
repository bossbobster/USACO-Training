#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("hayfeast.in");
ofstream fout("hayfeast.out");

struct meal
{
    long long fl, sp;
};
meal meals[100000];
long long pre[100010];
long long maxs[400];
long long n, m, cur = 0, maxN = 0, sq, ans = 1000000000000;

long long maxQ(int s, int e)
{
    long long l = 0, r = 0, maxNum = 0;
    if(s % sq == 0) l = maxs[s / sq];
    else
    {
        for(int i = s; i <= min(s / sq * sq + sq, n); i ++)
            l = max(l, meals[i].sp);
    }
    if((e + 1) % sq == 0) r = maxs[e / sq];
    else
    {
        for(int i = e / sq * sq; i <= e; i ++)
            r = max(r, meals[i].sp);
    }
    maxNum = max(l, r);
    for(int i = s / sq + 1; i < e / sq; i ++)
        maxNum = max(maxNum, maxs[i]);
    return maxNum;
}
int main()
{
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> meals[i].fl >> meals[i].sp;
    for(int i = 0; i <= n; i ++)
    {
        pre[i] = cur;
        cur += meals[i].fl;
    }
    sq = sqrt(n); cur = 1;
    for(int i = 0; i < n; i ++)
    {
        maxN = max(maxN, meals[i].sp);
        if(i == sq * cur - 1 || i == n - 1)
        {
            cur ++;
            maxs[cur - 2] = maxN; maxN = 0;
        }
    }
    for(int i = 0; i < n; i ++)
    {
        if(pre[n] - pre[i] < m) break;
        long long *it = lower_bound(pre + i, pre + n, m + pre[i]);
        ans = min(ans, maxQ(i, it - pre - 1));
    }
    fout << ans << endl;
}


// BETTER O(N LOG N) SOLUTION (other one is O(N sqrt N))
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct meal
{
    long long fl, sp;
};
meal meals[100010];
long long pre[100010];
long long n, m, cur = 0, maxN = 0, sq, ans = 1000000000000;

long long prec[100010][35];
void sparse(int n)
{
    for(int i = 0; i < n; i ++)
        prec[i][0] = meals[i].sp;
    for(int i = 1; i <= floor(log2(n)); i ++)
        for(int j = 0; j <= n - (1 << i); j ++)
            prec[j][i] = max(prec[j][i - 1], prec[j + (1 << (i - 1))][i - 1]);
}
long long maxQ(int l, int r)
{
    int log = floor(log2(r - l + 1));
    return max(prec[l][log], prec[r - (1 << log) + 1][log]);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> meals[i].fl >> meals[i].sp;
    sparse(n);
    for(int i = 0; i <= n; i ++)
    {
        pre[i] = cur;
        cur += meals[i].fl;
    }
    for(int i = 0; i < n; i ++)
    {
        if(pre[n] - pre[i] < m) break;
        long long *it = lower_bound(pre + i, pre + n, m + pre[i]);
        ans = min(ans, maxQ(i, it - pre - 1));
    }
    cout << ans << endl;
}
