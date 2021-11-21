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

int n;
int tree[400010];
int nums[2][200010], idx[200010];
void update(int idx, int val)
{
    tree[idx + n] = val;
    idx += n;
    for(int i = idx; i > 1; i >>= 1)
        tree[i >> 1] = max(tree[i], tree[i ^ 1]);
}
int maxQ(int l, int r)
{
    int ans = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1) ans = max(ans, tree[l ++]);
        if(r & 1) ans = max(ans, tree[-- r]);
    }
    return ans;
}
int mx[10];
int main()
{
    cin >> n;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < n; j ++)
        {
            cin >> nums[i][j]; nums[i][j] --;
            if(i) idx[nums[i][j]] = j;
        }
    for(int i = 0; i < n; i ++)
    {
        int tmp = 0;
        for(int j = max(0, nums[0][i]-4); j <= min(n-1, nums[0][i]+4); j ++)
            mx[tmp++] = maxQ(0, idx[j]);
        tmp = 0;
        for(int j = max(0, nums[0][i]-4); j <= min(n-1, nums[0][i]+4); j ++)
            update(idx[j], mx[tmp++]+1);
    }
    cout << maxQ(0, n) << '\n';
}
