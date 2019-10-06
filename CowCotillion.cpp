#include <iostream>
using namespace std;

int change(char ch)
{
    if(ch == '>')
        return 1;
    return -1;
}

char cows[200];
int main()
{
    int n, m, num;
    bool cor = true;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> m;
        num = 0;
        cor = true;
        for(int j = 0; j < m; j ++)
        {
            cin >> cows[j];
            num += change(cows[j]);
            if(num < 0)
                cor = false;
        }
        if(num == 0 && cor)
            cout << "legal" << endl;
        else
            cout << "illegal" << endl;
    }
}
