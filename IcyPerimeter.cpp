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

ifstream fin("perimeter.in");
ofstream fout("perimeter.out");

string board[1010];
bool visited[1010][1010];
queue<pii> nextInLine;
int main()
{
    int n, curA, curP, r, c, a = 0, p = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> board[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            if(visited[i][j] || board[i][j] == '.') continue;
            curA = curP = 0;
            nextInLine.push({i, j});
            while(!nextInLine.empty())
            {
                r = nextInLine.front().f; c = nextInLine.front().s;
                nextInLine.pop();
                if(r < 0 || r >= n || c < 0 || c >= n || visited[r][c] || board[r][c] == '.') continue;
                visited[r][c] = true;
                curA ++;
                if(r+1 >= n || board[r+1][c] == '.') curP++;
                if(r-1 < 0 || board[r-1][c] == '.') curP++;
                if(c+1 >= n || board[r][c+1] == '.') curP++;
                if(c-1 < 0 || board[r][c-1] == '.') curP++;
                nextInLine.push({r+1, c});
                nextInLine.push({r-1, c});
                nextInLine.push({r, c+1});
                nextInLine.push({r, c-1});
            }
            if(curA > a) { a = curA; p = curP; }
            else if(curA == a) p = min(p, curP);
        }
    fout << a << " " << p << "\n";
}
