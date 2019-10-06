#include <iostream>
#include <algorithm>
using namespace std;

int startArr[100000];
int endArr[100000];
int main()
{
    int n, k, t1, cur = 0, cntStarts = 0, cntEnds = 0, prev, total = 0, num = 0;
    char t2;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> t1 >> t2;
        if(t2 == 'R')
        {
            startArr[i] = cur;
            endArr[i] = cur + t1;
            cur += t1;
        }
        else
        {
            startArr[i] = cur - t1;
            endArr[i] = cur;
            cur -= t1;
        }
    }
    sort(startArr, startArr + n);
    sort(endArr, endArr + n);
    while(cntEnds < n)
    {
        if(cntStarts < n)
        {
            if(startArr[cntStarts] <= endArr[cntEnds])
            {
                if(num >= k)
                    total += (startArr[cntStarts] - prev);
                cntStarts ++;
                num ++;
                prev = startArr[cntStarts - 1];
            }
            else
            {
                if(num >= k)
                    total += (endArr[cntEnds] - prev);
                cntEnds ++;
                num --;
                prev = endArr[cntEnds - 1];
            }
        }
        else
        {
            if(num >= k)
                total += (endArr[cntEnds] - prev);
            cntEnds ++;
            num --;
            prev = endArr[cntEnds - 1];
        }
    }
    cout << total;
}
