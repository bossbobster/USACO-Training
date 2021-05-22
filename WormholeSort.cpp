#include <iostream>
#include <string.h>
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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

int n, m, a, b, c, cur = 0, curN, ans;
bool good;
int nums[100010];
vector<pii> adj[100010];
queue<int> nextInLine;
int cc[100010];
int bs(int l, int r)
{
    int mid = (l+r+1)/2;
    if(l == r) return l;
    memset(cc, 0, sizeof(cc));
    cur = 0;
    for(int i = 0; i < n; i ++)
    {
        if(cc[i]) continue;
        cur ++;
        nextInLine.push(i);
        while(!nextInLine.empty())
        {
            curN = nextInLine.front();
            nextInLine.pop();
            if(cc[curN]) continue;
            cc[curN] = cur;
            for(auto it : adj[curN])
                if(it.s >= mid)
                    nextInLine.push(it.f);
        }
    }
    good = true;
    for(int i = 0; i < n; i ++)
        if(cc[nums[i]] != cc[i])
        {
            good = false;
            break;
        }
    if(!good) return bs(l, mid-1);
    return bs(mid, r);
}
int main()
{
    fin >> n >> m;
    for(int i = 0; i < n; i ++) { fin >> nums[i]; nums[i]--; }
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    ans = bs(0, 1010000000);
    fout << ((ans==1010000000)?-1:ans) << "\n";
}
