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
//#define cin fin
//ifstream fin("/Users/bobby/prob1_platinum_feb21/20.in");

int main()
{
    input();
    ll n, cur = 0, ans = 0, ansans = 2000000000, a, b, num, x;
    bool done = false;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        ans = 0; done = false; ansans = 2000000000;
        while(a > 0)
        {
            if(a <= b)
            {
                num = b;
                x = 0;
                while(num / 2 >= a)
                    num /= 2, x ++;
                x --;
                cur = ans + (num - a);
                while(num < b)
                {
                    num *= 2; cur ++;
                    if((b >> x) & 1) num ++, cur ++;
                    x --;
                }
                ansans = min(ansans, cur);
            }
            if(a & 1) a++, ans ++;
            a /= 2; ans ++;
            if(done) break;
            if(a == 1) done = true;
        }
        cout << ansans << '\n';
    }
}
