//This is not a USACO problem

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int coins[10000];
int vals[10000000];
vector<int> path;
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> coins[i];
    vals[0] = 0;
    path.push_back(0);
    for(int i = 1; i <= k; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(i - coins[j] > -1)
            {
                if(vals[i] == 0)
                {
                    vals[i] = vals[i - coins[j]] + 1; path.push_back(coins[j]);
                }
                if(vals[i - coins[j]] + 1 < vals[i])
                {
                    vals[i] = min(vals[i], vals[i - coins[j]] + 1); path.pop_back();
                    path.push_back(coins[j]);
                }
            }
        }
    }
    cout << vals[k] << "\n";
    while(k > 0)
    {
        cout << path[k] << " ";
        k -= path[k];
    }
    cout << "\n";
}
