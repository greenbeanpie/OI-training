#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long a, b, c,t=0;
    long long  num[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        for(int j=1;j<=50;j++)
        {
            num[t]=a*j*j+b*j+c;
            t++;
        }
    }
    sort(num,num+t);
    for(int i=0;i<m;i++){
        cout << num[i] << ' ';
    }
    return 0;
}
