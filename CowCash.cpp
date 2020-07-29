#include <iostream>
#include <algorithm>
using namespace std;

int coins[30];
long long vals[10010];
int main()
{
    long long n, k, cur = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> coins[i];
    vals[0] = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= k; j ++)
            if(j - coins[i] >= 0)
                vals[j] += vals[j - coins[i]];
    cout << vals[k] << "\n";
}
