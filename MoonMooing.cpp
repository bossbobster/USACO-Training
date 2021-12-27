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

ll c, n, a1, b1, d1, a2, b2, d2, cur;
ll f1(ll num) { return num * a1 / d1 + b1; }
ll f2(ll num) { return num * a2 / d2 + b2; }
deque<ll> v1, v2;
int main()
{
    input();
    cin >> c >> n >> a1 >> b1 >> d1 >> a2 >> b2 >> d2;
    v1.push_back(f1(c)); v2.push_back(f2(c));
    for(int i = 0; i < n-1; i ++)
    {
        if(v1[0] == v2[0]) cur = v1[0], v1.pop_front(), v2.pop_front();
        else if(v1[0] < v2[0]) cur = v1[0], v1.pop_front();
        else cur = v2[0], v2.pop_front();
        v1.push_back(f1(cur)); v2.push_back(f2(cur));
    }
    cout << cur << '\n';
}
