// const string tsh="forever friends"
// rp++;
// return "退役";
// No "No, Commander" again
// g++ -Wall -O2 -std=c++14 expand.cpp -o expand_exec
// ./expand_exec

#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fo(_var,_a,_b) for(int _var=_a;_var<=_b;_var++)
#define fr(_var,_a,_b) for(int _var=_a;_var>=_b;_var--)
#define foo(_var,_a,_b,_c) for(int _var=_a;_var<=_b;_var+=_c)
#define frr(_var,_a,_b,_c) for(int _var=_a;_var>=_b;_var-=_c)

int c,n,m,q;
int a[2010],b[2010];
int _a[2010],_b[2010];
int minn[2010],maxx[2010];

void cpy()
{
    fo(i,1,n)
    {
        a[i]=_a[i];
    }
    fo(i,1,m)
    {
        b[i]=_b[i];
    }
    return ;
}

void change()
{
    int x,y;
    scanf("%d%d",&x,&y);
    fo(i,1,x)
    {
        int p,v;
        scanf("%d%d",&p,&v);
        a[p]=v;
    }
    fo(i,1,y)
    {
        int p,v;
        scanf("%d%d",&p,&v);
        b[p]=v;
    }
    return ;
}

void query()
{
    int flag=0;
    int i,j;
    for(i=1,j=1;i<=n&&j<=m;)
    {
        if(a[i]>=b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
        if(i==n&&j==m)
        {
            flag=1;
        }
    }
    for(i=1,j=1;i<=n&&j<=m;)
    {
        if(a[i]<=b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
        if(i==n&&j==m)
        {
            flag=1;
        }
    }
    printf("%d",flag);
    return ;
}

void solve()
{
    scanf("%d%d%d",&n,&m,&q);
    fo(i,1,n)
    {
        scanf("%d",&_a[i]);
    }
    fo(i,1,m)
    {
        scanf("%d",&_b[i]);
    }
    cpy();
    query();
    fo(i,1,q)
    {
        cpy();
        change();
        query();
    }
    printf("\n");
    return ;
}

void query0()
{
    if(a[1]!=b[1])
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return; 
}
void solve0()
{
    scanf("%d%d%d",&n,&m,&q);
    fo(i,1,n)
    {
        scanf("%d",&_a[i]);
    }
    fo(i,1,m)
    {
        scanf("%d",&_b[i]);
    }
    cpy();
    query0();
    fo(i,1,q)
    {
        cpy();
        change();
        query0();
    }
    printf("\n");
    return ;
}

void query6()
{
    if(a[1]==b[1]||a[2]==b[2])
    {
        printf("0");
    }
    else if(a[1]<b[1]&&a[2]>b[2])
    {
        printf("0");
    }
    else if(a[1]>b[1]&&a[2]<b[2])
    {
        printf("0");
    }
    else
    {
        printf("1");
    }
    return; 
}
void solve6()
{
    scanf("%d%d%d",&n,&m,&q);
    fo(i,1,n)
    {
        scanf("%d",&_a[i]);
    }
    fo(i,1,m)
    {
        scanf("%d",&_b[i]);
    }
    cpy();
    query6();
    fo(i,1,q)
    {
        cpy();
        change();
        query6();
    }
    printf("\n");
    return ;
}


int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d",&c);
    if(c==1)
    {
        solve0();
    }
    if(c==2)
    {
        solve6();
    }
    if(c>2)
    {
        solve();
    }    

    // 多测要清空、要换行
    return 0;
}
