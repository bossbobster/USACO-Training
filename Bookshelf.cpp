#include <iostream>
#include <algorithm>
using namespace std;

bool cpr(int n1, int n2)
{
    return n1 > n2;
}

int heights[20000];
int main()
{
    int n, height, total = 0, cnt = 0;
    cin >> n >> height;
    for(int i = 0; i < n; i ++)
        cin >> heights[i];
    sort(heights, heights + n, cpr);
    while(total < height)
    {
        total += heights[cnt];
        cnt ++;
    }
    cout << cnt;
}
