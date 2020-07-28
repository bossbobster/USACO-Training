#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

pii times[50010];
int main()
{
    int n, cur = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> times[i].second >> times[i].first;
    sort(times, times + n);
    for(int i = 0; i < n; i ++)
    {
        if(times[i].second >= cur)
        {
            ans ++;
            cur = times[i].first;
        }
    }
    cout << ans << "\n";
}
