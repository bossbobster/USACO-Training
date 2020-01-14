#include <iostream>
using namespace std;

int buckets[21];
bool used[21];
int c, b, ans = 0;
void findAll(int nn, int n1, int idx, int m, int total)
{
    if(n1 == 0)
    {
        if(total <= c) ans = max(ans, total);
        return;
    }
    for(int i = nn - n1 + idx; i < nn - n1 + m - nn + 1; i ++)
    {
        if(used[i]) continue;
        total += buckets[i];
        used[i] = true;
        findAll(nn, n1 - 1, idx, m, total);
        idx ++;
        total -= buckets[i];
        used[i] = false;
    }
}

int main()
{
    cin >> c >> b;
    for(int i = 0; i < b; i ++)
        cin >> buckets[i];
    for(int i = 1; i <= b; i ++) 
    {
        findAll(i, i, 0, b, 0);
    }
    cout << ans;
}
