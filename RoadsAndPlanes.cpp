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

const int inf = 2000000000;
vector<pii> adj[25010], plan[25010];
vector<int> topAdj[25010];
int cc[25010], in[25010];
vector<int> ccV[25010];
queue<int> nextInLine;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> ord;
int dist[25010];
int main()
{
    input();
    int n, m, p, beg, a, b, c, curCC = 0, curN, curD;
    cin >> n >> m >> p >> beg; beg--;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    for(int i = 0; i < n; i ++)
    {
        if(cc[i]) continue;
        curCC ++;
        nextInLine.push(i);
        while(!nextInLine.empty())
        {
            curN = nextInLine.front();
            nextInLine.pop();
            if(cc[curN]) continue;
            cc[curN] = curCC; ccV[curCC].push_back(curN);
            for(auto it : adj[curN])
                nextInLine.push(it.f);
        }
    }
    curCC ++;
    for(int i = 0; i < p; i ++)
    {
        cin >> a >> b >> c; a--; b--;
        plan[a].push_back({b, c}); topAdj[cc[a]].push_back(cc[b]); in[cc[b]]++;
    }
    for(int i = 1; i < curCC; i ++)
        if(in[i] == 0)
            nextInLine.push(i);
    while(!nextInLine.empty())
    {
        curN = nextInLine.front();
        nextInLine.pop();
        ord.push_back(curN);
        for(auto it : topAdj[curN])
        {
            in[it] --;
            if(in[it] == 0)
                nextInLine.push(it);
        }
    }
    for(int i = 0; i < n; i ++)
        dist[i] = inf;
    dist[beg] = 0;
    for(auto curC : ord)
    {
        for(auto it : ccV[curC])
            if(dist[it] != inf)
                pq.push({dist[it], it});
        while(!pq.empty())
        {
            curD = pq.top().f; curN = pq.top().s;
            pq.pop();
            if(curD > dist[curN]) continue;
            for(auto it : adj[curN])
                if(curD + it.s < dist[it.f])
                {
                    dist[it.f] = curD + it.s;
                    pq.push({dist[it.f], it.f});
                }
            for(auto it : plan[curN])
                dist[it.f] = min(dist[it.f], dist[curN]+it.s);
        }
    }
    for(int i = 0; i < n; i ++)
        cout << ((dist[i]==inf)?"NO PATH":to_string(dist[i])) << '\n';
}
