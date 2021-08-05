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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ifstream fin("fencedin.in");
ofstream fout("fencedin.out");

struct st
{
    ll sz, idx, type;
    const bool operator<(const st& other) const
    {
        return sz < other.sz;
    }
};

int hor[25010], ver[25010];
st all[50010];
bool done[2];
int main()
{
    ll a, b, n, m, idx = 0, ans = 0, sz, type, h = 0, v = 0;
    fin >> a >> b >> n >> m;
    ver[0] = 0; ver[n+1] = a;
    for(int i = 1; i <= n; i ++)
        fin >> ver[i];
    hor[0] = 0; hor[m+1] = b;
    for(int i = 1; i <= m; i ++)
        fin >> hor[i];
    sort(ver, ver+n+2); sort(hor, hor+m+2);
    for(int i = 1; i <= n+1; i ++)
        all[idx++] = {ver[i]-ver[i-1], i-1, 0};
    for(int i = 1; i <= m+1; i ++)
        all[idx++] = {hor[i]-hor[i-1], i-1, 1};
    sort(all, all+n+m+2);
    for(int i = 0; i < n+m+2; i ++)
    {
        sz = all[i].sz; idx = all[i].idx; type = all[i].type;
        if(!done[(type+1)%2] || !done[type])
        {
            if(type == 0)
            {
                ans += sz*m;
                v++;
            }
            else
            {
                ans += sz*n;
                h++;
            }
            done[type] = true;
        }
        else
        {
            if(type == 0)
            {
                ans += sz*(m-h+1);
                v++;
            }
            else
            {
                ans += sz*(n-v+1);
                h++;
            }
        }
    }
    fout << ans << "\n";
}
