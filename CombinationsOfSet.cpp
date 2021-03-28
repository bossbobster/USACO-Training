//NOT USACO PROBLEM
#include <iostream>
using namespace std;

int nums[100010];
bool used[100010];
int n, m;
vector<int> cur;
void printAll(int n1, int idx)
{
    if(n1 == 0)
    {
        for(int i = 0; i < n; i ++)
            cout << cur[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = n - n1 + idx; i < m - n1 + 1; i ++)
    {
        if(used[i]) continue;
        cur[n - n1] = nums[i];
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
    for(int i = 0; i < n; i ++) cur.push_back(0);
    printAll(n, 0);
}
