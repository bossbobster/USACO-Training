#include <iostream>
#include <algorithm>
using namespace std;

long long powers[50050];
bool par[100010];
int main()
{
    long long cur = 1, n, num = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> par[i];
    for(int i = 0; i < 50010; i ++)
    {
        powers[i] = cur;
        cur *= 2;
        cur = cur % 12345678910;
    }
    for(int i = 0; i < n; i ++)
    {
        if(par[i]) num --;
        else num ++;
        if(i != 0) if(par[i] == true && par[i - 1] == false) ans += powers[num];
        ans = ans % 12345678910;
    }
    cout << ans << "\n";
}
