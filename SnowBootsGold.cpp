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
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI 3.14159265359

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

int nums[100010];
piii boot[100010];
set<int> all;
unordered_map<int, int> hsh;
vector<int> idx[200010];
multiset<int> dist;
set<int> good;
bitset<100010> ans;
int main()
{
    input();
    int n, b;
    fin >> n >> b;
    for(int i = 0; i < n; i ++)
        fin >> nums[i], all.insert(nums[i]);
    for(int i = 0; i < b; i ++)
        fin >> boot[i].f.f >> boot[i].f.s, boot[i].s = i, all.insert(boot[i].f.f);
    int id = 0;
    for(auto it : all)
        hsh[it] = id++;
    for(int i = 0; i < n; i ++)
        nums[i] = hsh[nums[i]];
    for(int i = 0; i < b; i ++)
        boot[i].f.f = hsh[boot[i].f.f];
    sort(boot, boot+b);
    for(int i = 1; i < n-1; i ++)
        idx[nums[i]].push_back(i);
    set<int>::iterator smol, big;
    dist.insert(n-1);
    good.insert(0); good.insert(n-1);
    int bootIdx = 0;
    for(int i = 0; i < id; i ++)
    {
        for(int cur : idx[i])
        {
            big = good.lower_bound(cur);
            smol = prev(big);
            dist.erase(dist.find(*big-*smol));
            dist.insert(*big-cur);
            dist.insert(cur-*smol);
            good.insert(cur);
        }
        while(bootIdx < b && i == boot[bootIdx].f.f)
        {
            if(boot[bootIdx].f.s >= *prev(dist.end()))
                ans[boot[bootIdx].s] = 1;
            bootIdx ++;
        }
    }
    for(int i = 0; i < b; i ++)
        fout << ans[i] << '\n';
}
