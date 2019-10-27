#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int power(int num, int base)
{
    int n = 1;
    for(int i = 0; i < base; i ++)
        n *= num;
    return n;
}

long long binaryToTen(string s)
{
    long long n = 0;
    for(int i = s.length() - 1; i >= 0; i --)
        if(s[i] != '0')
            n += power(2, s.length() - i - 1);
    return n;
}
long long ternaryToTen(string s)
{
    long long n = 0;
    for(int i = s.length() - 1; i >= 0; i --)
        if(s[i] != '0')
            n += (power(3, s.length() - i - 1) * (s[i] - '0'));
    return n;
}

vector<long long> binary;
set<long long> ternary;
int main()
{
    long long ans = 0;
    string b, t, tmpB, tmpT;
    cin >> b >> t;
    tmpB = b;
    tmpT = t;
    for(int i = 0; i < b.length(); i ++)
    {
        tmpB[i] = (b[i] - '0' + 1) % 2 + '0';
        binary.push_back(binaryToTen(tmpB));
        tmpB[i] = b[i];
    }
    for(int i = 0; i < t.length(); i ++)
    {
        tmpT[i] = (t[i] - '0' + 1) % 3 + '0';
        ternary.insert(ternaryToTen(tmpT));
        tmpT[i] = (t[i] - '0' + 2) % 3 + '0';
        ternary.insert(ternaryToTen(tmpT));
        tmpT[i] = t[i];
    }
    for(int i = 0; i < binary.size(); i ++)
        if(ternary.find(binary[i]) != ternary.end())
        {
            ans = binary[i];
            break;
        }
    cout << ans;
}
