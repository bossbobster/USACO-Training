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

ifstream fin("cowdate.in");
ofstream fout("cowdate.out");

ld nums[1000010], pre1[1000010], pre2[1000010];
ld get(int l, int r)
{
    return pre1[r+1]/pre1[l]*(pre2[r+1]-pre2[l]);
}
int main()
{
    input();
    int n, num;
    ld ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> num, nums[i] = (ld)num/1000000.0;
    pre1[0] = 1.0;
    for(int i = 0; i < n; i ++)
        pre1[i+1] = (1-nums[i])*pre1[i];
    pre2[0] = 0.0;
    for(int i = 0; i < n; i ++)
        pre2[i+1] = pre2[i] + (nums[i]/(1-nums[i]));
    int idxL = 0, idxR = 0;
    while(idxL < n)
    {
        while(idxR < n && pre2[idxR+1]-pre2[idxL] < 1) idxR ++;
        ans = max(ans, get(idxL, idxR));
        idxL ++;
    }
    fout << (int)(ans*1000000) << '\n';
}
