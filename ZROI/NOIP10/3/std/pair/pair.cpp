#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
    int x=0;char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x;
}
struct QQQ{
    int id,l,r;
}q[1000006];
int n,m,a[1000006],c[52];
ll pre[1000006],ans[1000006],sum[51][1000006];
void add(int x,int v){
    for(;x<=50;x+=(x&-x))c[x]+=v;
}
int query(int x){
    int res=0;
    for(;x;x-=(x&-x))res+=c[x];
    return res;
}
void update(int i){
    add(a[i],1);
    pre[i]=pre[i-1]+i-query(a[i]);
    for(int j=1;j<=50;j++){
        if(j>=a[i])sum[j][i]=sum[j][i-1]+1;
        else sum[j][i]=sum[j][i-1];
    }
}
int main(){
	freopen("pair.in","r",stdin);
	freopen("pair.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1,u,v;i<=m;i++){
        u=read(),v=read();
        q[i]={i,u,v};
    }
    sort(q+1,q+1+m,[&](const QQQ a,const QQQ b){return a.r<b.r;});
    int i=0;
    for(int t=1;t<=m;t++){
        int l=q[t].l,r=q[t].r,id=q[t].id;
        while(i<r)update(++i);
        ll res=pre[r]-pre[l-1];
        for(int j=1;j<=50;j++){
            ll s=(sum[j][i]-sum[j][l-1])-(sum[j-1][i]-sum[j-1][l-1]),c=sum[50][l-1]-sum[j][l-1];
            res-=s*c;
        }
        ans[id]=res;
    }
    for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
    return 0;
}
