#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

int tmp;
int cnt;
string nums[50010][5];
gp_hash_table<string, unsigned int> m;
string sub[31] = {"4","3","34","2","24","23","234","1","14","13","134","12","124","123","1234","0","04","03","034","02","024","023","0234","01","014","013","0134","012","0124","0123","01234"};
string s, add;
int main()
{
    int n, indexx = 0;
    long long finalAns = 0;
    fin >> n;
    for(int idx = 0; idx < n; idx ++)
    {
        for(int j = 0; j < 5; j ++)
            fin >> nums[idx][j];
        sort(nums[idx], nums[idx] + 5);
        for(int i = 0; i < 31; i ++)
        {
            cnt = indexx = 0;
            add = "                                ";
            s = sub[i];
            for(int j = 0; j < s.length(); j ++)
            {
                for(int k = 0; k < nums[idx][sub[i][j] - '0'].length(); k ++)
                {
                    add[indexx] = nums[idx][sub[i][j] - '0'][k];
                    indexx ++;
                }
                cnt ++;
            }
            add[add.length() - 1] = cnt;
            m[add] ++;
        }
    }
    for(auto a : m)
    {
        cnt = a.first[a.first.length() - 1];
        if(cnt % 2 == 1) finalAns += (a.second * (a.second - 1) / 2);
        else finalAns -= (a.second * (a.second - 1) / 2);
    }
    fout << (long long)(((long long)n * (long long)(n - 1) / (long long)2 - (long long)finalAns)) << "\n";
}
