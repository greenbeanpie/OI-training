#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
inline int read(){
	int f=1,w=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c>='0'&& c<='9'){
		w=(w<<1)+(w<<3)+(c^48);
		c=getchar();
	}
	return f*w;
}
int f[1010][1010];
int c,T;
int n,m,K,d;
struct node{
	int x,y,v;
}q[100010];
struct point{
	int y;
	int v;
};
vector <point> vis[10010];
namespace sub1{
	int sum[10010];
	void work(){
		n=read();
		m=read();
		K=read();
		d=read();
		for(int i=1;i<=n;i++)	 vis[i].clear();
		for(int i=1;i<=m;i++){
			q[i].x=read();
			q[i].y=read();
			q[i].v=read();
			vis[q[i].x].push_back({q[i].y,q[i].v});
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=K;j++){
				f[i][j]=-inf;
			}
		}
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			if(vis[i].size()){
				for(int j=0;j<=K;j++){
					sum[j]=0;
				}
				for(int op=0;op<(int)vis[i].size();op++){
					int lim=vis[i][op].y;
					int val=vis[i][op].v;
//					for(int j=0;j<=K;j++){
//						if(j==0){
//							for(int k=0;k<=K;k++){
//								f[i][j]=max(f[i][j],f[i-1][k]);
//							}
//						}else if(j<lim){
//							f[i][j]=max(f[i-1][j-1]-d,f[i][j]);
//						}else{
//							f[i][j]=max(f[i][j],f[i-1][j-1]-d+val);
//						}
//					}
					for(int j=0;j<=K;j++){
						if(j>=lim){
							sum[j]+=val;
						}
					}
				}
				for(int j=0;j<=K;j++){
					if(j==0){
						for(int k=0;k<=K;k++){
							f[i][j]=max(f[i][j],f[i-1][k]+sum[j]);
						}
					}else{
						f[i][j]=max(f[i-1][j-1]-d+sum[j],f[i][j]);
					}
				}
				continue;
			}
			for(int j=0;j<=K;j++){
				if(j==0){
					for(int k=0;k<=K;k++){
						f[i][j]=max(f[i][j],f[i-1][k]);
					}
				}else{
					f[i][j]=max(f[i-1][j-1]-d,f[i][j]);
				}
			}
		}
		int ans=-inf;
		for(int i=0;i<=K;i++){
			ans=max(ans,f[n][i]);
		}
		cout<<ans<<endl;
	}
}
namespace sub2{
	void work(){
		n=read();
		m=read();
		K=read();
		d=read();
		int ans=-d*n;
		for(int i=1;i<=m;i++){
			q[i].x=read();
			q[i].y=read();
			q[i].v=read();
			ans+=q[i].v;
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	T=read();
	if(c<=9){
		while(T--){
			sub1::work();
		}
		return 0;
	}
	while(T--){
		sub2::work();
	}
	return 0;
}