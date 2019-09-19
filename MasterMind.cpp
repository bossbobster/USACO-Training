#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct code
{
    string c;
    int f, s;
};
code codes[100];
int n;
string ans = "NONE";

bool possible(string s)
{
    int positions1, positions2;
    bool visited[4];
    for(int i = 0; i < n; i ++)
    {
        positions1 = positions2 = 0;
        for(int j = 0; j < 4; j ++)
            visited[j] = false;
        for(int j = 0; j < 4; j ++)
            if(s[j] == codes[i].c[j])
            {
                positions1 ++;
                visited[j] = true;
            }
        if(positions1 != codes[i].f)
            return false;
        for(int j = 0; j < 4; j ++)
        {
            if(visited[j])
                continue;
            if(s[j] != codes[i].c[j] && codes[i].c.find(s[j]) != string::npos && !visited[codes[i].c.find(s[j])])
                positions2 ++;
        }
        if(positions2 != codes[i].s)
            return false;
    }
    return true;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> codes[i].c >> codes[i].f >> codes[i].s;
    for(int i = 9999; i > 999; i --)
        if(possible(to_string(i)))
            ans = to_string(i);
    cout << ans;
}
