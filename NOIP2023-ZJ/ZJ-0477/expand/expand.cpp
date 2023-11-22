#include<bits/stdc++.h>
using namespace std;
const int inf=2e9;
int c,n,m,q,x,y,kx,ky,ma1,ma2,mi1,mi2;
int a[500002],b[500002],A[500002],B[500002];
bool dp[2002][2002];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;++i) cin>>a[i],A[i]=a[i];
    for(int i=1;i<=m;++i) cin>>b[i],B[i]=b[i];
    if(c==1)
    {
        cout<<(int)(a[1]!=b[1]);
        while(q--)
        {
            cin>>kx>>ky;
            for(int i=1;i<=kx;++i) cin>>x>>y,a[x]=y;
            for(int i=1;i<=ky;++i) cin>>x>>y,b[x]=y;
            cout<<(int)(a[1]!=b[1]);
            for(int i=1;i<=n;++i) a[i]=A[i];
            for(int i=1;i<=m;++i) b[i]=B[i];
        }
        return 0;
    }
    if(c>=2&&c<=7)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                dp[i][j]=0;
        if(a[1]<b[1]) swap(a,b);
        x=m+1;
        for(int i=1;i<=m;++i) if(a[1]<=b[i]) {x=i;break;}
        for(int i=1;i<x;++i) dp[1][i]=1;
        y=n+1;
        for(int i=1;i<=n;++i) if(b[1]>=a[i]) {y=i;break;}
        for(int i=1;i<y;++i) dp[i][1]=1;
        for(int i=2;i<=n;++i)
            for(int j=2;j<=m;++j)
            {
                if(a[i]<=b[j]) {dp[i][j]=0;continue;}
                dp[i][j]|=(dp[i-1][j-1]&&(a[i]>b[j]));
                if(!dp[i][j])
                {
                    for(int k=i-1;k>=1;--k)
                    {
                        if(a[k]<=b[j]) break;
                            else dp[i][j]|=dp[k-1][j-1];
                    }
                }
                if(!dp[i][j])
                {
                    for(int k=j-1;k>=1;--k)
                    {
                        if(a[i]<=b[k]) break;
                            else dp[i][j]|=dp[i-1][k-1];
                    }
                }
            }
        // for(int i=1;i<=n;++i)
        // {
        //     for(int j=1;j<=m;++j) cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        cout<<dp[n][m];
        for(int i=1;i<=n;++i) a[i]=A[i];
        for(int i=1;i<=m;++i) b[i]=B[i];
        while(q--)
        {
            cin>>kx>>ky;
            for(int i=1;i<=kx;++i) cin>>x>>y,a[x]=y;
            for(int i=1;i<=ky;++i) cin>>x>>y,b[x]=y;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j)
                    dp[i][j]=0;
            if(a[1]<b[1]) swap(a,b);
            x=m+1;
            for(int i=1;i<=m;++i) if(a[1]<=b[i]) {x=i;break;}
            for(int i=1;i<x;++i) dp[1][i]=1;
            y=n+1;
            for(int i=1;i<=n;++i) if(b[1]>=a[i]) {y=i;break;}
            for(int i=1;i<y;++i) dp[i][1]=1;
            for(int i=2;i<=n;++i)
                for(int j=2;j<=m;++j)
                {
                    if(a[i]<=b[j]) {dp[i][j]=0;continue;}
                    dp[i][j]|=(dp[i-1][j-1]&&(a[i]>b[j]));
                    if(!dp[i][j])
                    {
                        for(int k=i-1;k>=1;--k)
                        {
                            if(a[k]<=b[j]) break;
                                else dp[i][j]|=dp[k-1][j-1];
                        }
                    }
                    if(!dp[i][j])
                    {
                        for(int k=j-1;k>=1;--k)
                        {
                            if(a[i]<=b[k]) break;
                                else dp[i][j]|=dp[i-1][k-1];
                        }
                    }
                }
            cout<<dp[n][m];
            for(int i=1;i<=n;++i) a[i]=A[i];
            for(int i=1;i<=m;++i) b[i]=B[i];
        }
        return 0;
    }
    ma1=ma2=0;mi1=mi2=inf;
    for(int i=1;i<=n;++i) ma1=max(ma1,a[i]),mi1=min(mi1,a[i]);
    for(int i=1;i<=n;++i) ma2=max(ma2,b[i]),mi2=min(mi2,b[i]);
    if((ma1>ma2&&mi1>mi2)||(ma1<ma2&&mi1<mi2)) cout<<1;
        else cout<<0;
    while(q--)
    {
        cin>>kx>>ky;
        for(int i=1;i<=kx;++i) cin>>x>>y,a[x]=y;
        for(int i=1;i<=ky;++i) cin>>x>>y,b[x]=y;
        ma1=ma2=0;mi1=mi2=inf;
        for(int i=1;i<=n;++i) ma1=max(ma1,a[i]),mi1=min(mi1,a[i]);
        for(int i=1;i<=n;++i) ma2=max(ma2,b[i]),mi2=min(mi2,b[i]);
        if((ma1>ma2&&mi1>mi2)||(ma1<ma2&&mi1<mi2)) cout<<1;
            else cout<<0;
    }
    return 0;
}