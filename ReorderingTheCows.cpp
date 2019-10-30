#include <iostream>
#include <algorithm>
using namespace std;

int a[110];
int b[110];
int cur[110];
int locations[110];
int main()
{
    int n, longest = 0, curLen = 0, first = 0, curPlace = 0, curNum = 0, cycles = 0;
    bool done = true;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        cur[i] = a[i];
    }
    for(int i = 0; i < n; i ++)
    {
        cin >> b[i];
        locations[b[i]] = i;
        if(b[i] != a[i]) done = false;
    }
    if(done) 
        cout << 0 << " " << -1;
    else
    {
        while(true)
        {
            curLen = 1;
            done = true;
            for(int i = 0; i < n; i ++)
                if(cur[i] != b[i])
                {
                    first = i;
                    curPlace = i;
                    curNum = cur[i];
                    break;
                }
            do
            {
                int temp = cur[locations[curNum]];
                cur[locations[curNum]] = curNum;
                curNum = temp;
                curPlace = locations[curNum];
                curLen ++;
            } while(curPlace != first);
            cur[first] = curNum;
            longest = max(curLen, longest);
            cycles ++;
            for(int i = 0; i < n; i ++)
                if(cur[i] != b[i])
                {
                    done = false;
                    break;
                }
            if(done) break;
        }
        cout << cycles << " " << longest;
    }
}
