#include <iostream>
using namespace std;

int cows[1000][2];
bool dead[1000];
int main()
{
    int n, best, index = 0, cnt = 0, i2 = -1;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> cows[i][0] >> cows[i][1];
    }
    while(cnt < n)
    {
        i2 ++;
        i2 = i2 % n;
        if(dead[i2])
            continue;
        best = 2000000000;
        index = 0;
        for(int j = 0; j < n; j ++)
        {
            if(j == i2 || dead[j])
                continue;
            if(best > ((cows[i2][0] - cows[j][0]) * (cows[i2][0] - cows[j][0])) + ((cows[i2][1] - cows[j][1]) * (cows[i2][1] - cows[j][1])))
            {
                best = ((cows[i2][0] - cows[j][0]) * (cows[i2][0] - cows[j][0])) + ((cows[i2][1] - cows[j][1]) * (cows[i2][1] - cows[j][1]));
                index = j;
            }
        }
        dead[index] = true;
        cnt ++;
    }
    for(int i = 0; i < n; i ++)
        if(!dead[i])
            cout << i + 1;
}
