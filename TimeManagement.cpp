#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//ulng namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int n;
pii nums[1010];
int bs(int l, int r)
{
    int mid = (l + r + 1) / 2, cur = mid;
    bool good = true;
    if(l == r) return mid;
    for(int i = 0; i < n; i ++)
    {
        if(cur > nums[i].f - nums[i].s) { good = false; break; }
        cur += nums[i].s;
    }
    if(good) return bs(mid, r);
    return bs(l, mid - 1);
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].s >> nums[i].f;
    sort(nums, nums + n);
    cout << max(-1, bs(-1000000, 1000000)) << "\n";
}
