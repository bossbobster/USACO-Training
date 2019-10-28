#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

string x, y;
set<long long> nums;
void findNums()
{
    string num = "000000000000000000000";
    for(int i = x.length(); i <= y.length(); i ++)
    {
        for(char ch = '0'; ch <= '9'; ch ++)
        {
            for(int j = 16; j > 16 - i; j --)
            {
                num[j] = ch;
            }
            for(int j = 16; j > 16 - i; j --)
            {
                for(int k = '0'; k <= '9'; k ++)
                {
                    if(k == ch)
                        continue;
                    if(k == '0' && j == 16 - i + 1)
                        continue;
                    num[j] = k;
                    if(stoll(num.substr(16 - i + 1, i)) >= stoll(x) && stoll(num.substr(16 - i + 1, i)) <= stoll(y))
                        nums.insert(stoll(num.substr(16 - i + 1, i)));
                    num[j] = ch;
                }
            }
        }
    }
}

int main()
{
    cin >> x >> y;
    findNums();
    cout << nums.size();
}
