#include <iostream>
#include <algorithm>
using namespace std;

int places[1000];
int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> places[i];
    sort(places, places + n);
    for(int i = 0; i < n - 2; i ++)
        for(int j = i + 1; j < n - 1; j ++)
            ans += (upper_bound(places, places + n, places[j] + ((places[j] - places[i]) * 2)) - lower_bound(places, places + n, places[j] + (places[j] - places[i]))); 
    cout << ans;
}
