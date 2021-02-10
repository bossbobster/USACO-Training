#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

int n, m;
long long mod = 1000000007, p = 7;
long long pw[500010];
long long hsh[500010];
string nums[2][510];
string big;
unordered_set<long long> visited;
void hshs()
{
    hsh[0] = 1;
    for(int i = 0; i < n * 2 * m; i ++)
        hsh[i + 1] = ((hsh[i] * p) % mod + (long long)big[i]) % mod;
}
long long get(int a, int b)
{
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % mod + mod) % mod;
}
int bs(int l, int r)
{
    int mid = (l + r) / 2;
    if(r == mid) return mid;
    for(int j = 0; j < m - mid; j ++)
    {
        bool good = true;
        visited.clear();
        for(int i = 0; i < n; i ++)
            visited.insert(get(i * m + j, i * m + j + mid));
        for(int i = n ; i < n * 2; i ++)
            if(visited.find(get(i * m + j, i * m + j + mid)) != visited.end())
                { good = false; break; }
        if(good) return bs(l, mid);
    }
    return bs(mid + 1, r);
}
int main()
{
    fin >> n >> m;
    big.reserve(n * 2 * m);
    for(int i = 0; i < n * 2; i ++)
    {
        fin >> nums[i / n][i % n];
        big += nums[i / n][i % n];
    }
    pw[0] = 1;
    for(int i = 1; i <= n * 2 * m; i ++)
        pw[i] = (pw[i - 1] * p) % mod;
    hshs();
    fout << bs(0, m - 1) + 1 << "\n";
    return 0;
}
