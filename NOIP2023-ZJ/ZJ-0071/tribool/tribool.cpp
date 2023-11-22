#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
// #define int long long
inline int read()
{
    int x=0,f=1,c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)x=x*10+c-48,c=getchar();
    return x*f;
}
int fa[1234567];
int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}
void uf(int x,int y){fa[f(x)]=f(y);}
int res[1234567],sgn[1234567];
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C=read(),T=read();
    while(T--)
    {
        int n=read(),m=read();
        for(int i=1;i<=n*2;i++)fa[i]=i;
        for(int i=1;i<=n;i++)res[i]=i,sgn[i]=0;
        for(int i=1;i<=m;i++)
        {
            char ss[4];scanf("%s",ss);
            char s=ss[0];
            if(s=='+')
            {
                int u=read(),v=read();
                res[u]=res[v];
                sgn[u]=sgn[v];
            }
            else if(s=='-')
            {
                int u=read(),v=read();
                if(res[v]>0)
                {
                    res[u]=res[v];
                    sgn[u]=!sgn[v];
                }
                else
                {
                    if(res[v]==-3)res[u]=-3;
                    else if(res[v]==-1)res[u]=-2;
                    else res[u]==-1;
                }
            }
            else if(s=='U')
            {
                int u=read();
                res[u]=-3;
            }
            else
            {
                int u=read();
                res[u]=(s=='T'?-1:-2);
            }
        }
        for(int u=1;u<=n;u++)
        {
            if(res[u]<0)
            {
                if(res[u]==-3)uf(u,u+n);
            }
            else
            {
                int v=res[u];
                if(sgn[u])uf(u,v+n),uf(u+n,v);
                else uf(u,v),uf(u+n,v+n);
            }
        }
        int r=0;
        for(int i=1;i<=n;i++)r+=f(i)==f(i+n);
        printf("%d\n",r);
    }
}