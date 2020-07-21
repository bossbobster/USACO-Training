#include <iostream>
#include <algorithm>
using namespace std;

int w[1010];
int ans = 2000000000;
int n, c;
void rec(int idx, int cap)
{
    if(cap >= 0) ans = min(ans, cap);
    if(idx == n) return;
    if(idx == n - 1)
    {
        if(cap > w[idx]) cap -= w[idx];
        ans = min(ans, cap);
        return;
    }
    if(w[idx] + w[idx + 1] <= cap) return rec(idx + 1, cap - w[idx]);
    else if(w[idx] > cap) return rec(idx + 1, cap);
    else
    {
        rec(idx + 2, cap - w[idx]);
        rec(idx + 2, cap - w[idx + 1]);
    }
}
int main()
{
    cin >> n >> c;
    for(int i = 0; i < n; i ++)
        cin >> w[i];
    sort(w, w + n, greater<int>());
    rec(0, c);
    cout << c - ans << "\n";
}
