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
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
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
typedef pair<pll, ld> plld;
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
int nums[100010];
int bit[100010];
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
    while(idx <= n)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
int bs(int l, int r)
{
    int mid = (l+r)/2;
    if(l == r) return mid;
    memset(bit, 0, sizeof(bit));
    for(int i = 0; i < mid; i ++)
        update(nums[i], 1);
    for(int i = 0; i < mid; i ++)
        if(nums[i] >= sum(nums[i]-1)+n-mid)
            return bs(l, mid);
    return bs(mid+1, r);
}
int main()
{
    input();
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    cout << n-bs(1, n) << '\n';
}
