#include <iostream>
#include <algorithm>
using namespace std;

short bessie[1000010];
short elsie[1000010];
int main()
{
    int b, e, curB = 0, curE = 0, tmp, idx = 0, total = 0;
    bool already = true;
    char tmpC;
    cin >> b >> e;
    for(int i = 0; i < b; i ++)
    {
        cin >> tmp >> tmpC;
        for(int j = 0; j < tmp; j ++)
        {
            bessie[idx] = tmpC == 'R'?1:-1;
            idx ++;
        }
    }
    idx = 0;
    for(int i = 0; i < e; i ++)
    {
        cin >> tmp >> tmpC;
        for(int j = 0; j < tmp; j ++)
        {
            elsie[idx] = tmpC == 'R'?1:-1;
            idx ++;
        }
    }
    idx = 0;
    while(bessie[idx] != 0 || elsie[idx] != 0)
    {
        curB += bessie[idx];
        if(curB == curE && !already) {total ++; already = true;}
        curE += elsie[idx];
        if(curB == curE && !already) {total ++; already = true;}
        if(curB != curE) already = false;
        idx ++;
    }
    cout << total;
}
