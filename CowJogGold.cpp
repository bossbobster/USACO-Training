#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pii;

pii cows[100010];
long long groups[100010];
int main()
{
    long long n, t, dist, ans = 1;
    cin >> n >> t;
    for(int i = 0; i < n; i ++)
        cin >> cows[i].first >> cows[i].second;
    for(int i = n - 1; i >= 0; i --)
    {
        dist = cows[i].first + (cows[i].second * t);
        groups[i] = dist;
        if(i != n - 1) if(groups[i] > groups[i + 1]) groups[i] = groups[i + 1];
    }
    for(int i = 1; i < n; i ++)
        if(groups[i] != groups[i - 1])
            ans ++;
    cout << ans << "\n";
}
