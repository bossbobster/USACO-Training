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

ifstream fin("deleg.in");
ofstream fout("deleg.out");

int n, a, b, mid;
vector<int> adj[100010];
int dp[100010];
bool good;
int bs2(vector<int> v, int l, int r)
{
    if(l >= r) return l;
    int mid2 = (l+r+1)/2;
    for(int idx1 = 0, idx2 = (int)v.size()-1; idx1 < idx2; idx1++,idx2--)
    {
        if(idx1 == mid2) idx1 ++;
        if(idx2 == mid2) idx2 --;
        if(v[idx1]+v[idx2] < mid)
            return bs2(v, l, mid2-1);
    }
    return bs2(v, mid2, r);
}
void dfs(int cur, int par)
{
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
    }
    vector<int> v;
    for(auto it : adj[cur])
        if(it != par)
            v.push_back(dp[it]+1);
    sort(v.begin(), v.end());
    if(v.empty()) return;
    if(v.size()%2 == 0)
    {
        vector<int> other;
        bool alr = false;
        for(int i : v)
        {
            if(i >= mid && !alr)
                alr = true;
            else other.push_back(i);
        }
        bool goood = false;
        if(other.size()%2)
        {
            int best = bs2(other, -1, (int)other.size()-1);
            goood = true;
            if(best == -1)
            {
                for(int idx1 = 0, idx2 = (int)v.size()-1; idx1 < idx2; idx1++,idx2--)
                    if(v[idx1]+v[idx2] < mid)
                        goood = false;
            }
            else
                dp[cur] = other[best];
        }
        if(!goood)
        {
            for(int i = 0; i < v.size(); i ++)
                if(v[i]+v[v.size()-i-1] < mid)
                    good = false;
        }
    }
    else
    {
        int best = bs2(v, -1, (int)v.size()-1);
        if(best == -1)
            good = false;
        else
            dp[cur] = v[best];
    }
}
int bs(int l, int r)
{
    mid = (l+r+1)/2;
    if(l == r) return l;
    memset(dp, 0, sizeof(dp));
    good = true;
    dfs(0, -1);
    if(good) return bs(mid, r);
    return bs(l, mid-1);
}
int main()
{
    input();
    fin >> n;
    for(int i = 0; i < n-1; i ++)
    {
        fin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    fout << bs(1, n-1) << '\n';
}
