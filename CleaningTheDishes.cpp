#include <iostream>
#include <stack>
using namespace std;

stack<int> unwashed;
stack<int> washed;
stack<int> dried;
int main()
{
    int n, total = 0, command, num;
    cin >> n;
    for(int i = n; i >= 1; i --)
        unwashed.push(i);
    while(total < n * 2)
    {
        cin >> command >> num;
        total += num;
        if(command == 1)
            for(int i = 0; i < num; i ++)
            {
                washed.push(unwashed.top());
                unwashed.pop();
            }
        else
            for(int i = 0; i < num; i ++)
            {
                dried.push(washed.top());
                washed.pop();
            }
    }
    for(int i = 0; i < n; i ++)
    {
        cout << dried.top() << "\n";
        dried.pop();
    }
}
