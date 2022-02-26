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

ifstream fin("cave.in");
ofstream fout("cave.out");

int n, m;
string board1[1010];
bitset<1010> board[1010];
unordered_set<int> vis;
unordered_map<int, int> mult;
ll ans = 1;
const ll mod = 1000000007;
ll dp[1010][1010], nums[1010];
int par[1010];
struct dsu
{
    int par[1000010];
    int size[1000010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
        }
    }
    // find root of n
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    // return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    // connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(size[n] < size[m])
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
    }
};
int main()
{
    input();
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> board1[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(board1[i][j] == '.')
                board[i][j] = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(board[i][j])
                dp[i][j] = 1;
    dsu d = dsu(n*m+5);
    for(int i = n-2; i > 0; i --)
    {
        vis.clear(); mult.clear(); memset(par, -1, sizeof(par));
        for(int j = 1; j < m-1; j ++)
            if(board[i+1][j])
                par[j] = d.root((i+1)*m+j), nums[j] = dp[i+1][j];
        for(int j = 1; j < m-1; j ++)
            if(board[i][j] && board[i][j+1])
                d.un(i*m+j, i*m+j+1);
        for(int j = 1; j < m-1; j ++)
            if(board[i][j] && board[i+1][j])
                d.un(i*m+j, (i+1)*m+j);
        for(int j = 1; j < m-1; j ++)
            if(board[i][j])
                mult[d.root(i*m+j)] = 1;
        for(int j = 1; j < m-1; j ++)
            if(board[i][j] && par[j] != -1)
                if(vis.find(par[j]) == vis.end())
                {
                    mult[d.root(i*m+j)] = (mult[d.root(i*m+j)] * nums[j]) % mod;
                    vis.insert(par[j]);
                }
        for(int j = 1; j < m-1; j ++)
            if(board[i][j])
                dp[i][j] = (mult[d.root(i*m+j)]+1)%mod;
    }
    vis.clear();
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(board[i][j])
                if(vis.find(d.root(i*m+j)) == vis.end())
                {
                    ans = (ans * dp[i][j]) % mod;
                    vis.insert(d.root(i*m+j));
                }
    fout << ans << '\n';
}
