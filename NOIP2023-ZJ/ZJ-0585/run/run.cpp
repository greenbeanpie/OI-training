#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=100010;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
struct node{
	int l,r,v,val;
}a[MAXN];
int c,t,n,m,k,d,ans;
int b[MAXN];
inline void dfs(int tot){
	if(tot+1>n){
		int num=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1)num++,cnt-=d;
			if(num>k)return;
		}
		bool flag=0;
		for(int i=1;i<=m;i++)
			if(a[i].val<=k){
				flag=0;
				for(int j=a[i].l;j<=a[i].r;j++)if(b[j]==0){flag=1;break;}
				if(flag==0)cnt+=a[i].v;
			}
		ans=max(ans,cnt);
		return;
	}
	b[tot+1]=0;
	dfs(tot+1);
	b[tot+1]=1;
	dfs(tot+1);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	int x,y,w;
	while(t--){
		ans=0;
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=n;i++)b[i]=0;
		for(int i=1;i<=m;i++){
			x=read();y=read();w=read();
			a[i].r=x;a[i].l=x-y+1;a[i].v=w;a[i].val=y;
		}
		dfs(0);
		printf("%lld\n",ans);
	}
	return 0;
}