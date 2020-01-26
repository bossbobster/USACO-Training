#include <iostream>
using namespace std;

int place[20];
int main()
{
    string s;
    cin >> s;
    if(s[1] != '#') place[1] = 1;
    place[0] = 1;
    for(int i = 2; i < s.length(); i ++)
    {
        if(s[i] == '#') continue;
        place[i] = place[i - 2] + place[i - 1];
    }
    cout << place[s.length() - 1];
}
