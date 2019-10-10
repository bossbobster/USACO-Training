#include <iostream>
using namespace std;

int main()
{
    int t, n, u, f, d, cur = 0, total = 0;
    char c;
    cin >> t >> n >> u >> f >> d;
    for(int i = 0; i < n; i ++)
    {
        cin >> c;
        if(c == 'u' || c == 'd')
            cur += u + d;
        else
            cur += f + f;
        if(cur > t)
            break;
        total ++;
    }
    cout << total;
}
