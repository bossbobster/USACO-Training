#include <iostream>
#include <string>
using namespace std;

string possible[20][5000];
char dict[8][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}}; 
int main()
{
    int cnt = 0, cnt2 = 0, size = 0, remaining = 0;
    string code;
    cin >> code;
    while(getline(cin, possible[0][cnt])) 
    {
        if(possible[0][cnt].length() == code.length())
        {
            possible[1][cnt2] = possible[0][cnt];
            size ++; cnt2 ++;
        }
        cnt ++;
    }
    remaining = size;
    for(int i = 1; i < code.length() + 1; i ++)
    {
        cnt = 0;
        for(int j = 0; j < remaining; j ++)
        {
            if(possible[i][j][i - 1] == dict[code[i - 1] - '0' - 2][0] || possible[i][j][i - 1] == dict[code[i - 1] - '0' - 2][1] || possible[i][j][i - 1] == dict[code[i - 1] - '0' - 2][2]) {
                possible[i + 1][cnt] = possible[i][j]; cnt ++;}
        }
    }
    if(cnt > 0)
        for(int i = 0; i < cnt; i ++)
            cout << possible[code.length() + 1][i] << endl;
    else
        cout << "NONE";
}
