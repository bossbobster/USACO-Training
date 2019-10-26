//I used prefix sums and calculated the number of ones and zeros that needed change for each pivot point
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

bitset<30010> ids;
int main()
{
    int n, zeros = 0, ones = 0, minim = 1000000, tmp, idx = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> tmp;
        if(tmp == 2)
            ids[i] = true;
        else
            zeros ++;
    }
    minim = zeros;
    while(idx < n)
    {
        if(ids[idx])
            ones ++;
        else
            zeros --;
        minim = min(minim, ones + zeros);
        idx ++;
    }
    minim = min(minim, ones);
    cout << minim;
}
