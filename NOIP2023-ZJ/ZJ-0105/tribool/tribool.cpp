#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m,ans,fa[1000010];
int op[1000010],val[1000010],vis[1000010];
// op=1 +
// op=2 -
// op=3 T
// op=4 F
// op=5 U
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    x=find(x),y=find(y);
    fa[x]=y;
    return ;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%d",&n,&m),ans=0;
        for(int i=1;i<=n+n;i++) fa[i]=i,vis[i]=0;
        for(int i=1;i<=n;i++) op[i]=1,val[i]=i;
        // printf("123\n");
        for(int i=1;i<=m;i++)
        {
            int x,y;
            char s;
            s=getchar();
            while(s!='+'&&s!='-'&&s!='T'&&s!='F'&&s!='U') s=getchar();
            if(s=='+')
            {
                scanf("%d%d",&x,&y);
                op[x]=op[y],val[x]=val[y];
            }
            if(s=='-')
            {
                scanf("%d%d",&x,&y);
                if(op[y]==1) op[x]=2;
                else if(op[y]==2) op[x]=1;
                else if(op[y]==3) op[x]=4;
                else if(op[y]==4) op[x]=3;
                else if(op[y]==5) op[x]=5;
                val[x]=val[y];
            }
            if(s=='T') scanf("%d",&x),op[x]=3,val[x]=0;
            if(s=='F') scanf("%d",&x),op[x]=4,val[x]=0;
            if(s=='U') scanf("%d",&x),op[x]=5,val[x]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(op[i]==1) merge(i,val[i]),merge(i+n,val[i]+n);
            if(op[i]==2) merge(i+n,val[i]),merge(i,val[i]+n);
        }
        for(int i=1;i<=n;i++) if(find(i)==find(i+n)||op[i]==5) vis[find(i)]=1,vis[find(i+n)]=1;
        for(int i=1;i<=n;i++) if(vis[find(i)]||vis[find(i+n)]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
/*
1 1
3 3
- 2 1
- 3 2
+ 1 3
*/
