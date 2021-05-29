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

ifstream fin("mooyomooyo.in");
ofstream fout("mooyomooyo.out");

string board[110];
bool visited[110][11];
vector<pii> cc[1010];
queue<pii> nextInLine;
stack<char> ord[11];
int main()
{
    int n, k, curCC = -1, r, c, num;
    char og;
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
        fin >> board[i];
    while(true)
    {
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 1010; i ++) cc[i].clear();
        num = 0; curCC = -1;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < 10; j ++)
            {
                if(visited[i][j] || board[i][j] == '0') continue;
                curCC ++;
                nextInLine.push({i, j}); og = board[i][j];
                while(!nextInLine.empty())
                {
                    r = nextInLine.front().f; c = nextInLine.front().s;
                    nextInLine.pop();
                    if(r < 0 || r >= n || c < 0 || c >= 10 || visited[r][c] || board[r][c] != og) continue;
                    visited[r][c] = true;
                    cc[curCC].push_back({r, c});
                    nextInLine.push({r+1, c});
                    nextInLine.push({r-1, c});
                    nextInLine.push({r, c+1});
                    nextInLine.push({r, c-1});
                }
            }
        for(int i = 0; i < 1010; i ++)
            if(cc[i].size() >= k)
            {
                num ++;
                for(pii cur : cc[i])
                    board[cur.f][cur.s] = '0';
            }
        for(int j = 0; j < 10; j ++)
            for(int i = 0; i < n; i ++)
                if(board[i][j] != '0')
                    ord[j].push(board[i][j]);
        for(int i = 0; i < n; i ++) board[i] = "0000000000";
        for(int j = 0; j < 10; j ++)
            for(int i = n-1; i >= 0; i --)
            {
                if(ord[j].empty()) break;
                board[i][j] = ord[j].top();
                ord[j].pop();
            }
        if(num == 0) break;
    }
    for(int i = 0; i < n; i ++)
        fout << board[i] << "\n";
}
