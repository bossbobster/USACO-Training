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

ifstream fin("closing.in");
ofstream fout("closing.out");

vector<int> adj[3010];
stack<int> ord;
stack<string> ans;
bool good[3010];
int cc[3010];
queue<int> nextInLine;
int main()
{
    int n, m, a, b, cur, curN;
    fin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 0; i < n; i ++)
    {
        fin >> a; a--;
        ord.push(a);
    }
    while(!ord.empty())
    {
        good[ord.top()] = true; ord.pop();
        memset(cc, 0, sizeof(cc)); cur = 0;
        for(int i = 0; i < n; i ++)
        {
            if(cc[i] || !good[i]) continue;
            cur ++;
            nextInLine.push(i);
            while(!nextInLine.empty())
            {
                curN = nextInLine.front();
                nextInLine.pop();
                if(cc[curN]) continue;
                cc[curN] = cur;
                for(auto it : adj[curN])
                    if(good[it])
                        nextInLine.push(it);
            }
        }
        if(cur == 1) ans.push("YES");
        else ans.push("NO");
    }
    while(!ans.empty()) { fout << ans.top() << "\n"; ans.pop(); }
}
