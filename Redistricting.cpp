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

ifstream fin("redistricting.in");
ofstream fout("redistricting.out");

multiset<int> pos[300010]; //for each dp answer store all the possible prefix vals it can have
multiset<int> cur; //stores the dp answers
int nums[300010], pre[300010], dp[300010];
int main()
{
    int n, k;
    char c;
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
        fin >> c, nums[i] = ((c=='H')?-1:1);
    pre[0] = 0;
    for(int i = 1; i <= n; i ++)
        pre[i] = pre[i-1] + nums[i-1];
    for(int i = 0; i < k; i ++)
        dp[i] = ((pre[i+1]>=0)?1:0), cur.insert(dp[i]), pos[dp[i]].insert(pre[i+1]);
    for(int i = k; i < n; i ++)
    {
        if((pre[i+1] - *prev(pos[*cur.begin()].end())) < 0)
            dp[i] = *cur.begin();
        else dp[i] = *cur.begin()+1;
        pos[dp[i-k]].erase(pos[dp[i-k]].find(pre[i-k+1]));
        cur.erase(cur.find(dp[i-k]));
        cur.insert(dp[i]);
        pos[dp[i]].insert(pre[i+1]);
    }
    fout << dp[n-1] << '\n';
}
