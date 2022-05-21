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
typedef unsigned short ushort;
typedef pair<uint, uint> puint;
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
#define leni(x) sizeof(x)/sizeof(int)
//#define cin fin
//#define cout fout

pis nums[50010];
vector<pii> v;
int main()
{
    input();
    freopen("learning.in", "r", stdin);
    freopen("learning.out", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].s >> nums[i].f;
    sort(nums, nums+n);
    if(nums[0].s == "S")
        v.push_back({min(a, nums[0].f), (nums[0].f+nums[1].f)/2});
    if(nums[n-1].s == "S")
        v.push_back({(nums[n-2].f+nums[n-1].f+1)/2, max(b, nums[n-1].f)});
    for(int i = 1; i < n-1; i ++)
    {
        if(nums[i].s == "NS") continue;
        int l = (nums[i-1].f+nums[i].f+1)/2;
        if(!v.empty() && v.back().s == l) l ++;
        v.push_back({l, (nums[i].f+nums[i+1].f)/2});
    }
    for(auto it : v)
        ans += max(0, (min(b, it.s)-max(a, it.f)+1));
    cout << ans << '\n';
}
