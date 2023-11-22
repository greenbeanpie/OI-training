#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>void read(T &x){x=0;char ch;bool f=0;while(!isdigit(ch=getchar())) f|=ch=='-';while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();x=f?-x:x;}
template<typename T1,typename ...T2>void read(T1 &x,T2& ...y){read(x);read(y...);}
mt19937 rnd(time(0));
int n,m,k,d;
ll ans,now,xt;
int x[100005],y[100005],v[100005];
bitset<100005>vis,flag;
void work(){
	read(n,m,k,d);ans=0;
	for(int i=1;i<=m;i++){
		read(x[i],y[i],v[i]);
		if(y[i]>k)i--,m--;
	}
	int T=5000;
	while(T--){
		vis.reset();flag.reset();xt=now=0;
		int tt=(rnd()%m+m)%m;
		while(tt--) vis[(rnd()%m+m)%m]=1;
		for(int i=1;i<=m;i++){
			if(vis[i]){
				for(int j=max(0,x[i]-y[i]+1);j<=x[i];j++)
					if(!flag[j])++now,flag[j]=1;
				xt+=v[i];
			}
		}
		int bb=0;
		for(int i=1;i<=n;i++){
			if(bb>k)break;
			if(!flag[i])bb=0;
			else ++bb;
		}
		if(bb<=k)ans=max(xt-now*d,ans);
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;read(c,t);
	while(t--){
		work();
	}
	return 0;
}

