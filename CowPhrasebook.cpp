#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

unordered_set<string> phrases;
bool str[61];
int main()
{
    int m, n, total = 0;
    string temp;
    cin >> m >> n;
    getline(cin, temp);
    for(int i = 0; i < m; i ++)
    {
        getline(cin, temp);
        p1[i] = temp;
    }
    for(int i = 0; i < n; i ++)
    {
        getline(cin, temp);
        p2[i] = temp;
        str[temp.length()] = true;
    }
    for(int i = 0; i < m; i ++)
    {
        temp = p1[i];
        for(int j = 1; j < temp.length()+1; j ++)
            if(str[j])
                phrases.insert(temp.substr(0, j));
    }
    for(int i = 0; i < n; i ++)
    {
        temp = p2[i];
        if(phrases.find(temp) != phrases.end())
            total ++;
    }
    cout << total;
}
