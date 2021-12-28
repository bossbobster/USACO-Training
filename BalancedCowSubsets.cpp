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
#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

int n, sum = 0, cnt = 0;
gp_hash_table<int, null_type> ans;
bitset<11> cur;
int nums[30];
gp_hash_table<int, set<int>> m;
void make(int which)
{
    if(cnt == ((which==0)?n/2:n))
    {
        if(which == 0)
            m[sum].insert(cur.to_ulong());
        if(which == 1)
            //if(sum >= 0)
                for(auto it : m[-sum])
                    ans.insert(it*(1<<(n/2+1))+cur.to_ulong());
        return;
    }
    sum += nums[cnt]; cur.flip(cnt-((which==0)?0:n/2)); cnt ++;
    make(which);
    cnt --; cur.flip(cnt-((which==0)?0:n/2)); sum -= nums[cnt];
    cnt ++;
    make(which);
    cnt --;
    sum -= nums[cnt]; cur.flip(cnt-((which==0)?0:n/2)); cnt ++;
    make(which);
    cnt --; cur.flip(cnt-((which==0)?0:n/2)); sum += nums[cnt];
}
int main()
{
    input();
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    make(0);
    sum = 0; cur.reset(); cnt = n/2;
    make(1);
    cout << ans.size()-1 << '\n';
}
