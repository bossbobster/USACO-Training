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

ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

vector<int> adj[100010];
queue<int> nextInLine;
int cc[100010];
int main()
{
    input();
    int n, m, a, b, cur = 0, curN;
    char ch;
    string st;
    fin >> n >> m >> st;
    for(int i = 0; i < n-1; i ++)
    {
        fin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
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
                if(st[curN] == st[it])
                    nextInLine.push(it);
        }
    }
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b >> ch; a--; b--;
        if(cc[a] == cc[b] && st[a] != ch) fout << 0;
        else fout << 1;
    }
    fout << "\n";
}
