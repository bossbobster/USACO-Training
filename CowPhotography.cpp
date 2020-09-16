#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;

map<int, int> pos[5];
int nums[5][20010];
bool comp(int i1, int i2)
{
    int left = 0;
    for(int i = 0; i < 5; i ++)
        if(pos[i][i1] < pos[i][i2])
            left ++;
    if(left >= 3) return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 5 * n; i ++)
    {
        cin >> nums[i / n][i % n];
        pos[i / n][nums[i / n][i % n]] = i % n;
    }
    sort(nums[0], nums[0] + n, comp);
    for(int i = 0; i < n; i ++)
        cout << nums[0][i] << "\n";
}
