#include"cstdio"
#include"algorithm"
#include"cstring"
char c[3100][3100];
int a[3100][3100];
int n,m;
int m1[3100],t1;
int m2[3100],t2;
int ans[3100];
inline int p(int a[],int b[])
{
    for(int i=1;i<=m;i++)
    {
        if(a[i]<b[i])return 1;
        if(a[i]>b[i])return 0;
    }
    return 0;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c[i]);
        for(int j=0;j<m;j++)
        {
            a[i][j+1]=c[i][j]-'a'+1;
        }
        std::sort(a[i]+1,a[i]+m+1);
    }
    m1[1]=28;
    m2[1]=28;
    for(int i=1;i<=n;i++)
    {
        int p=1;
        for(int j=m;j;j--)
        {
            if(p==1&&a[i][j]<m1[m-j+1])p=2;
            if(p==1&&a[i][j]>m1[m-j+1])p=0;
            if(p!=1)break;
        }
        if(p==2)
        {
            t2=t1,t1=i;
            for(int j=m;j;j--)
            {
                m2[m-j+1]=m1[m-j+1];
                m1[m-j+1]=a[i][j];
            }
            continue;
        }
        p=1;
        for(int j=m;j;j--)
        {
            if(p==1&&a[i][j]<m2[m-j+1])p=2;
            if(p==1&&a[i][j]>m2[m-j+1])p=0;
            if(p!=1)break;
        }
        if(p==2)
        {
            t2=i;
            for(int j=m;j;j--)
            {
                m2[m-j+1]=a[i][j];
            }
            continue;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=t1)
        {
            ans[i]=p(a[i],m1);
        }
        else ans[i]=p(a[i],m2);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
