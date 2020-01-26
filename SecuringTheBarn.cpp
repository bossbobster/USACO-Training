#include <iostream>
#include <algorithm>
using namespace std;

int l, c, vo, co;
char ch[30];
bool used[30];
string cur = "";
void printAll(int n1, int idx)
{
    if(n1 == 0)
    {
        vo = co = 0;
        for(int i = 0; i < cur.length(); i ++)
        {
            if(cur[i] == 'a' || cur[i] == 'e' || cur[i] == 'i' || cur[i] == 'o' || cur[i] == 'u') vo ++;
            else co ++;
        }
        if(vo >= 1 && co >= 2) cout << cur << "\n";
        return;
    }
    for(int i = l - n1 + idx; i < c - n1 + 1; i ++)
    {
        if(used[i]) continue;
        cur[l - n1] = ch[i];
        used[i] = true;
        printAll(n1 - 1, idx);
        idx ++;
        used[i] = false;
    }
}
int main()
{
    cin >> l >> c;
    for(int i = 0; i < c; i ++) cin >> ch[i];
    for(int i = 0; i < l; i ++) cur += "0";
    sort(ch, ch + c);
    printAll(l, 0);
}
