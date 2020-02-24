//BRONZE VERSION
#include <iostream>
#include <algorithm>
using namespace std;

int coos[10][4];

bool used[1000000];
int n, total = 0;
string cur = "0000000000";
bool done = false;
void printAll(int n1, int nn, int idx)
{
    if(n1 == 0)
    {
        done = false;
        int x1 = -10000, y1 = 10000, x2 = 10000, y2 = -10000;
        for(int i = 0; i < nn; i ++)
        {
            x1 = max(x1, coos[cur[i] - '0'][0]);
            x2 = min(x2, coos[cur[i] - '0'][2]);
            y1 = min(y1, coos[cur[i] - '0'][1]);
            y2 = max(y2, coos[cur[i] - '0'][3]);
            if(x1 >= x2 || y1 <= y2) { done = true; break; }
        }
        if(done) return;
        if(nn % 2 == 1) total += (x2 - x1) * (y1 - y2);
        else total -= (x2 - x1) * (y1 - y2);
        return;
    }
    for(int i = nn - n1 + idx; i < n - n1 + 1; i ++)
    {
        if(used[i]) continue;
        cur[nn - n1] = i + '0';
        used[i] = true;
        printAll(n1 - 1, nn, idx);
        idx ++;
        used[i] = false;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> coos[i][0] >> coos[i][1] >> coos[i][2] >> coos[i][3];
    for(int i = 1; i <= n; i ++)
        printAll(i, i, 0);
    cout << total << "\n";
}
