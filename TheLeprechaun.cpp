//The Leprechaun (torus problem)

#include <iostream>
using namespace std;

int torus[200][200];
int main()
{
    int n, cur = 0, best = -10000000;
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> torus[i][j];
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            for(int dx = -1; dx <= 1; dx ++)
            {
                for(int dy = -1; dy <= 1; dy ++)
                {
                    if(dx == dy && dx == 0)
                        continue;
                    cur = 0;
                    for(int k = 0; k < n; k ++)
                    {
                        cur = max(torus[(i + dx * k + n) % n][(j + dy * k + n) % n], cur + torus[(i + dx * k + n) % n][(j + dy * k + n) % n]);
                        if(cur > best)
                            best = cur;
                    }
                }
            }
        }
    }
    cout << best;
}
