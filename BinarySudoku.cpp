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

bitset<9> board[9];
bitset<2100000> vis, inq;
queue<pair<int, short>> q;
int cur, og; //8 rows then 4 boxes then 9 columns
int pw[25];
short bits[2100000];
int cntB(int num)
{
    int cnt = 0;
    while(num)
    {
        num &= (num-1);
        cnt++;
    }
    return cnt;
}
int main()
{
    input();
    int n = 9, idx = 0, d;
    for(int i = 0; i < n; i ++)
        cin >> board[i];
    for(int i = 0; i < 2100000; i ++)
        bits[i] = cntB(i);
    pw[0] = 1;
    for(int i = 1; i < 25; i ++)
        pw[i] = pw[i-1]*2;
    for(int i = 0; i < n-1; i ++)
    {
        for(int j = 0; j < n; j ++)
            cur = cur ^ (board[i][j]*pw[idx]);
        idx ++;
    }
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
        {
            for(int k = i*3; k < i*3+3; k ++)
                for(int l = j*3; l < j*3+3; l ++)
                    cur = cur ^ (board[k][l]*pw[idx]);
            idx ++;
        }
    for(int j = 0; j < n; j ++)
    {
        for(int i = 0; i < n; i ++)
            cur = cur ^ (board[i][j]*pw[idx]);
        idx ++;
    }
    q.push({cur, 0});
    while(!q.empty())
    {
        cur = q.front().f; d = q.front().s;
        q.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        if(cur == 0)
        {
            cout << d << '\n';
            return 0;
        }
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
            {
                og = cur;
                if(i < n-1) cur = cur ^ pw[i];
                cur = cur ^ pw[12+j];
                if(i < 6 && j < 6) cur = cur ^ pw[8+(i/3*2)+j/3];
                if(!vis[cur] && !inq[cur] && bits[og] >= bits[cur]) q.push({cur, d+1}), inq[cur] = 1;
                cur = og;
            }
    }
    cout << "-1\n";
    return 0;
}
