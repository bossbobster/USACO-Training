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
//#define cin fin
//#define cout fout

ifstream fin("sort.in");
ofstream fout("sort.out");

int nums[100010], sorted[100010];
unordered_map<int, int> hsh;
vector<int> idx[100010];
int ii[100010];
ll part[100010];
int main()
{
    int n, num = 0, cur = 0;
    ll ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i], sorted[i] = nums[i], hsh[nums[i]] = -1;
    sort(sorted, sorted+n);
    for(auto it : sorted)
        if(hsh[it] == -1)
            hsh[it] = cur++;
    for(int i = 0; i < n; i ++)
        nums[i] = hsh[nums[i]], sorted[i] = hsh[sorted[i]];
    for(int i = 0; i < n; i ++)
        idx[nums[i]].push_back(i);
    for(int i = 0; i < n-1; i ++)
    {
        num = max(num, idx[sorted[i]][ii[sorted[i]]++]);
        part[i] = max(0, num-i);
    }
    ll add = 0;
    for(int i = 0; i < n; i ++)
    {
        add = part[i];
        if(i > 0) add = max(add, part[i-1]);
        ans += add;
    }
    if(ans < n) ans += n;
    fout << ans << '\n';
}
