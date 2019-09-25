//Silver version
#include <iostream>
#include <algorithm>
using namespace std;

int broken[100001];
int main()
{
    int n, k, b, num, cur = 0, best = 100001;
    cin >> n >> k >> b;
    for(int i = 0; i < b; i ++)
    {
        cin >> num;
        broken[num] = 1;
    }
    for(int i = 1; i <= k; i ++)
        cur += broken[i];
    best = cur;
    for(int i = 1; i <= n - k; i ++)
    {
        cur -= (broken[i] - broken[i + k]);
        if(cur < best)
            best = cur;
    }
    cout << best;
}
