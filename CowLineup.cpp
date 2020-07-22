#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

pair<int, int> cows[50010];
unordered_set<int> in;
unordered_set<int> breeds;
unordered_map<int, int> cnt;
int main()
{
    int n, idx = 0, ans;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> cows[i].first >> cows[i].second;
        breeds.insert(cows[i].second);
    }
    sort(cows, cows + n);
    while(in.size() != breeds.size())
    {
        in.insert(cows[idx].second);
        cnt[cows[idx].second] ++;
        idx ++;
    }
    ans = cows[idx - 1].first - cows[0].first;
    for(int i = 0; i < n - 1 && idx <= n; i ++)
    {
        cnt[cows[i].second] --;
        if(cnt[cows[i].second] == 0)
        {
            in.erase(cows[i].second);
            while(in.size() != breeds.size())
            {
                if(idx >= n) break;
                in.insert(cows[idx].second);
                cnt[cows[idx].second] ++;
                idx ++;
            }
        }
        if(in.size() != breeds.size()) break;
        ans = min(ans, cows[idx - 1].first - cows[i + 1].first);
    }
    cout << ans << "\n";
}
