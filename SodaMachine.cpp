#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

bool comp(pii p1, pii p2)
{
    if(p1.first == p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
}
pii points[100010];
int main()
{
    int n, one, two, num = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n * 2; i += 2)
    {
        cin >> one >> two;
        points[i].first = one; points[i].second = 1;
        points[i + 1].first = two; points[i + 1].second = -1;
    }
    sort(points, points + n * 2, comp);
    for(int i = 0; i < n * 2; i ++)
    {
        num += points[i].second;
        ans = max(ans, num);
    }
    cout << ans << "\n";
}
