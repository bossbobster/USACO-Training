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
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
//#define cin fin

vector<int> adj[510];
bitset<510> pos[510], vis;
queue<int> q;
int main()
{
    input();
    int n, num;
    bool b;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        b = true;
        for(int j = 0; j < n; j ++)
        {
            cin >> num; num --;
            if(b) adj[i].push_back(num);
            if(num == i) b = false;
        }
    }
    for(int i = 0; i < n; i ++)
    {
        q.push(i);
        vis.reset();
        while(!q.empty())
        {
            num = q.front();
            q.pop();
            if(vis[num]) continue;
            vis[num] = 1;
            pos[i][num] = 1;
            for(auto it : adj[num])
                q.push(it);
        }
    }
    for(int i = 0; i < n; i ++)
        for(auto cur : adj[i])
            if(pos[cur][i])
            {
                cout << cur+1 << '\n';
                break;
            }
}
