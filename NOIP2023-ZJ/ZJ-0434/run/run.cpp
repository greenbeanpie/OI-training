#include<bits/stdc++.h>
using namespace std;
int wt[1005];
int hst[1005];
long long dp[2005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        for(int i=0;i<=1004;i++){
            wt[i]=0;
            hst[i]=0;
        }
        for(int i=0;i<=2004;i++){
            dp[i]=0;
        }
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        while(m--){
            int x,y,v;
            cin>>x>>y>>v;

            for(int i=max(0,x-k+1);i<=x-y+1;i++){
                wt[i]+=v;
                //cout<<"wow!  "<<i<<" "<<x<<"  "<<y<<" "<<v<<endl;
                hst[i]=max(hst[i],x-i+1);
            }
        }
        /*
        cout<<" wt= ";
        for(int i=1;i<=n;i++)cout<<wt[i]<<" ";
        cout<<endl<<"hst= ";
        for(int i=1;i<=n;i++)cout<<hst[i]<<" ";
        cout<<endl;
        */
        dp[0]=0;
        for(int i=1;i<=n-k;i++){
            dp[k+i]=max(dp[k+i],dp[i]);
            dp[k+i]=max(dp[k+i],dp[i]+wt[i]-k*d);
            dp[hst[i]+i]=max(dp[hst[i]+i],dp[i]);
            dp[hst[i]+i]=max(dp[hst[i]+i],dp[i]+wt[i]-hst[i]*d);
        }
        long long ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(dp[i],ans);
        }
        cout<<ans<<endl;
    }
    //170pts+?Please say 'Happy AFO' to me.
    return 0;
}
