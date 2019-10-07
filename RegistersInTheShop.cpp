#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> line;
vector<int> registers[30];
int len[30];
int main()
{
    int n, cust;
    char command;
    cin >> n;
    cin >> command >> cust;
    line.push(cust);
    while(cin)
    {
        cin >> command >> cust;
        if(command == 'C')
            line.push(cust);
        if(command == 'R')
        {
            registers[cust - 1].push_back(line.front());
            len[cust - 1] ++;
            line.pop();
        }
    }
    for(int i = 0; i < n; i ++)
    {
        if(i != cust - 1)
        {
            cout << len[i] << " ";
            for(int j = 0; j < len[i]; j ++)
                cout << registers[i][j] << " ";
        }
        else
        {
            cout << len[i] - 1 << " ";
            for(int j = 0; j < len[i] - 1; j ++)
                cout << registers[i][j] << " ";
        }
        
        cout << "\n";
    }
}
