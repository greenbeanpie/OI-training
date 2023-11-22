#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e5+5;
int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
struct activ{
    int l,r;
    ll v;
}b[M];
int cid,T,n,m,K,d;
namespace subtask1{
    ll ans;
    int a[20];
    void work(){
        ans=0;
        for(int s=0;s<(1<<n);s++){
            ll res=0;
            int o=0;
            bool flag=1;
            memset(a,0,sizeof(a));
            for(int i=1;flag&&i<=n;i++){
                if((s>>(i-1))&1){
                    o++;
                    a[i]++;
                    res-=d;
                }else o=0;
                if(o>K)flag=0;
            }
            if(!flag)continue;
            for(int i=1;i<=n;i++)a[i]+=a[i-1];
            for(int i=1;i<=m;i++){
                if(a[b[i].r]-a[b[i].l-1]==b[i].r-b[i].l+1)res+=b[i].v;
            }
            ans=max(ans,res);
        }
        printf("%lld\n",ans);
        return;
    }
}
namespace subtaskB{
    void work(){
        ll ans=0;
        for(int i=1;i<=m;i++){
            if(b[i].v>=1ll*(b[i].r-b[i].l+1)*d)ans+=b[i].v-1ll*(b[i].r-b[i].l+1)*d;
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cid=read(),T=read();
    while(T--){
        n=read(),m=read(),K=read(),d=read();
        for(int i=1;i<=m;i++){
            int x=read(),y=read(),v=read();
            b[i]={x-y+1,x,v};
        }
        if(cid<=2)subtask1::work();
        else if(cid==17||cid==18)subtaskB::work();
    }
    return 0;
}