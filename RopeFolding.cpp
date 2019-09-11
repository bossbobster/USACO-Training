#include <iostream>
#include <algorithm>
using namespace std;

int knots[100];
int main()
{
    int l, n, answer = 0;
    float mn;
    bool good = true;
    cin >> n >> l;
    for(int i = 0; i < n; i ++)
        cin >> knots[i];
    sort(knots, knots + n);
    for(int i = 1; i < n; i ++)
    {
        good = true;
        mn = ((float)knots[i - 1] + (float)knots[i]) / 2;
        for(int j = 0; j < min(i, n - i); j ++)
            good = good & (mn - (float)knots[i - j - 1] == (float)knots[i + j] - mn);
        answer += good;
    }
    for(int i = 1; i < n - 1; i ++)
    {
        good = true;
        mn = (float)knots[i];
        for(int j = 0; j < min(i, n - i - 1); j ++)
            good = good & (mn - (float)knots[i - j - 1] == (float)knots[i + j + 1] - mn);
        answer += good;
    }
    cout << answer;
}
