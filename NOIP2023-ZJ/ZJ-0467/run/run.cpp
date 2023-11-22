#include<bits/stdc++.h>
using namespace std;
int maxn=0,c,n,m,k,d,t,a[500001],b[500001],tot=0;
long long f[100001][2],g[100001];
void dfs(int step,int ey,int len){
	
	maxn=max(maxn,ey);
	if(step==n) return;
	dfs(step+1,ey,0);
	if(len+1<=k){
		if(a[step+1] and a[step+1]<=len+1){
			dfs(step+1,ey-d+b[step+1],len+1);
		}
		else dfs(step+1,ey-d,len+1);
	}
}
int inline read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9' or ch<'0') ch=getchar();
	while(ch<='9' and ch>='0'){
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	if(c==1 or c==2){
		while(t--){
			n=read();m=read();k=read();d=read();
			maxn=0;
			for(int i=1;i<=m;i++){
				int x=read(),y=read(),z=read();
				a[x]=y,b[x]=z;
			}
			dfs(0,0,0);
			printf("%d\n",maxn);
			for(int i=1;i<=n;i++) a[i]=0,b[i]=0;
		}
	}
	else if(c==17 or c==18){
		while(t--){
			n=read();m=read();k=read();d=read();
			maxn=0;
			long long ans=0;
			for(int i=1;i<=m;i++){
				int x=read(),y=read(),z=read();
				if(y<=k and z-1ll*y*d>0){
					ans+=z-1ll*y*d;
				}
			}
			printf("%lld\n",ans);
		}
	}
}

