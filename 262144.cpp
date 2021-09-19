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

int dp[270010][70];
int main()
{
    input();
    int n, num, ans = 1;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i ++)
        cin >> num, dp[i][num] = i+1, ans = max(ans, num);
    for(int j = 2; j <= 60; j ++)
        for(int i = 0; i < n; i ++)
            if(dp[i][j-1] != -1)
            {
                dp[i][j] = dp[dp[i][j-1]][j-1];
                if(dp[i][j] != -1) ans = max(ans, j);
            }
    cout << ans << '\n';
}
