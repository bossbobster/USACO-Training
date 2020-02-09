#include <iostream>
using namespace std;

int ans = 0, n;
int cows[2200];

void findPairs(int l, int r)
{
    if(r - l == 2) { ans += (cows[l] * cows[l + 1]); return; }
    if(r - l <= 1) return;
    findPairs(l, (r - l + 1) / 2 + l);
    findPairs((r - l + 1) / 2 + l, r);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cows[i] = i + 1;
    findPairs(0, n);
    cout << ans << endl;
}
