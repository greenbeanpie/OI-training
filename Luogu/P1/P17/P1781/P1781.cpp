#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    string b;
    string max;
    int num;
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        if (b.length() > max.length())
        {
            max = b;
            num = i + 1;
        }
        else if (b.length() == max.length())
        {

            if (b>max)
            {
                max = b;
                num = i + 1;
            }
        }
    }
    cout << num << endl << max;
    return 0;
}