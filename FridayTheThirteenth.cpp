#include <iostream>
using namespace std;

int days[7];
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int curDay = 0, n, limit;
    cin >> n;
    for(int i = 1900; i < 1900 + n; i ++)
        for(int j = 0; j < 12; j ++)
        {
            limit = month[j];
            if(j == 1 && ((i % 100 != 0 && i % 4 == 0) || (i % 400 == 0)))
                limit = 29;
            else
                for(int k = 0; k < limit; k ++)
                {
                    if(k == 13)
                        days[curDay] ++;
                    curDay = (curDay+1) % 7;
                }
        }
    for(int i = 0; i < 7; i ++)
        cout << days[(i + 6) % 7] << ((i==6)?'\n':' ');
}
