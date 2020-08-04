#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

bool comp(pii p1, pii p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
pii cows[160];
int main()
{
    int n, r1 = 0, r2 = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> cows[i].first >> cows[i].second;
    sort(cows, cows + n, comp);
    for(int i = 0; i < n; i ++)
    {
        if(cows[i].first < r1) continue;
        else if(cows[i].first < r2) { r1 = r2; r2 = cows[i].second; ans ++; }
        else { r2 = cows[i].second; ans ++; }
    }
    cout << ans << "\n";
}
