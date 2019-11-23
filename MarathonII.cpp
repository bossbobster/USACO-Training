#include <iostream>
#include <algorithm>
using namespace std;

struct cow
{
    int x, y;
};

cow cows[100000];
int distances[100000];
int main()
{
    int n, total = 0, minN = 1000000000, temp;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> cows[i].x >> cows[i].y;
        if(i > 0)
        {
            distances[i] = abs(cows[i].x - cows[i - 1].x) + abs(cows[i].y - cows[i - 1].y);
            total += distances[i];
        }
    }
    for(int i = 1; i < n - 1; i ++)
    {
        temp = total;
        temp -= distances[i];
        temp -= distances[i + 1];
        temp += abs(cows[i + 1].x - cows[i - 1].x) + abs(cows[i + 1].y - cows[i - 1].y);
        minN = min(minN, temp);
    }
    cout << minN;
}
