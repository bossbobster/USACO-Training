#include <iostream>
#include <math.h>
using namespace std;

int nums[50000];
int n, q, num, cur = 0;
int binarySearch(int number)
{
    int place = n / 2, cnt = 2, finalI = 1000000;
    while(cnt <= log2(n) + 2)
    {
        if(nums[place] > number)
            if(place < finalI)
                finalI = place;
        if(number < nums[place])
            place -= ceil((float)n / pow(2, cnt));
        else
            place += ceil((float)n / pow(2, cnt));
        if(place < 0)
            place = 0;
        if(place >= n)
            place = n - 1;
        cnt ++;
    }
    return finalI;
}
int finalL[50000];
int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> num;
        cur += num;
        nums[i] = cur;
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> num;
        finalL[i] = binarySearch(num);
    }
    for(int i = 0; i < q; i ++)
        cout << finalL[i] + 1 << endl;
}
