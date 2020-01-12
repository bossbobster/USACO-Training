//NOT USACO PROBLEM
#include <iostream>
using namespace std;

void findAll(int cur, int n, string s)
{
    if(cur == n)
    {
        cout << s << "\n";
        return;
    }
    s[cur] = '0';
    findAll(cur + 1, n, s);
    s[cur] = '1';
    findAll(cur + 1, n, s);
}

int main()
{
    int n;
    string s = "";
    cin >> n;
    for(int i = 0; i < n; i ++)
        s += "0";
    findAll(0, n, s);
}
