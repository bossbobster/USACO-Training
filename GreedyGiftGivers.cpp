#include <iostream>
#include <string>
using namespace std;

string people[100];
int values[100];
int main()
{
    int n, money, numOfPeople, place = 0;
    string person = "a";
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> people[i];
    for(int i = 0; i < n; i ++)
    {
        cin >> person >> money >> numOfPeople;
        for(int j = 0; j < n; j ++)
        {
            if(people[j] == person)
            {
                place = j;
                break;
            }
        }
        for(int j = 0; j < numOfPeople; j ++)
        {
            values[place] -= (money / numOfPeople);
        }
        for(int j = 0; j < numOfPeople; j ++)
        {
            cin >> person;
            for(int j = 0; j < n; j ++)
            {
                if(people[j] == person)
                {
                    place = j;
                    break;
                }
            }
            values[place] += (money / numOfPeople);
        }
    }
    for(int i = 0; i < n; i ++)
        cout << people[i] << " " << values[i] << endl;
}
