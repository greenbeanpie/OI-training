#include <bits/stdc++.h>
using namespace std;
string b[8] = {"0", "BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
struct person
{
    string name, job;
    int h, l, j, num;
};
person list1[120];
bool cmp1(person a, person b)
{
    if (a.h != b.h)
        return a.h > b.h;
    else if (a.j != b.j)
    {
        return a.j < b.j;
    }
    else
    {
        return a.num > b.num;
    }
}
bool cmp2(person a, person b)
{
    if (a.j != b.j)
    {
        return a.j < b.j;
    }
    else if (a.l != b.l)
    {
        return a.l > b.l;
    }
    else
    {
        return a.num < b.num;
    }
}
int main()
{
    freopen("P1786.in","r",stdin);
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> list1[i].name >> list1[i].job >> list1[i].h >> list1[i].l;
        for (int j = 1; j <= 7; j++)
        {
            if (list1[i].job == b[j])
            {
                list1[i].j = j;
            }
        }
        if (list1[i].j == 1 || list1[i].j == 2)
        {
            sum++;
        }
        list1[i].num = i;
    }
    sort(list1 + sum + 1, list1 + n + 1, cmp1);
    for (int i = sum + 1; i <= n; i++)
    {
        if (i - sum <= 2)
        {
            list1[i].job = "HuFa";
            list1[i].j = 3;
        }
        else if (i - sum <= 6)
        {
            list1[i].job = "ZhangLao";
            list1[i].j = 4;
        }
        else if (i - sum <= 13)
        {
            list1[i].job = "TangZhu";
            list1[i].j = 5;
        }
        else if (i - sum <= 38)
        {
            list1[i].job = "JingYing";
            list1[i].j = 6;
        }
        else
        {
            list1[i].job = "BangZhong";
            list1[i].j = 7;
        }
    }
    sort(list1 + 1, list1 + n + 1, cmp2);
    for (int i = 1; i <= n; i++)
    {
        cout << list1[i].name << " " << list1[i].job << " " << list1[i].l << endl;
    }
    return 0;
}