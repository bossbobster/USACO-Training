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

int n, idxAll, num, pw;
piii all[100010], other[100010];
vector<piii> all2[100010];
string st, s2;
int pre[100010][19], idx[26];
set<char> let;
void suf()
{
    for(int i = 0; i < n; i ++)
        let.insert(st[i]);
    num = 0;
    for(auto it : let)
        idx[it-'a'] = num++;
    for(int i = 0; i < n; i ++)
        pre[i][0] = idx[st[i]-'a'];
    for(int i = 1; i <= pw; i ++)
    {
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            all[idxAll++] = {{pre[j][i-1], pre[(j+(1<<(i-1)))%n][i-1]}, j};
        for(int j = 0; j < n; j ++)
            all2[j].clear();
        for(int j = 0; j < n; j ++)
            all2[all[j].f.s].push_back(all[j]);
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            for(auto it : all2[j])
                other[idxAll++] = it;
        for(int j = 0; j < n; j ++)
            all2[j].clear();
        for(int j = 0; j < n; j ++)
            all2[other[j].f.f].push_back(other[j]);
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            for(auto it : all2[j])
                all[idxAll++] = it;
        num = 0;
        for(int j = 0; j < n; j ++)
            pre[all[j].s][i] = (j != 0 && all[j].f.f == all[j-1].f.f && all[j].f.s == all[j-1].f.s)?pre[all[j-1].s][i]:num++;
    }
}
int main()
{
    input();
    cin >> n;
    st.reserve(n*2);
    while(st.length() < n)
    {
        cin >> s2;
        st += s2;
    }
    st += st;
    pw = log2(n*2);
    suf();
    for(int i = 0; i < n; i ++)
        if(pre[i][pw] == 0)
        {
            cout << i << '\n';
            return 0;
        }
}
