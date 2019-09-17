#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string reverse(string s)
{
    return s.substr(2, 2) + s.substr(0, 2);
}

map<string, int> keys;
string ct, st;
int main()
{
    int n, total = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> ct >> st;
        ct = ct.substr(0, 2);
        if(ct != st)
        {
            map<string, int>::iterator it = keys.find(ct + st);
            if(it == keys.end())
                keys.insert(pair<string, int>(ct + st, 1));
            else
                it->second ++;
        }
    }
    map<string, int>::iterator it = keys.begin();
    while(it != keys.end())
    {
        string revKey = reverse(it->first);
        if(keys.find(revKey) != keys.end())
            total += it->second * keys.find(revKey)->second;
        it ++;
    }
    cout << total / 2;
}
