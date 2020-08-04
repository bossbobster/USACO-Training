#include <iostream>
#include <algorithm>
using namespace std;

int m[25010];
int b[25010];
int main()
{
    int n, x, y, ans = 0;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i ++)
        cin >> m[i] >> b[i];
    sort(m, m + n);
    sort(b, b + n);
    for(int i = 0; i < n; i ++)
    {
        if(m[i] <= b[i]) ans += (b[i] - m[i]) * x;
        else ans += (m[i] - b[i]) * y;
    }
    cout << ans << "\n";
}
