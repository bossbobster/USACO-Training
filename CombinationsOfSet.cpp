//NOT USACO PROBLEM
#include <iostream>
using namespace std;

int nums[100010];
int n, m;
vector<int> cur;
void printAll(int idx, int lef)
{
    if(lef == 0)
    {
        for(int i = 0; i < n; i ++)
            cout << cur[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = idx; i <= m - lef; i ++)
    {
        cur.push_back(nums[i]);
        printAll(i + 1, lef - 1);
        cur.pop_back();
    }
}

int main()
{
    cin >> m;
    for(int i = 0; i < m; i ++)
        cin >> nums[i];
    cin >> n;
    printAll(0, n);
}
