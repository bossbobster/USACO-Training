#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("circlecross.in");
ofstream fout("circlecross.out");

int sum(int arr[], int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int arr[], int idx, int val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}

int nums[100010];
bool visited[100010];
int beg[100010];
int bit[100010];
int main()
{
    int n, ans = 0;
    fin >> n;
    for(int i = 0; i < n * 2; i ++)
        fin >> nums[i];
    for(int i = 0; i < n * 2; i ++)
    {
        if(visited[nums[i]])
        {
            ans += max(0, sum(bit, i) - sum(bit, beg[nums[i]]));
            update(bit, beg[nums[i]], -1, 2 * n + 2);
        }
        else
        {
            beg[nums[i]] = i;
            update(bit, i, 1, 2 * n + 2);
        }
        visited[nums[i]] = true;
    }
    fout << ans << "\n";
}
