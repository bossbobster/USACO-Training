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
typedef pair<uint, uint> puint;
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
//#define cout fout

ifstream fin("diamond.in");
ofstream fout("diamond.out");

int nums[50010];
int r[50010], mx[50010];
int main()
{
    input();
    int n, k, ans = 0;
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    sort(nums, nums+n);
    int idx = 0;
    for(int i = 0; i < n; i ++)
    {
        while(idx < n && nums[idx]-nums[i] <= k) idx ++;
        idx --;
        r[i] = idx;
    }
    for(int i = n-1; i >= 0; i --)
    {
        ans = max(ans, r[i]-i+1 + mx[r[i]+1]);
        mx[i] = max(mx[i+1], r[i]-i+1);
    }
    fout << ans << '\n';
}
