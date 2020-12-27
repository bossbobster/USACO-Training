#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool dp[1000010];
int qs[110];
int main()
{
    int g, maxN = 0, tmp, big, small;
    cin >> g;
    for(int i = 0; i < g; i ++)
    {
        cin >> qs[i];
        maxN = max(maxN, qs[i]);
    }
    dp[0] = 0;
    for(int i = 1; i <= maxN; i ++)
    {
        tmp = i;
        big = 0; small = 10;
        while(tmp != 0)
        {
            big = max(big, tmp % 10);
            if(tmp % 10 != 0) small = min(small, tmp % 10);
            tmp /= 10;
        }
        dp[i] = !dp[i - big] | !dp[i - small];
    }
    for(int i = 0; i < g; i ++)
        cout << ((dp[qs[i]])?"YES":"NO") << "\n";
}
