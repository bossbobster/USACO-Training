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
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int mx[310][310][310], dp[310][310];
vector<piii> cows;
int main()
{
    input();
    int n, m;
    piii tmp;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> tmp.s >> tmp.f.f >> tmp.f.s; tmp.f.f--; tmp.f.s--;
        cows.push_back(tmp);
    }
    for(auto it : cows)
        for(int i = it.f.f; i <= it.f.s; i ++)
            mx[i][it.f.f][it.f.s] = max(mx[i][it.f.f][it.f.s], it.s);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n-i; j ++)
            for(int k = j; k <= j+i; k ++)
                mx[k][j][j+i] = max({mx[k][j][j+i], mx[k][j][j+i-1], mx[k][j+1][j+i]});
    for(int i = 0; i < n; i ++)
        dp[i][0] = mx[i][i][i];
    for(int j = 1; j < n; j ++)
        for(int i = 0; i < n-j; i ++)
        {
            dp[i][j] = max(dp[i][j-1]+mx[i+j][i][i+j], dp[i+1][j-1]+mx[i][i][i+j]);
            for(int k = 0; k < j-1; k ++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[i+k+2][j-k-2] + mx[i+k+1][i][i+j]);
        }
    cout << dp[0][n-1] << '\n';
}
