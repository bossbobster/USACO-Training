#include <iostream>
using namespace std;

bool nums[10000];
int main()
{
    int cnt = 0, cur;
    cin >> cur;
    while(!nums[cur])
    {
        nums[cur] = true;
        cur = (cur / 10) % 100;
        cur = cur * cur;
        cnt ++;
    }
    cout << cnt;
}
