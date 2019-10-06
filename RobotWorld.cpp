#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int ans[1000000];
int main()
{
    int n, len = 0, num = 1;
    string command;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> command;
        if(command == "ADD")
        {
            st.push(num);
            num ++;
            len ++;
        }
        else
        {
            st.pop();
            if(len != 0)
                len --;
        }
    }
    for(int i = 0; i < len; i ++)
    {
        ans[len - i - 1] = st.top();
        st.pop();
    }
    cout << len << endl;
    for(int i = 0; i < len; i ++)
        cout << ans[i] << endl;
}
