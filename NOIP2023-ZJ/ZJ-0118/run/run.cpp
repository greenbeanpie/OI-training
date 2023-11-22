#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define long long long
long dp[100010];int n,m,k,d,T;
struct sd{int v,l;};basic_string<sd>c[100010];
long t[1000010],lz[1000010];
void bld(int p,int l,int r){
	t[p]=lz[p]=0;if(l==r)return;
	bld(p<<1,l,(l+r)>>1);
	bld(p<<1|1,((l+r)>>1)+1,r);
}
void down(int p){
	t[p<<1]+=lz[p],lz[p<<1]+=lz[p];
	t[p<<1|1]+=lz[p],lz[p<<1|1]+=lz[p];
}
void add(int p,int l,int r,int i,int j,long x){
	if(i<=l&&r<=j){t[p]+=x,lz[p]+=x;return;}
	if(lz[p])down(p),lz[p]=0;
	if(i<=((l+r)>>1))add(p<<1,l,(l+r)>>1,i,j,x);
	if(j>((l+r)>>1))add(p<<1|1,((l+r)>>1)+1,r,i,j,x);
	t[p]=max(t[p<<1],t[p<<1|1]);
}
void mak(int p,int l,int r,int k,long x){
	if(l==r){t[p]=x;return;}
	if(lz[p])down(p),lz[p]=0;
	if(k<=((l+r)>>1))mak(p<<1,l,(l+r)>>1,k,x);
	else mak(p<<1|1,((l+r)>>1)+1,r,k,x);
	t[p]=max(t[p<<1],t[p<<1|1]);
}
long qry(int p,int l,int r,int i,int j){
	if(i<=l&&r<=j)return t[p];long ret=0;
	if(lz[p])down(p),lz[p]=0;
	if(i<=((l+r)>>1))ret=max(ret,qry(p<<1,l,(l+r)>>1,i,j));
	if(j>((l+r)>>1))ret=max(ret,qry(p<<1|1,((l+r)>>1)+1,r,i,j));
	return ret;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	for(scanf("%d%d",&T,&T);T--;){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=n;i++)c[i].clear();
		for(int i=1,x,y,z;i<=m;i++)
			scanf("%d%d%d",&x,&y,&z),c[x]+=(sd){z,x-y+1};
		n++;bld(1,1,n);
		long mx1=0,mx2=0;
		for(int i=1;i<=n;i++){
			mak(1,1,n,i,mx2),add(1,1,n,max(1,i-k+1),i,-d);
			for(sd x:c[i])add(1,1,n,max(1,i-k+1),x.l,x.v);
			mx2=max(mx2,mx1),mx1=qry(1,1,n,max(1,i-k+1),i);
		}
		cout<<max(mx2,mx1)<<endl;
	}
	return 0;
}
