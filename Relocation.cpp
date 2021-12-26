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

int n, m, k, curN, curD, one, two, three;
int len[10][10010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[10010];
bitset<10010> mark, used;
vector<int> mar;
vector<int> cur;
int ans = 2000000000, curA;
void printAll(int cnt)
{
    if(cnt == k)
    {
        curA = 0;
        for(int i = 1; i < cur.size(); i ++)
            curA += len[cur[i]][((i==1)?cur[i-1]:mar[cur[i-1]])];
        ans = min(ans, curA+len[cur[cur.size()-1]][cur[0]]);
        return;
    }
    for(int i = 0; i < k; i ++)
    {
        if(used[i]) continue;
        cur.push_back(i); used[i] = true;
        printAll(cnt + 1);
        cur.pop_back(); used[i] = false;
    }
}
int main()
{
    input();
    cin >> n >> m >> k;
    for(int i = 0; i < k; i ++)
    {
        cin >> one; one --;
        mark[one] = 1; mar.push_back(one);
    }
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        adj[one-1].push_back({two-1, three});
        adj[two-1].push_back({one-1, three});
    }
    for(int j = 0; j < k; j ++)
        for(int i = 0; i < n; i ++)
            len[j][i] = 2000000000;
    for(int j = 0; j < k; j ++)
    {
        nextInLine.push({0, mar[j]});
        len[j][mar[j]] = 0;
        while(!nextInLine.empty())
        {
            curD = nextInLine.top().f; curN = nextInLine.top().s;
            nextInLine.pop();
            if(len[j][curN] < curD) continue;
            for(int i = 0; i < adj[curN].size(); i ++)
                if(len[j][curN] + adj[curN][i].s < len[j][adj[curN][i].f])
                {
                    len[j][adj[curN][i].f] = len[j][curN] + adj[curN][i].s;
                    nextInLine.push({len[j][adj[curN][i].f], adj[curN][i].f});
                }
        }
    }
    for(int i = 0; i < n; i ++)
        if(!mark[i])
        {
            cur.clear();
            cur.push_back(i);
            printAll(0);
        }
    cout << ans << '\n';
}
