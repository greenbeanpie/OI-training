#include<bits/stdc++.h>
using namespace std;
int c,n,m,s,x1,x2,T,i,ans[100005];
struct STU{int x,d;}f[100005],fx,fy;
char opt;
inline void read(int &x)
{
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
}
STU find(int x)
{
    if(f[x].x==x)return f[x];
    STU xx=find(f[x].x);
    f[x].x=xx.x,f[x].d^=xx.d;
    return f[x];
}
int get(int x,int d)
{
    if(x<3&&d)return 3-x;
    return x;
}
int main()
{
    //freopen("tribool.in","r",stdin);
    //freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&m),getchar();
        for(i=1;i<=n+3;i++)f[i].x=i;
        for(i=1;i<=m;i++)
        {
            opt=getchar();
            //cout<<opt<<endl;
            if(opt=='+')
            {
                read(x1),read(x2);
                fx=find(x1),fy=find(x2);
                if(fx.x==fy.x){
                    if((fx.d^fy.d)!=0)ans[fx.x]=-1;}
                else f[x1].x=fy.x,f[x1].d=0^fy.d;
            }
            if(opt=='-')
            {
                read(x1),read(x2);
                fx=find(x1),fy=find(x2);
                cout<<fy.x<<" d="<<fy.d<<endl;
                if(fx.x==fy.x){
                    if((fx.d^fy.d)!=1)ans[fx.x]=-1;}
                else f[x1].x=fy.x,f[x1].d=1^fy.d;
                //cout<<f[x1].d<<endl;
            }
            if(opt=='T')read(x1),x2=n+1,f[x1]={n+1,0};
            if(opt=='F')read(x1),x2=n+2,f[x1]={n+2,0};
            if(opt=='U')read(x1),x2=n+3,f[x1]={n+3,0};
            //cout<<"x1="<<x1<<" x2="<<x2<<endl;
        }
        for(i=1;i<=n;i++)STU p=find(f[i].x);
        cout<<f[1].x<<" "<<f[1].d<<endl;
        for(i=1;i<=n;i++)cout<<"fx="<<f[i].x<<"   diff="<<f[i].d<<endl;
        for(i=1;i<=n;i++)
            if((f[i].x==i&&f[i].d==1)||f[i].x==n+3)ans[i]=-1;
        for(i=1;i<=n;i++)
            if(f[i].x!=i&&f[i].x<=n)ans[i]=ans[f[i].x];
        s=0;
        cout<<endl;
        for(i=1;i<=n;i++)cout<<setw(4)<<ans[i];
        cout<<endl;
        for(i=1;i<=n;i++)s+=(ans[i]==-1);
        printf("%d\n",s);
    }
}
