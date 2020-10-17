#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[100010];
int first[100010];
int second[100010];
stack<int> rec;
int main()
{
    int n, idx1 = 0, idx2 = 0, cnt = 1, ans = 1;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    for(int i = 0; i < n; i ++)
    {
        if(arr[i] == 0) continue;
        if(first[arr[i]] == 0) 
            first[arr[i]] = i + 1;
        second[arr[i]] = i + 1;
    }
    for(int i = 0; i < n; i ++)
    {
        if(arr[i] == 0) continue;
        if(first[arr[i]] == i + 1) { cnt ++; rec.push(arr[i]); }
        ans = max(cnt, ans);
        if(cnt <= 0 || rec.top() != arr[i]) { ans = 0; break; }
        if(second[arr[i]] == i + 1) { cnt --; rec.pop(); }
    }
    cout << ans - 1 << "\n";
}
