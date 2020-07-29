#include <iostream>
#include <algorithm>
using namespace std;

int coins[20];
int vals[1010];
int main()
{
    int n, k;
    cin >> k >> n;
    for(int i = 0; i < n; i ++)
        cin >> coins[i];
    vals[0] = 0;
    for(int i = 1; i <= k; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(i - coins[j] > -1)
            {
                if(vals[i] == 0)
                    vals[i] = vals[i - coins[j]] + 1;
                if(vals[i - coins[j]] + 1 < vals[i])
                    vals[i] = min(vals[i], vals[i - coins[j]] + 1);
            }
        }
    }
    cout << vals[k] << "\n";
}
