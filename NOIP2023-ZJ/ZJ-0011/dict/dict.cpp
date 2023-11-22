#include<bits/stdc++.h>
using namespace std;
long long a,b,m1[1000001],m2[1000001],mxx1,mxx2;
char s[1000001];
int main()
{
//    freopen("dict4.in","r",stdin);
//    freopen("1.out","w",stdout);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    mxx1=mxx2=1e9;
    scanf("%lld%lld",&a,&b);
    for(int i=1;i<=a;i++)
    {
        scanf("%s",s+1);
        long long mn=1e9,mx=0;
        for(int j=1;j<=b;j++)
        {
            mn=min(mn,(long long)s[j]);
            mx=max(mx,(long long)s[j]);
        }
        m1[i]=mn,m2[i]=mx;
        if(mx<mxx1) mxx2=mxx1,mxx1=mx;
        else if(mx<mxx2) mxx2=mx;
    }
    for(int i=1;i<=a;i++)
    {
        if(m2[i]==mxx1)
        {
            if(mxx2<=m1[i])
            {
                putchar('0');
            }
            else putchar('1');
        }
        else
        {
            if(mxx1<=m1[i])
            {
                putchar('0');
            }
            else putchar('1');
        }
    }printf("\n");
    return 0;
}