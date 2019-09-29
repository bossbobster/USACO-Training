#include <iostream>
#include <string>
using namespace std;

int main()
{
    int l, r, best = 0, cur = 0;
    string curStr = "", bestStr = "", tmp, str;
    while(getline(cin, tmp)) {str += "\n"; str += tmp;}
    for(int i = 1; i < str.length() - 1; i ++)
    {
        l = i - 1;
        r = i + 1;
        cur = 1;
        curStr = str[i];
        if(isalpha(str[i]))
        {
            while (l >= 0 && r < str.length())
            {
                if(isalpha(str[l]) && isalpha(str[r]))
                {
                    if(tolower(str.at(l)) == tolower(str.at(r)))
                        cur += 2;
                    else
                        break;
                    curStr = str.at(l) + curStr + str.at(r);
                    l --;
                    r ++;
                    if(cur > best)
                    {
                        best = cur;
                        bestStr = curStr;
                    }
                }
                else if(isalpha(str[l]) && !isalpha(str[r])) {curStr += str.at(r); r ++;}
                else if(!isalpha(str[l]) && isalpha(str[r])) {curStr = str.at(l) + curStr; l --;}
                else {curStr = str.at(l) + curStr + str.at(r); l --; r ++;}
            }
        }
        if(cur == 1)
        {
            l = i - 1;
            r = i;
            cur = 0;
            curStr = "";
            while (l >= 0 && r < str.length())
            {
                if(isalpha(str[l]) && isalpha(str[r]))
                {
                    if(tolower(str.at(l)) == tolower(str.at(r)))
                        cur += 2;
                    else
                        break;
                    curStr = str.at(l) + curStr + str.at(r);
                    l --;
                    r ++;
                    if(cur > best)
                    {
                        best = cur;
                        bestStr = curStr;
                    }
                }
                else if(isalpha(str[l]) && !isalpha(str[r])) {curStr += str.at(r); r ++;}
                else if(!isalpha(str[l]) && isalpha(str[r])) {curStr = str.at(l) + curStr; l --;}
                else {curStr = str.at(l) + curStr + str.at(r); l --; r ++;}
            }
        }
    }
    cout << best << endl << bestStr;
}
