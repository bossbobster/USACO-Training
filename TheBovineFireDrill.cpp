#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

int cur[260];
bitset<256> visited;
int main()
{
    int n, first = 0, curPlace = 0, curNum = 0, prevNum;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cur[i + 1] = i + 1;
    first = 1;
    curPlace = 1;
    curNum = cur[1];
    do
    {
        prevNum = curNum;
        visited[curPlace] = true;
        curNum = cur[((curPlace + cur[curPlace]) - 1) % n + 1];
        curPlace = ((curPlace + cur[curPlace]) - 1) % n + 1;
    } while(curPlace != first && !visited[curPlace]);
    cout << prevNum;
}
