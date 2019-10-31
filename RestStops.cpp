#include <iostream>
#include <algorithm>
using namespace std;

int stops[100000][2];
int main()
{
    int l, n, sFJ, sB;
    long long cur = 0, dif, locMax = 0, maxIdx = 0;
    unsigned long long sum = 0;
    bool stillRests = true;
    cin >> l >> n >> sB >> sFJ;
    dif = sB - sFJ;
    for(int i = 0; i < n; i ++)
        cin >> stops[i][0] >> stops[i][1];
    while(stillRests)
    {
        stillRests = false;
        locMax = 0;
        for(int i = 0; i < n; i ++)
            if(stops[i][0] > cur)
                if(stops[i][1]  > locMax)
                {
                    locMax = stops[i][1];
                    maxIdx = i;
                    stillRests = true;
                }
        unsigned long long temp = locMax * dif;
        unsigned long long temp2 = (stops[maxIdx][0] - cur) * temp;
        sum += temp2;
        cur = stops[maxIdx][0];
    }
    cout << sum;
}
