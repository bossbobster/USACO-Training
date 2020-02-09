#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans = 0, val = 0;
int coins[8];
int possible[8][310];

void findAll(int idx)
{
    if(val > k) return;
    if(val == k) { ans ++; return; }
    for(int i = idx; i < n; i ++)
    {
        if(!possible[i][val]) continue;
        val += coins[i];
        if(val <= k) findAll(i);
        val -= coins[i];
    }
}

int main()
{
    cin >> k >> n;
    for(int i = 0; i < n; i ++)
        cin >> coins[i];
    sort(coins, coins + n);
    for(int i = 0; i < n; i ++)
    {
        possible[i][k] = true;
        for(int j = k; j >= 0; j --)
            for(int l = i; l < n; l ++)
                if(j + coins[l] <= k)
                    if(possible[i][j + coins[l]])
                        possible[i][j] = true;
    }
    for(int i = 0; i < n; i ++)
    {
        if(!possible[i][0]) continue;
        val += coins[i];
        findAll(i);
        val -= coins[i];
    }
    cout << ans << endl;
}
