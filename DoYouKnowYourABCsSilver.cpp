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
typedef pair<uint, uint> puint;
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
//#define cout fout

bitset<3> bits[7] = {1, 2, 4, 3, 5, 6, 7}; //001, 010, 100, 011, 101, 110, 111
ll nums[7];
bitset<7> used;
int n, m;
vector<bitset<3>> cur;
unordered_map<bitset<3>, ll> mp;
set<pair<pll, ll>> st;
void printAll(int cnt)
{
    if(cnt == n)
    {
        mp.clear();
        for(int i = 0; i < n; i ++)
            mp[cur[i]] = nums[i];
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
            {
                if(i == j) continue;
                if(max(cur[i].to_ulong(), cur[j].to_ulong()) == (cur[i].to_ulong() | cur[j].to_ulong()))
                {
                    if(mp[cur[i]^cur[j]] != 0 && mp[cur[i]^cur[j]] != max(mp[cur[i]], mp[cur[j]]) - min(mp[cur[i]], mp[cur[j]]))
                        return;
                    if(cur[i].to_ulong() > cur[j].to_ulong() && mp[cur[i]] <= mp[cur[j]])
                        return;
                    if(cur[i].to_ulong() < cur[j].to_ulong() && mp[cur[i]] >= mp[cur[j]])
                        return;
                    mp[cur[i]^cur[j]] = max(mp[cur[i]], mp[cur[j]]) - min(mp[cur[i]], mp[cur[j]]);
                }
            }
        ll a, b, c;
        a = min({mp[bits[0]], mp[bits[1]], mp[bits[2]]});
        c = max({mp[bits[0]], mp[bits[1]], mp[bits[2]]});
        b = mp[bits[0]]+mp[bits[1]]+mp[bits[2]]-a-c;
        if((mp[bits[6]] != 0 && a+b+c != mp[bits[6]]) || (mp[bits[3]] != 0 && a+b != mp[bits[3]]) || (mp[bits[4]] != 0 && a+c != mp[bits[4]]) || (mp[bits[5]] != 0 && b+c != mp[bits[5]]))
            return;
        if(a > 0 && b > 0 && c > 0)
            st.insert({{a, b}, c});
        return;
    }
    for(int i = 0; i < m; i ++)
    {
        if(used[i]) continue;
        cur.push_back(bits[i]); used[i] = true;
        printAll(cnt+1);
        cur.pop_back(); used[i] = false;
    }
}
int main()
{
    input();
    int t;
    cin >> t;
    m = 7;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i ++)
            cin >> nums[i];
        st.clear();
        printAll(0);
        cout << st.size() << '\n';
    }
}
