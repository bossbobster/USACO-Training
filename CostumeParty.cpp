#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int power(int base, int exp)
{
    int result = 1;
    for(int i = 0; i < exp; i ++)
        result *= base;
    return result;
}

int cows[100000];
int n, s;
int binarySearch(int number)
{
    int place = n / 2, cnt = 2, finalI = 0;
    while(cnt <= log2(n) + 2)
    {
        if(cows[place] + cows[number] <= s)
            if(place > finalI)
                finalI = place;
        if(cows[number] + cows[place] > s)
            place -= ceil((float)n / power(2, cnt));
        else
            place += ceil((float)n / power(2, cnt));
        if(place < 0)
            place = 0;
        if(place >= n)
            place = n - 1;
        cnt ++;
    }
    if(finalI > number)
        return finalI - number;
    else
        return 0;
}
int main()
{
    cin >> n >> s;
    int total = 0;
    for(int i = 0; i < n; i ++)
        cin >> cows[i];
    sort(cows, cows + n);
    for(int i = 0; i < n; i ++)
        total += binarySearch(i);
    cout << total;
}
