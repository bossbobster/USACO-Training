#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("preface.in");
ofstream fout("preface.out");

int vals[7] = {1000, 500, 100, 50, 10, 5, 1};
char chars[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
int hsh(char ch)
{
    if(ch == 'I') return 0;
    if(ch == 'V') return 1;
    if(ch == 'X') return 2;
    if(ch == 'L') return 3;
    if(ch == 'C') return 4;
    if(ch == 'D') return 5;
    return 6;
}
int ans[10];
int main()
{
    int n, num;
    string cur = "";
    int cnt = 0;
    fin >> n;
    for(int i = 1; i <= n; i ++)
    {
        num = i;
        cur = ""; cnt = 0;
        while(num > 0)
        {
            if(vals[cnt] > num) {cnt ++; continue;}
            if(num >= 900 && num <= 999) {cur += "CM"; cnt ++; num -= 900; continue;}
            if(num >= 90 && num <= 99) {cur += "XC"; cnt ++; num -= 90; continue;}
            if(num == 9) {cur += "IX"; cnt ++; num -= 9; continue;}
            if(num >= 400 && num <= 499) {cur += "CD"; cnt ++; num -= 400; continue;}
            if(num >= 40 && num <= 49) {cur += "XL"; cnt ++; num -= 40; continue;}
            if(num == 4) {cur += "IV"; cnt ++; num -= 4; continue;}
            for(int j = 0; j < num / vals[cnt]; j ++) cur += chars[cnt];
            num -= num / vals[cnt] * vals[cnt];
            cnt ++;
        }
        for(int i = 0; i < cur.length(); i ++)
            ans[hsh(cur[i])] ++;
    }
    for(int i = 0; i < 7; i ++)
        if(ans[i] > 0)
            fout << chars[6 - i] << " " << ans[i] << "\n";
}
