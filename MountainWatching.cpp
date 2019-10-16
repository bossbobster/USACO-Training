#include <iostream>
#include <algorithm>
using namespace std;

int hsh(int n1, int n2)
{
    if(n2 > n1)
        return 1;
    if(n2 == n1)
        return 0;
    return -1;
}

int heights[10000];
int main()
{
    int n, direction = 0, curStart = 0, nextStart = 0, ans = 0, prevDirection = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> heights[i];
    for(int i = 1; i < n; i ++)
    {
        direction = hsh(heights[i - 1], heights[i]);
        if(direction == -1)
        {
            nextStart = i;
        }
        if(direction == 1 && prevDirection == -1)
        {
            ans = max(ans, i - curStart);
            curStart = nextStart;
        }
        if(direction == 1 || direction == -1)
            prevDirection = direction;
    }
    if(ans != 0)
        cout << max(ans, n - curStart);
    else
        cout << n;
}
