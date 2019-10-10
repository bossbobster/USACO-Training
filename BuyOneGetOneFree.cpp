#include <iostream>
#include <algorithm>
using namespace std;

int high[50000];
int low[50000];
int main()
{
    int n, m, idx1 = 0, idx2 = 0, total = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> high[i];
    for(int i = 0; i < m; i ++)
        cin >> low[i];
    sort(high, high + n);
    sort(low, low + m);
    total += n;
    while(idx1 < m && idx2 < n)
    {
        if(high[idx2] > low[idx1])
        {
            idx1 ++;
            total ++;
        }
        idx2 ++;
    }
    cout << total << endl;
}
