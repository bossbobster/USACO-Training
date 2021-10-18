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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
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
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int nums[3000010];
int main()
{
    input();
    int n, k, x, y, a, b, cur = 0;
    cin >> n >> k;
    while(k--)
    {
        cin >> x >> y >> a >> b;
        for(int i = 1; i <= y; i ++)
            nums[((ll)(a%n)*(ll)(i%n)+(ll)(b%n)) % n] += x;
    }
    for(int i = 0; i < n; i ++)
    {
        cur += nums[i];
        if(cur > 0) nums[i] = 1, cur --;
    }
    for(int i = 0; i < n; i ++)
    {
        if(cur > 0 && !nums[i]) nums[i] = 1, cur --;
        else if(!nums[i])
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}
