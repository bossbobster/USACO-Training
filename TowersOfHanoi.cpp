#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

vector<pii> ans;
void rec(int n, int fir, int sec, int thi)
{
    if(n == 1)
    {
        ans.push_back({fir, thi});
        return;
    }
    rec(n - 1, fir, thi, sec);
    ans.push_back({fir, thi});
    rec(n - 1, sec, fir, thi);
}
int main()
{
    int n;
    cin >> n;
    rec(n, 1, 2, 3);
    cout << ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); i ++)
        cout << ans[i].f << " " << ans[i].s << "\n";
}
