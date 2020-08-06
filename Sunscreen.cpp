#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

bool comp(pii p1, pii p2)
{
    return p1.second < p2.second;
}
pii cows[3000];
pii suns[3000];
int main()
{
    int c, l, ans = 0;
    cin >> c >> l;
    for(int i = 0; i < c; i ++)
        cin >> cows[i].first >> cows[i].second;
    for(int i = 0; i < l; i ++)
        cin >> suns[i].first >> suns[i].second;
    sort(cows, cows + c, comp);
    sort(suns, suns + l);
    for(int i = 0; i < c; i ++)
        for(int j = 0; j < l; j ++)
            if(suns[j].first >= cows[i].first && suns[j].first <= cows[i].second && suns[j].second > 0)
            {
                ans ++;
                suns[j].second --;
                break;
            }
    cout << ans << "\n";
}
