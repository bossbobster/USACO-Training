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

ifstream fin("moocast.in");
ofstream fout("moocast.out");

struct cow
{
    int x, y, d;
};
int dist(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
int n, ans = 1;
cow cows[210];
vector<int> adj[210];
bool visited[210];
int dfs(int cur)
{
    if(visited[cur]) return 0;
    visited[cur] = true;
    int curSum = 1;
    for(auto it : adj[cur])
        curSum += dfs(it);
    return curSum;
}
int main()
{
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> cows[i].x >> cows[i].y >> cows[i].d;
        cows[i].d *= cows[i].d;
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            if(i == j) continue;
            if(dist(cows[i].x, cows[i].y, cows[j].x, cows[j].y) <= cows[i].d)
                adj[i].push_back(j);
        }
    for(int i = 0; i < n; i ++)
    {
        memset(visited, false, sizeof(visited));
        ans = max(ans, dfs(i));
    }
    fout << ans << "\n";
}
