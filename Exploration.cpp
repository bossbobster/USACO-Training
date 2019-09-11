#include <iostream>
#include <algorithm>
using namespace std;

bool cpr(int n1, int n2)
{
    return abs(n1) < abs(n2);
}

int locations[50000];
int main()
{
    int totTime, n, curTime = 0, cnt = 0, pos = 0;
    cin >> totTime >> n;
    for(int i = 0; i < n; i ++)
        cin >> locations[i];
    sort(locations, locations + n, cpr);
    while((abs(pos - locations[cnt]) + curTime) <= totTime)
    {
        curTime += abs(pos - locations[cnt]);
        pos = locations[cnt];
        cnt ++;
    }
    cout << cnt;
}
