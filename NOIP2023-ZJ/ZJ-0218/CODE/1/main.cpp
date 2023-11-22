#include<bits/stdc++.h>
using namespace std;
int p,n,m,tag,mini,i,j,k,tong[3005][35],a[3005][3005];
bool cmp(int x,int y)
{
    for(int i=1;i<=n;i++)
    {
        if(a[x][i]>a[y][i]){tag=0;return 1;}
        else if(a[x][i]<a[y][i])return 0;
    }
    tag=1;
    return 0;
}
bool check(int x)
{
    int j=0;
    for(int i=1;i<=26;i++)
        while(tong[x][i])a[n+1][++j]=i,--tong[x][i];
    return cmp(mini,n+1);
}
bool same(int x)
{
    int k=0;
    for(i=1;i<=26;i++)k+=(tong[x][i]>0);
    return k==1;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m),getchar();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)a[i][j]=getchar()-96,++tong[i][a[i][j]];
        getchar();
    }
    if(n==1){printf("1");return 0;}
    for(i=1;i<=n;i++)
    {
        int xx=0;
        for(j=26;j>=1;j--)
            for(k=1;k<=tong[i][j];k++)a[i][++xx]=j;
    }
    mini=1;
    for(i=2;i<=n;i++)
        if(cmp(mini,i))mini=i;
    if(tag&&same(mini))p=1;
    for(i=1;i<=n;i++)
        if(check(i)||(i==mini&&!p))printf("1");
        else printf("0");
    return 0;
}
