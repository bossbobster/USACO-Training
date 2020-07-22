#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<pair<int, int>> s;
int nums[50010][2];
int vol[50010];
int ans = 0;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i][0] >> nums[i][1];
    for(int i = 0; i < n; i ++)
    {
        while(!s.empty())
        {
            if(s.top().first < nums[i][0])
            {
                vol[i] += s.top().second;
                s.pop();
            }
            else break;
        }
        s.push(pair<int, int>(nums[i][0], nums[i][1]));
    }
    while(!s.empty()) s.pop();
    for(int i = n - 1; i >= 0; i --)
    {
        while(!s.empty())
        {
            if(s.top().first < nums[i][0])
            {
                vol[i] += s.top().second;
                s.pop();
            }
            else break;
        }
        s.push(pair<int, int>(nums[i][0], nums[i][1]));
        ans = max(ans, vol[i]);
    }
    cout << ans << "\n";
}
