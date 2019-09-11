#include <iostream>
#include <algorithm>
using namespace std;

int hayBales[1000000];
int lr[2][1000000];
int main()
{
    int n, k, idx = 0, cntL = 1, cntR = 0, height = 0;
    cin >> n >> k;
    for(int i = 0; i < k; i ++)
        cin >> lr[0][i] >> lr[1][i];
    sort(lr[0], lr[0] + k);
    sort(lr[1], lr[1] + k);
    
    while(idx < n)
    {
        while(lr[0][cntL] == idx)
        {
            height ++;
            cntL ++;
        }
        hayBales[idx] = height;
        while(lr[1][cntR] == idx)
        {
            height --;
            cntR ++;
        }
        idx ++;
    }
    sort(hayBales, hayBales + n);
    cout << hayBales[n / 2] + 1;
}
