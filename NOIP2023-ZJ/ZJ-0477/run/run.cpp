#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,k,d,Ans;
long long a[100002],b[100002],x[100002],y[100002],v[100002];
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c==1||c==2)
    {
        while(t--)
        {
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;++i) cin>>x[i]>>y[i]>>v[i];
            Ans=0;
            for(int i=0;i<=n;++i) b[i]=0;
            while(!b[0])
            {
                int i=n;
                while(b[i]) b[i--]=0;
                b[i]=1;
                long long ma=0,sum=0;
                for(int i=1;i<=n;++i)
                    if(b[i]==1) sum++;
                    else
                    {
                        ma=max(ma,sum);
                        sum=0;
                    }
                ma=max(ma,sum);
                if(ma>k) continue;
                long long ans=0;
                for(int i=1;i<=n;++i) a[i]=a[i-1]+b[i],ans-=d*b[i];
                for(int i=1;i<=m;++i) if(a[x[i]]-a[x[i]-y[i]]==y[i]) ans+=v[i];
                // for(int i=1;i<=n;++i) cout<<a[i]<<" ";cout<<"\n";
                // for(int i=1;i<=n;++i) cout<<b[i]<<" ";cout<<ans<<"\n";
                Ans=max(ans,Ans);
            }
            cout<<Ans<<"\n";
        }
        return 0;
    }
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;++i) cin>>x[i]>>y[i]>>v[i];
		for(int i=1;i<=m;++i) if(y[i]<k&&y[i]*d<v[i]) Ans+=v[i]-y[i]*d;
        cout<<Ans<<"\n";
    }
    return 0;
}
