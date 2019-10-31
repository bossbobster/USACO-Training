#include <iostream>
#include <stack>
using namespace std;

stack<int> clumps;
int main()
{
    int n, cow, prevCow = 100000000, useless;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> useless >> cow;
        if(!clumps.empty())
            while(cow < clumps.top())
            {
                clumps.pop();
                if(clumps.empty()) break;
            }
        clumps.push(cow);
    }
    cout << clumps.size();
}
