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

/*
 TASK: runround
 LANG: C++
 */

ifstream fin("runround.in");
ofstream fout("runround.out");

vector<int> nums;
vector<int> cur;
bitset<10> b, vis;
int n, num;
ll ans = 2000000000000000;
void rec()
{
    if(cur.size() == nums.size())
    {
        vis.reset();
        int idx = 0;
        while(true)
        {
            if(vis[idx]) break;
            vis[idx] = 1;
            idx = (idx+cur[idx])%cur.size();
        }
        if(vis.count() != cur.size() || idx != 0) return;
        int mult = 1;
        ll cur2 = 0;
        for(int i = cur.size()-1; i >= 0; i --)
            cur2 += mult*cur[i], mult *= 10;
        if(cur2 > n)
            ans = min(ans, cur2);
        return;
    }
    for(int i = 1; i < 10; i ++)
    {
        if(b[i]) continue;
        b[i] = 1;
        cur.push_back(i);
        rec();
        cur.pop_back();
        b[i] = 0;
    }
}
int main()
{
    input();
    fin >> n; num = n;
    while(num > 0)
    {
        nums.insert(nums.begin(), num%10);
        num/=10;
    }
    rec();
    if(ans == 2000000000000000)
    {
        nums.push_back(0);
        rec();
    }
    fout << ans << '\n';
}
