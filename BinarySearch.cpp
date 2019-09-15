#include <iostream>
#include <math.h>
using namespace std;

int nums[100000];
int n, q, curQ;
int binarySearch(int number)
{
    int place = n / 2, cnt = 2, finalI = 1000000;
    while(cnt <= log2(n) + 2)
    {
        if(nums[place] == number)
            if(place < finalI)
                finalI = place;
        if(number <= nums[place])
            place -= ceil((float)n / pow(2, cnt));
        else
            place += ceil((float)n / pow(2, cnt));
        if(place < 0)
            place = 0;
        if(place >= n)
            place = n - 1;
        cnt ++;
    }
    if(finalI == 1000000)
        return -1;
    return finalI;
}

int finalL[100000];
int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < q; i ++)
    {
        cin >> curQ;
        finalL[i] = binarySearch(curQ);
    }
    for(int i = 0; i < q; i ++)
        cout << finalL[i] << endl;
}
