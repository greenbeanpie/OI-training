#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    char s2[3002];
}a[3002];
int n,m;
char s[3002][3002],s1[3002][3002];
bool cmp(node x,node y)
{
    for(int i=1;i<=m;++i)
    {
        if(x.s2[i]<y.s2[i]) return true;
        if(x.s2[i]>y.s2[i]) return false;
    }
    return true;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) cin>>s[i][j],s1[i][j]=a[i].s2[j]=s[i][j];
        a[i].num=i;
        sort(s1[i]+1,s1[i]+m+1,[](char x,char y){return x<y;});
        sort(a[i].s2+1,a[i].s2+m+1,[](char x,char y){return x>y;});
    }
    sort(a+1,a+n+1,cmp);
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=m;++j) cout<<a[i].s2[j];
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=m;++j) cout<<s1[i][j];
    //     cout<<"\n";
    // }
    for(int i=1;i<=n;++i)
    {
        int x=1;
        if(i==a[1].num) x=2;
        int p=0;
        for(int j=1;j<=m;++j)
        {
            if(a[x].s2[j]>s1[i][j]) {p=1;break;}
            if(a[x].s2[j]<s1[i][j]) {p=0;break;}
        }
        cout<<p;
    }
    return 0;
}