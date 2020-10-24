#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> cur;
int main()
{
    int n, w, x, y, ans = 0;
    cin >> n >> w;
    for(int i = 0; i < n; i ++)
    {
        cin >> x >> y;
        if(!cur.empty())
            while(cur.top() > y)
            {
                cur.pop();
                if(cur.empty()) break;
            }
        if(y != 0 && (cur.empty() || cur.top() != y))
        {
            ans ++;
            cur.push(y);
        }
    }
    cout << ans << "\n";
}
