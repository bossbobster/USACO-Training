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
pii nums[100010];
map<int, bool> cur;
int main()
{
    input();
    int ans = 0;
    map<int, bool>::iterator l, r;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    sort(nums, nums+n, greater<pii>());
    cur.insert({-1000000001, true}); cur.insert({2000000001, true});
    for(int i = 0; i < n; i ++)
    {
        r = cur.upper_bound(nums[i].s); l = prev(r);
        cur[nums[i].s] = false;
        if(r->f - nums[i].s > nums[i].f)
            cur[nums[i].s] = l->s;
        if(nums[i].s - l->f <= nums[i].f)
            cur[l->f] = false;
    }
    for(map<int, bool>::iterator it = cur.begin(); it != prev(cur.end()); ++it)
        if(it->s == false)
            ans += next(it)->f - it->f;
    cout << ans << '\n';
}
