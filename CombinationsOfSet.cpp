//NOT USACO PROBLEM
#include <iostream>
using namespace std;

int nums[1000000];
bool used[1000000];
int n, m;
string cur = "";
void printAll(int n1, int idx)
{
    if(n1 == 0)
    {
        cout << cur << "\n";
        return;
    }
    for(int i = n - n1 + idx; i < n - n1 + m - n + 1; i ++)
    {
        if(used[i]) continue;
        cur[n - n1] = nums[i] + '0';
        used[i] = true;
        printAll(n1 - 1, idx);
        idx ++;
        used[i] = false;
    }
}

int main()
{
    cin >> m;
    for(int i = 0; i < m; i ++)
        cin >> nums[i];
    cin >> n;
    for(int i = 0; i < n; i ++) cur += "0";
    printAll(n, 0);
}
