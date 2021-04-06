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

ifstream fin("hamming.in");
ofstream fout("hamming.out");

int n, b, d;
vector<int> ans;
int main()
{
    fin >> n >> b >> d;
    bool good;
    ans.push_back(0);
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < (1 << b); j ++)
        {
            if(ans.size() == n) break;
            good = true;
            for(int k = 0; k < ans.size(); k ++)
                if(bitset<10>(ans[k] ^ j).count() < d) { good = false; break; }
            if(good) ans.push_back(j);
        }
    for(int i = 0; i < ans.size(); i ++)
        fout << ans[i] << (((i%10)==9 || (i == ans.size()-1))?"\n":" ");
}
