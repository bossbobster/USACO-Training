#include <iostream>
#include <fstream>
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
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("deleg.in");
ofstream fout("deleg.out");

int n;
vector<int> adj[100010];
int sz[100010];
int m[100010];
vector<int> nums[100010];
void calcSZ(int cur, int par)
{
    sz[cur] = 1;
    for(auto nx : adj[cur])
        if(nx != par)
        {
            calcSZ(nx, cur);
            sz[cur] += sz[nx];
            nums[cur].push_back(sz[nx]);
        }
    nums[cur].push_back(n - sz[cur]);
}
int main()
{
    int one, two, cnt, len;
    bool good;
    fin >> n;
    for(int i = 0; i < n - 1; i ++)
    {
        fin >> one >> two; one --; two --;
        adj[one].push_back(two); adj[two].push_back(one);
    }
    calcSZ(0, -1);
    for(int a = 1; a < n; a ++)
    {
        if((n - 1) % a != 0) { fout << 0; continue; }
        for(int i = 0; i <= a; i ++)
            m[i] = 0;
        good = true;
        for(int i = 0; i < n; i ++)
        {
            cnt = 0;
            for(auto nx : nums[i])
            {
                len = nx % a;
                if(len == 0) continue;
                if(m[a - len]) { m[a - len] --; cnt --; }
                else { m[len] ++; cnt ++; }
            }
            if(cnt != 0) { good = false; break; }
        }
        if(good) fout << 1;
        else fout << 0;
    }
    fout << "\n";
}
