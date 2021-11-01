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

int n, m;
int nums[100010], pre[100010], bit[200010];
int sum(int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int idx, int val)
{
    idx ++;
    while(idx <= 2*n)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
int main()
{
    input();
    cin >> n >> m;
    ll ans = 0;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    pre[0] = n;
    for(int i = 0; i < n; i ++)
        pre[i+1] = ((nums[i]<m)?pre[i]-1:pre[i]+1);
    update(n, 1);
    for(int i = 0; i < n; i ++)
    {
        ans += sum(pre[i+1]);
        update(pre[i+1], 1);
    }
    cout << ans << '\n';
}
