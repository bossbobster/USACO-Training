#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, t, ans = 2000000000;
priority_queue<int, vector<int>, greater<int>> q;
int cows[10010];
bool visited[10010];
void bs(int l, int r)
{
    int k = (l + r) / 2;
    if(visited[k]) return bs(l + 1, r);
    visited[k] = true;
    int sum = 0;
    if(l <= r && l <= n && r <= n + 1)
    {
        while(!q.empty()) q.pop();
        for(int i = 0; i < k; i ++)
            q.push(cows[i]);
        for(int i = k; i < n; i ++)
        {
            sum = max(sum, q.top());
            q.pop();
            q.push(cows[i] + sum);
        }
        while(!q.empty())
        {
            sum = q.top();
            q.pop();
        }
        if(sum <= t)
        {
            ans = min(ans, k);
            return bs(l, k);
        }
        return bs(k, r);
    }
}
int main()
{
    cin >> n >> t;
    for(int i = 0; i < n; i ++)
        cin >> cows[i];
    bs(0, n + 1);
    cout << ans << "\n";
}
