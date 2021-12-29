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

ifstream fin("eight.in");
ofstream fout("eight.out");

string board[310];
bitset<310> posR[310][310], posC[310][310];
ll u[310][310], d[310][310], l[310][310], r[310][310];
ll ansU[310][310], ansD[310][310];
set<ll> cur;
ll rem[310][310];
int idxs[310];
int main()
{
    input();
    ll n;
    ll ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> board[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            if(board[i][j] != '*')
                posR[i][j][j] = posC[j][i][i] = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 1; j < n; j ++)
            for(int k = 0; k < n-j; k ++)
                if(posR[i][k][k+j-1] && posR[i][k+1][k+j])
                    posR[i][k][k+j] = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 1; j < n; j ++)
            for(int k = 0; k < n-j; k ++)
                if(posC[i][k][k+j-1] && posC[i][k+1][k+j])
                    posC[i][k][k+j] = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            if(board[i][j] == '*') continue;
            for(int k = 0; k <= i; k ++)
                if(posC[j][k][i]) { u[i][j] = k; break; }
            for(int k = n-1; k >= i; k --)
                if(posC[j][i][k]) { d[i][j] = k; break; }
            for(int k = 0; k <= j; k ++)
                if(posR[i][k][j]) { l[i][j] = k; break; }
            for(int k = n-1; k >= j; k --)
                if(posR[i][j][k]) { r[i][j] = k; break; }
        }
    set<ll>::iterator it;
    for(ll i = 2; i < n-2; i ++)
    {
        for(ll j = 0; j < n; j ++)
            memset(ansU[j], 0, sizeof(ansU[j])), memset(ansD[j], 0, sizeof(ansD[j]));
        for(int j = 0; j < n-2; j ++) //sweep from every point to the right
        {
            if(ans > (ll)(n-j-2)*(ll)(i-1)*(ll)(n-j-2)*(ll)(n-i-2)) break;
            cur.clear();
            for(int k = i-2; k >= u[i][j]; k --)
                if(r[k][j] >= j+2)
                {  //insert future removal and also into set for finding best
                    if(posR[i][j][r[k][j]+1])
                        rem[r[k][j]+1][idxs[r[k][j]+1]++] = k;
                    cur.insert(k);
                }
            for(int k = j+2; k < n; k ++)
            {
                if(!posR[i][j][k] || cur.empty()) break;
                while(idxs[k] >= 0)
                    cur.erase(rem[k][--idxs[k]]);
                it = cur.lower_bound(u[i][k]);
                if(it != cur.end())
                    ansU[j][k] = (i-*it-1)*(k-j-1);
            }
            cur.clear();
            for(int k = i+2; k <= d[i][j]; k ++)
                if(r[k][j] >= j+2)
                {  //insert future removal and also into set for finding best
                    if(posR[i][j][r[k][j]+1])
                        rem[r[k][j]+1][idxs[r[k][j]+1]++] = k;
                    cur.insert(k);
                }
            for(int k = j+2; k < n; k ++)
            {
                if(!posR[i][j][k] || cur.empty()) break;
                while(idxs[k] >= 0)
                    cur.erase(rem[k][--idxs[k]]);
                it = cur.upper_bound(d[i][k]);
                if(it != cur.begin())
                    ansD[j][k] = (*prev(it)-i-1)*(k-j-1);
            }
        }
        for(int j = n-2; j >= 2; j --)
            for(int k = 0; k < n-j; k ++)
                ansD[k][k+j] = max({ansD[k][k+j], ansD[k-1][k+j], ansD[k][k+j+1]});
        for(int j = 0; j < n-2; j ++)
            for(int k = j+2; k < n; k ++)
                if(ansU[j][k]*ansD[j][k] > ans)
                    ans = ansU[j][k]*ansD[j][k];
    }
    fout << ((ans==0)?-1:ans) << '\n';
}
