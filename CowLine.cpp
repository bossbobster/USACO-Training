#include <iostream>
#include <deque>
using namespace std;

deque<int> cows;
int main()
{
    int s, k, num = 1, len = 0;
    char command, direction;
    cin >> s;
    for(int i = 0; i < s; i ++)
    {
        cin >> command >> direction;
        if(command == 'A')
        {
            if(direction == 'L')
                cows.push_front(num);
            else
                cows.push_back(num);
            num ++;
            len ++;
        }
        else
        {
            cin >> k;
            len -= k;
            for(int j = 0; j < k; j ++)
            {
                if(direction == 'L')
                    cows.pop_front();
                else
                    cows.pop_back();
            }
        }
    }
    for(int i = 0; i < len; i ++)
    {
        cout << cows.front() << "\n";
        cows.pop_front();
    }
}
