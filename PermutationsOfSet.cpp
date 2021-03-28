//NOT USACO PROBLEM
#include <iostream>
#include <vector>
using namespace std;

int nums[100010];
bool used[100010];
int n, m;
vector<int> cur;
void printAll(int cnt)
{
    if(cnt == n)
    {
        for(int i = 0; i < n; i ++)
            cout << cur[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < m; i ++)
    {
        if(used[i]) continue;
        cur.push_back(nums[i]); used[i] = true;
        printAll(cnt + 1);
        cur.pop_back(); used[i] = false;
    }
}

int main()
{
    cin >> m;
    for(int i = 0; i < m; i ++)
        cin >> nums[i];
    cin >> n;
    printAll(0);
}
