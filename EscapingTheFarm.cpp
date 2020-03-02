#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0;
int sums[20];
int og[20];
int cows[20];
bool used[20];
int cur[20];
bool good = true;
void printAll(int n1, int nn, int idx)
{
    if(n1 == 0)
    {
        for(int i = 0; i < n; i ++)
            sums[i] = 0;
        good = true;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < nn; j ++)
            {
                sums[i] += cows[cur[j]] % 10;
                cows[cur[j]] /= 10;
            }
        for(int i = 0; i < n; i ++)
            if(sums[i] >= 10) good = false;
        if(good) ans = max(ans, nn);
        for(int i = 0; i < n; i ++) cows[i] = og[i];
        return;
    }
    for(int i = nn - n1 + idx; i < n - n1 + 1; i ++)
    {
        if(used[i]) continue;
        cur[nn - n1] = i;
        used[i] = true;
        printAll(n1 - 1, nn, idx);
        idx ++;
        cur[n - n1] = 0;
        used[i] = false;
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> cows[i]; og[i] = cows[i];
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j < n; j ++) cows[j] = og[j];
        printAll(i, i, 0);
    }
    cout << ans << endl;
}
