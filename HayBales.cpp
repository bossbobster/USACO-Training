#include <iostream>
using namespace std;

int bales[10000];
int main()
{
    int n, total = 0, avg = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> bales[i];
        total += bales[i];
    }
    avg = total / n;
    for(int i = 0; i < n; i ++)
        ans += abs(avg - bales[i]);
    cout << ans / 2;
}
