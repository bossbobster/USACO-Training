
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

int kmp[2000010];
int pre[2000010];
vector<int> er;
int main()
{
    input();
    int x, p, idx = 0;
    string st, t, ans = "";
    cin >> st >> t;
    st = t + st;
    for(int i = 1; i <= st.length(); i ++)
        pre[i] = i-1;
    kmp[0] = -1; kmp[1] = 0;
    for(int i = 2; i <= st.length(); i ++)
    {
        p = pre[i];
        x = kmp[p];
        while(x != -1 && st[x] != st[i-1])
            x = kmp[x];
        kmp[i] = x+1;
        if(kmp[i] > t.length() && i < 2*t.length())
            kmp[i] = kmp[kmp[i]];
        if(kmp[i] == t.length())
        {
            p = i;
            for(int j = 0; j < t.length(); j ++)
            {
                er.push_back(p-1);
                p = pre[p];
            }
            pre[i+1] = p;
        }
    }
    sort(er.begin(), er.end());
    ans.reserve(st.length());
    for(int i = t.length(); i < st.length(); i ++)
    {
        if(idx < er.size() && i == er[idx]) idx ++;
        else ans += st[i];
    }
    cout << ans << '\n';
}
