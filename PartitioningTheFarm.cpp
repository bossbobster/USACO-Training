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

int nums[20][20];
int sumC[20], sumR[20];
set<pii> bestR[20];
int sums[20];
int main()
{
    input();
    int n, k, sum, mx, ans = 2000000000, cur;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> nums[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            sumR[i] += nums[i][j], sumC[j] += nums[i][j];
    for(int i = 0; i < (1<<(n-1)); i ++)
    {
        sum = sumR[0]; mx = 0;
        for(int j = 0; j < n-1; j ++)
        {
            if(i & (1<<j))
                mx = max(mx, sum), sum = 0;
            sum += sumR[j+1];
        }
        int idx = ((bitset<20>)i).count();
        mx = max(mx, sum);
        if(bestR[idx].size() < 101 || (mx < prev(bestR[idx].end())->f))
        {
            if(bestR[idx].size() >= 100)
                bestR[idx].erase(prev(bestR[idx].end()));
            bestR[idx].insert({mx, i});
        }
    }
    for(int i = 0; i < (1<<(n-1)); i ++)
    {
        if(((bitset<20>)i).count() > k) continue;
        for(auto itt : bestR[min(n-1, (int)k-(int)((bitset<20>)i).count())])
        {
            cur = itt.s;
            int idx = 0;
            memset(sums, 0, sizeof(sums)); mx = 0;
            for(int r = 0; r < n; r ++)
            {
                idx = 0;
                for(int c = 0; c < n; c ++)
                {
                    sums[idx] += nums[r][c];
                    if(i & (1<<c))
                        idx ++;
                }
                if(cur & (1<<r))
                {
                    for(auto it : sums)
                        mx = max(mx, it);
                    memset(sums, 0, sizeof(sums));
                }
            }
            for(auto it : sums)
                mx = max(mx, it);
            ans = min(ans, mx);
        }
    }
    cout << ans << '\n';
}
