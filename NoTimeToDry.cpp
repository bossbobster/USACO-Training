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
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, short> pish;
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
typedef pair<pll, ll> plll;
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
#define eps 1e-9
//#define cin fin

struct st
{
    int a, b, idx;
    const bool operator<(const st& other) const
    {
        if(b == other.b)
        {
            if(a == other.a) return idx < other.idx;
            return a > other.a;
        }
        return b < other.b;
    }
};
int n, q, cur = 0;
int nums[200010], last[200010], bitDif[200010], bitVal[200010];
int ans[200010];
int sum(int arr[], int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int arr[], int idx, int val)
{
    if(idx == -1) return;
    idx ++;
    while(idx <= n)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
vector<st> qs;
vector<int> idx[200010];
int main()
{
    input();
    int a, b;
    cin >> n >> q;
    for(int i = 0; i <= n; i ++)
        last[i] = -1;
    for(int i = 0; i < n; i ++)
        cin >> nums[i], idx[nums[i]].push_back(i);
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 1; j < idx[i].size(); j ++)
        {
            if(sum(bitVal, idx[i][j])-sum(bitVal, idx[i][j-1]))
                qs.push_back({idx[i][j-1], idx[i][j], -1});
            update(bitVal, idx[i][j-1], 1);
        }
        if(!idx[i].empty())
            update(bitVal, idx[i][idx[i].size()-1], 1);
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b; a--; b--;
        qs.push_back({a, b, i});
    }
    sort(qs.begin(), qs.end());
    for(int i = 0; i < n; i ++)
    {
        update(bitDif, last[nums[i]], -1);
        update(bitDif, i, 1);
        last[nums[i]] = i;
        while(cur != qs.size() && qs[cur].b == i)
        {
            if(qs[cur].idx != -1)
                ans[qs[cur].idx] = sum(bitDif, i)-sum(bitDif, qs[cur].a-1);
            else
                update(bitDif, qs[cur].a, 1);
            cur ++;
        }
    }
    for(int i = 0; i < q; i ++)
        cout << ans[i] << "\n";
}
