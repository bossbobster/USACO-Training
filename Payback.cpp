#include <iostream>
using namespace std;

int cows[100000];
int main()
{
    int n, cur = 0, debtIdx = -1, debt = 0, total = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> cows[i];
    for(int i = 0; i < n; i ++)                                     
    {
        if(cows[i] < 0)
        {
            if(cows[i] + cur >= 0) 
            {
                cur += cows[i];
                total ++;
            }
            else
            {
                debt += cows[i];
                total ++;
                if(debtIdx == -1)
                    debtIdx = i;
            }
        }
        else
        {
            total ++;
            cur += cows[i];
            if(cur + debt >= 0 && debt != 0 && debtIdx != -1)
            {
                cur += debt;
                debt = 0;
                total += (i - debtIdx) * 2;
                debtIdx = -1;
            }
        }
    }
    if(debtIdx != -1)
        total += (n - debtIdx - 1) * 2;
    cout << total;  
}
