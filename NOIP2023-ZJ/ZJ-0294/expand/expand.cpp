#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q,x[N],y[N],ans[N],kx,ky,t1[N],t2[N],L[N];
bool a[2005][2005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>x[i],t1[i]=x[i];
    for(int i=1;i<=m;i++) cin>>y[i],t2[i]=y[i];
    if(c==1)
    {
        for(int w=1;w<=q+1;w++)
        {
            cout<<(x[1]!=y[1]);
            if(w<=q)
            {
                for(int i=1;i<=n;i++) x[i]=t1[i];
                for(int i=1;i<=m;i++) y[i]=t2[i];
                cin>>kx>>ky;
                for(int j=1,r,c;j<=kx;j++) 
                {
                    cin>>r>>c;
                    x[r]=c;
                }
                for(int j=1,r,c;j<=ky;j++) 
                {
                    cin>>r>>c;
                    y[r]=c;
                }
            }
        }
    }
    else if(c==2)
    {
        for(int w=1;w<=q+1;w++)
        {
            if(x[1]>y[1])
            {
                if(x[2]<=y[2]) cout<<0;
                else cout<<1;
            }   
            else if(x[1]<y[1])
            {
                if(x[2]>=y[2]) cout<<0;
                else cout<<1;
            } 
            else ans[w]=0;
            if(w<=q)
            {
                for(int i=1;i<=n;i++) x[i]=t1[i];
                for(int i=1;i<=m;i++) y[i]=t2[i];
                cin>>kx>>ky;
                for(int j=1,r,c;j<=kx;j++) 
                {
                    cin>>r>>c;
                    x[r]=c;
                }
                for(int j=1,r,c;j<=ky;j++) 
                {
                    cin>>r>>c;
                    y[r]=c;
                }
            }
        }
    }
    else if(c<=14&&c>=8)
    {
        
        for(int w=1;w<=q+1;w++)
        {
            ans[w]=1;
            if(x[n]>=y[m]) 
            {
                ans[w]=0;
            }
            else
            {
                int p1=n;
                for(int i=m;i>=1;i--)
                {
                    while(y[i]>x[p1]&&p1>=1) p1--;
                }
                if(p1) ans[w]=0;
            }
            if(w<=q)
            {
                for(int i=1;i<=n;i++) x[i]=t1[i];
                for(int i=1;i<=m;i++) y[i]=t2[i];
                cin>>kx>>ky;
                for(int j=1,r,c;j<=kx;j++) 
                {
                    cin>>r>>c;
                    x[r]=c;
                }
                for(int j=1,r,c;j<=ky;j++) 
                {
                    cin>>r>>c;
                    y[r]=c;
                }
            }
            cout<<ans[w];
        }
    }
    return 0;
}