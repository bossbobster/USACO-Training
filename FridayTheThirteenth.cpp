#include <iostream>
using namespace std;

int days[7];
int main()
{
    int curDay = 0, n;
    cin >> n;
    for(int i = 1900; i < 1900 + n; i ++)
    {
        for(int j = 0; j < 12; j ++)
        {
            if(j == 3 || j == 5 || j == 8 || j == 10)
            {
                for(int k = 0; k < 30; k ++)
                {
                    if(k == 13)
                        days[curDay] ++;
                    curDay ++;
                    curDay = curDay % 7;
                }
            }
            else if(j == 1)
            {
                if((i % 100 != 0 && i % 4 == 0) || (i % 400 == 0))
                {
                    for(int k = 0; k < 29; k ++)
                    {
                        if(k == 13)
                            days[curDay] ++;
                        curDay ++;
                        curDay = curDay % 7;
                    }
                }
                else
                {
                    for(int k = 0; k < 28; k ++)
                    {
                        if(k == 13)
                            days[curDay] ++;
                        curDay ++;
                        curDay = curDay % 7;
                    }
                }
            }
            else
            {
                for(int k = 0; k < 31; k ++)
                {
                    if(k == 13)
                        days[curDay] ++;
                    curDay ++;
                    curDay = curDay % 7;
                }
            }
        }
    }
    for(int i = 0; i < 7; i ++)
        cout << days[(i + 6) % 7] << " ";
}
