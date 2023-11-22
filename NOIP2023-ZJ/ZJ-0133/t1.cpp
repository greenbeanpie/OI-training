#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline int read()
{
    int x=0,f=1;char s=getchar();
    while(s<'0'||s>'9')
    {
        if(s=='-') f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9')
    {
        x=x*10+s-'0';
        s=getchar();
    }
    return x*f;
}

const int N=3005;
int a[N][30];
char s[N];
int lw[N],rw[N];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++) a[i][s[j]-'a']++;
        int l=0,r='z'-'a';
        while(!a[i][l]) l++;
        while(!a[i][r]) r--;
        lw[i]=l,rw[i]=r;
        //printf("%d %d\n",lw[i],rw[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            int l=lw[i],r=rw[j];
            if(l==r)
            {
                if(a[i][l]>=a[j][r])
                {
                    flag=0;
                    break;
                }
            }
            else
            {
                if(l>r)
                {
                    flag=0;
                    break;
                }
            }
        }
        putchar(flag?'1':'0');
    }
    return 0;
}
