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

ifstream fin("countcross.in");
ofstream fout("countcross.out");

set<pii> bad[110][110];
vector<pii> cows;
bool visited[110][110];
queue<pii> nextInLine;
int main()
{
    int n, k, r, a, b, c, d, ans = 0;
    fin >> n >> k >> r;
    for(int i = 0; i < r; i ++)
    {
        fin >> a >> b >> c >> d; a--; b--; c--; d--;
        bad[a][b].insert({c, d}); bad[c][d].insert({a, b});
    }
    for(int i = 0; i < k; i ++)
    {
        fin >> a >> b; a--; b--;
        memset(visited, false, sizeof(visited));
        nextInLine.push({a, b});
        while(!nextInLine.empty())
        {
            r = nextInLine.front().f; c = nextInLine.front().s;
            nextInLine.pop();
            if(r < 0 || r >= n || c < 0 || c >= n || visited[r][c]) continue;
            visited[r][c] = true;
            if(bad[r][c].find({r+1, c}) == bad[r][c].end()) nextInLine.push({r+1, c});
            if(bad[r][c].find({r-1, c}) == bad[r][c].end()) nextInLine.push({r-1, c});
            if(bad[r][c].find({r, c+1}) == bad[r][c].end()) nextInLine.push({r, c+1});
            if(bad[r][c].find({r, c-1}) == bad[r][c].end()) nextInLine.push({r, c-1});
        }
        for(int j = 0; j < cows.size(); j ++)
            if(!visited[cows[j].f][cows[j].s])
                ans ++;
        cows.push_back({a, b});
    }
    fout << ans << "\n";
}
