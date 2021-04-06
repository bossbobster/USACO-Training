#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("subset.in");
ofstream fout("subset.out");

ll dp[1010];
int main()
{
    int n, sum;
    fin >> n;
    if(n % 4 == 2 || n % 4 == 1) { fout << 0 << "\n"; return 0; }
    sum = n * (n + 1) / 2;
    for(int i = 0; i < sum; i ++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 1; i < n; i ++)
        for(int j = sum; j >= i; j --)
            dp[j] += dp[j - i];
    fout << dp[sum / 2] << "\n";
}
