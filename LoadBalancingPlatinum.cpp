#include <iostream>
#include <string.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("balancing.in");
ofstream fout("balancing.out");

int n;
pii nums[100010];
int bit[2][1000010];
int sum(int idx, int which)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += bit[which][idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int idx, int val, int which)
{
    idx ++;
    while(idx <= 1000000)
    {
        bit[which][idx] += val;
        idx += idx & (-idx);
    }
}
int bs(int l, int r)
{
    int mid = (l+r+1)/2, x1 = sum(mid, 0), x2 = sum(1000000, 0)-x1, x3 = sum(mid, 1), x4 = sum(1000000, 1)-x3;
    if(l == mid) return max({x1, x2, x3, x4});
    if(r == mid)
    {
        int x5 = sum(mid-1, 0), x6 = sum(1000000, 0)-x5, x7 = sum(mid-1, 1), x8 = sum(1000000, 1)-x7;
        return min(max({x1, x2, x3, x4}), max({x5, x6, x7, x8}));
    }
    if(max(x1, x3) > max(x2, x4)) return bs(l, mid);
    return bs(mid, r);
}
int main()
{
    int idx = 0, ans = 2000000000;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].f >> nums[i].s;
    sort(nums, nums+n);
    for(int i = 0; i < n; i ++) update(nums[i].s, 1, 1);
    for(int i = 0; i < n; i ++)
    {
        while(idx < n && nums[i].f == nums[idx].f) { update(nums[idx].s, 1, 0); update(nums[idx].s, -1, 1); idx++; }
        i = idx-1;
        ans = min(ans, bs(0, 1000000));
    }
    fout << ans << "\n";
}
