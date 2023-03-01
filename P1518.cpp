#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("P1518.in", "r", stdin);
    string field[10];
    int dc = 0, df = 0;
    pair<int, int> cow, farmer;
    for (int i = 0; i < 10; i++)
    {
        cin >> field[i];
        for (int j = 0; j < 10; j++)
        {
            if (field[i][j] == 'C')
            {
                cow.first = i;
                cow.second = j;
            }
            if (field[i][j] == 'F')
            {
                farmer.first = i;
                farmer.second = j;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= 100000; i++)
    {
        switch (dc)
        {
        case 0:
            if (cow.first == 0)
            {
                dc = 1;
                break;
            }
            if (field[cow.first - 1][cow.second] == '*')
            {
                dc = 1;
            }
            else
            {
                field[cow.first - 1][cow.second] = 'C';
                field[cow.first][cow.second] = '.';
                cow.first--;
            }
            break;
        case 1:
            if (cow.second == 9)
            {
                dc = 2;
                break;
            }
            if (field[cow.first][cow.second + 1] == '*')
            {
                dc = 2;
            }
            else
            {
                field[cow.first][cow.second + 1] = 'C';
                field[cow.first][cow.second] = '.';
                cow.second++;
            }
            break;
        case 2:
            if (cow.first == 9)
            {
                dc = 3;
                break;
            }
            if (field[cow.first + 1][cow.second] == '*')
            {
                dc = 3;
            }
            else
            {
                field[cow.first + 1][cow.second] = 'C';
                field[cow.first][cow.second] = '.';
                cow.first++;
            }
            break;
        case 3:
            if (cow.second == 0)
            {
                dc = 0;
                break;
            }
            if (field[cow.first][cow.second - 1] == '*')
            {
                dc = 0;
            }
            else
            {
                field[cow.first][cow.second - 1] = 'C';
                field[cow.first][cow.second] = '.';
                cow.second--;
            }
            break;
        }
        switch (df)
        {
        case 0:
            if (farmer.first == 0)
            {
                df = 1;
                break;
            }
            if (field[farmer.first - 1][farmer.second] == '*')
            {
                df = 1;
            }
            else
            {
                field[farmer.first - 1][farmer.second] = 'F';
                field[farmer.first][farmer.second] = '.';
                farmer.first--;
            }
            break;
        case 1:
            if (farmer.second == 9)
            {
                df = 2;
                break;
            }
            if (field[farmer.first][farmer.second + 1] == '*')
            {
                df = 2;
            }
            else
            {
                field[farmer.first][farmer.second + 1] = 'F';
                field[farmer.first][farmer.second] = '.';
                farmer.second++;
            }
            break;
        case 2:
            if (farmer.first == 9)
            {
                df = 3;
                break;
            }
            if (field[farmer.first + 1][farmer.second] == '*')
            {
                df = 3;
            }
            else
            {
                field[farmer.first + 1][farmer.second] = 'F';
                field[farmer.first][farmer.second] = '.';
                farmer.first++;
            }
            break;
        case 3:
            if (farmer.second == 0)
            {
                df = 0;
                break;
            }
            if (field[farmer.first][farmer.second - 1] == '*')
            {
                df = 0;
            }
            else
            {
                field[farmer.first][farmer.second - 1] = 'F';
                field[farmer.first][farmer.second] = '.';
                farmer.second--;
            }
            break;
        }
        sum++;
        if (cow.first == farmer.first && cow.second == farmer.second)
        {
            cout << sum;
            return 0;
        }
    }
    cout << 0;
    return 0;
}