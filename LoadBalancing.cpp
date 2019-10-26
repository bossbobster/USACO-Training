#include <iostream>
using namespace std;

int x[200];
int y[200];
int main()
{
    int n, b, r1 = 0, r2 = 0, r3 = 0, r4 = 0, ans = 100, avg1 = 0, avg2 = 0;
    cin >> n >> b;
    for(int i = 0; i < n; i ++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            r1 = r2 = r3 = r4 = 0;
            avg1 = x[i] + 1;
            avg2 = y[j] + 1;
            for(int k = 0; k < n; k ++)
            {
                if(x[k] < avg1 && y[k] < avg2) r1 ++;
                if(x[k] > avg1 && y[k] < avg2) r2 ++;
                if(x[k] < avg1 && y[k] > avg2) r3 ++;
                if(x[k] > avg1 && y[k] > avg2) r4 ++;
            }
            if(r1 >= r2 && r1 >= r3 && r1 >= r4) ans = min(r1, ans);
            if(r2 >= r1 && r2 >= r3 && r2 >= r4) ans = min(r2, ans);
            if(r3 >= r1 && r3 >= r2 && r3 >= r4) ans = min(r3, ans);
            if(r4 >= r1 && r4 >= r2 && r4 >= r3) ans = min(r4, ans);
        }
    }
    cout << ans;
}
