#include <iostream>
#include <algorithm>
using namespace std;

int startArr[20010];
int endArr[20010];
int main()
{
    int n, t1, t2, t3, maxNum = 0, num = 0, cntStarts = 0, cntEnds = 0, lower = 0, same = 0, higher = 0;
    cin >> n >> t3 >> t2 >> t1;
    for(int i = 0; i < n; i ++)
        cin >> startArr[i] >> endArr[i];
    sort(startArr, startArr + n);
    sort(endArr, endArr + n);
    while(cntEnds < n)
    {
        if(cntStarts < n)
        {
            if(startArr[cntStarts] <= endArr[cntEnds])
            {
                cntStarts ++;
                num ++;
            }
            else
                cntEnds ++;
        }
        else
            cntEnds ++;
        same = num;
        higher = n - (same + lower);
        maxNum = max(maxNum, lower * t1 + same * t2 + higher * t3);
        if(startArr[cntStarts] > endArr[cntEnds])
        {
            num --;
            lower ++;
        }
    }
    cout << maxNum;
}
