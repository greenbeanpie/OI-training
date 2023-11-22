#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lc(x) ((x)<<1)
#define rc(x) ((x)<<1|1)
inline int read(){
	int w=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) w=w*10+ch-'0',ch=getchar();
	return w;
}
int t,testid;
int n,m,k,dt;
struct node{
	int l,r,v;
}d[100005];
bool cmp(node a1,node a2){return a1.r<a2.r;}
struct sgt{
	int tag[500005],c[500005];
	void build(int x,int l,int r){
		tag[x]=c[x]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
	}
	void pushdown(int x){
		if(!tag[x]) return;
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];
		c[lc(x)]+=tag[x];c[rc(x)]+=tag[x];
		tag[x]=0;
	}
	void add(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr) return tag[x]+=val,c[x]+=val,void();
		int mid=(l+r)>>1;
		pushdown(x);
		if(ql<=mid) add(lc(x),l,mid,ql,qr,val);
		if(qr>mid) add(rc(x),mid+1,r,ql,qr,val);
		c[x]=max(c[lc(x)],c[rc(x)]);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr) return c[x];
		int mid=(l+r)>>1,ans=0;
		pushdown(x);
		if(ql<=mid) ans=query(lc(x),l,mid,ql,qr);
		if(qr>mid) ans=max(ans,query(rc(x),mid+1,r,ql,qr));
		return ans;
	}
}ds;
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/
int dp[100005][105];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	testid=read(),t=read();
	while(t--){
		n=read(),m=read(),k=read(),dt=read();
		for(int i=1;i<=m;i++){
			int x=read(),y=read(),val=read();
			d[i]={x-y+1,x,val};
		}
		sort(d+1,d+1+m,cmp);
		if(testid<=14){
			ds.build(1,0,n);
			for(int i=1,tot=1;i<=n;i++){
				int ql=max(0ll,(i-k-1)),qr=i-1;
				int nw=ds.query(1,0,n,ql,qr)+dt;
				ds.add(1,0,n,i,i,nw);
				while(tot<=m&&d[tot].r==i){
					ds.add(1,0,n,0,d[tot].l-1,d[tot].v);
					tot++;
				}
			}
			int ql=n-k,qr=n;
			printf("%lld\n",ds.query(1,0,n,ql,qr)-dt*n);
		}else{
			if(testid<=16){
				memset(dp,-0x3f,sizeof(dp));
				dp[0][0]=0;
				for(int i=1;i<=m;i++){
					int lv=(d[i].r-d[i-1].r);
					for(int j=lv;j<=k;j++) dp[i][j]=dp[i-1][j-lv]-lv*dt+(j>=(d[i].r-d[i].l+1))*d[i].v;
					int mx=0;
					for(int j=0;j<=k;j++) mx=max(mx,dp[i-1][j]);
					for(int j=0;j<lv&&j<=k;j++){
						dp[i][j]=mx-j*dt+(j>=(d[i].r-d[i].l+1))*d[i].v;
					}
				}
				int mx=0;
				for(int j=0;j<=k;j++) mx=max(mx,dp[m][j]);
				printf("%lld\n",mx);
			}else{
				int ans=0;
				for(int i=1;i<=m;i++){
					ans+=max(0ll,d[i].v-(d[i].r-d[i].l+1)*dt);
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}