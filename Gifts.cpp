#include <iostream>
#include <algorithm>
using namespace std;

struct gift
{
    long long cost, shipping;
};
bool cpr(gift g1, gift g2)
{
    return g1.cost + g1.shipping < g2.cost + g2.shipping;
}

gift gifts[1000];
int main()
{
    long long n, b, total = 0, cnt = 0;
    cin >> n >> b;
    for(int i = 0; i < n; i ++)
        cin >> gifts[i].cost >> gifts[i].shipping;
    sort(gifts, gifts + n, cpr);
    for(int i = 0; i < n; i ++)
    {
        if(total + gifts[i].cost + gifts[i].shipping > b)
        {
            if(total + (gifts[i].cost / 2) + gifts[i].shipping <= b)
                cnt ++;
            break;
        }
        cnt ++;
        total += gifts[i].cost + gifts[i].shipping;
    }
    cout << cnt;
}
