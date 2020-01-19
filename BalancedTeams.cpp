#include <iostream>
#include <algorithm>
using namespace std;

int skills[12];
int totals[4];
bool used[12];
int total = 0, ans = 1000000000;
void printAll(int n1, int idx, int idx2)
{
    if(n1 == 0)
    {
        if(idx2 == 3) ans = min(ans, max(max(totals[0], totals[1]), max(totals[2], totals[3])) - min(min(totals[0], totals[1]), min(totals[2], totals[3])));
        printAll(3, 0, idx2 + 1);
        return;
    }
    for(int i = 3 - n1 + idx; i < 13 - n1; i ++)
    {
        if(used[i]) continue;
        totals[idx2] += skills[i];
        used[i] = true;
        printAll(n1 - 1, idx, idx2);
        idx ++;
        totals[idx2] -= skills[i];
        used[i] = false;
    }
}
int main()
{
    for(int i = 0; i < 12; i ++) { cin >> skills[i]; total += skills[i]; }
    printAll(3, 0, 0);
    cout << ans;
}
