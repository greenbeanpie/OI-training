#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int d,k;
struct node{
	int l,r;
	long long b,z;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define b(x) tree[x].b
	#define z(x) tree[x].z
}tree[N*200];
int tlen=1,root=1;
inline long long max(long long a,long long b){
	return a>b?a:b;
}
inline int newdata(int l,int r){
	tlen++;
	l(tlen)=r(tlen)=b(tlen)=0;
	z(tlen)=(r-1)*1ll*d;
	return tlen;
}
inline int add(int ro,int l,int r,int L,int R,long long b);
inline void downdata(int a,int l,int r,int mid){
	if(!b(a))return;
	l(a)=add(l(a),l,mid,l,mid,b(a));
	r(a)=add(r(a),mid+1,r,mid+1,r,b(a));
	b(a)=0;
	return;
}
inline int add(int ro,int l,int r,int L,int R,long long b){
	if(r<L||l>R)return ro;
	if(!ro)ro=newdata(l,r);
	if(l>=L&&r<=R){
		b(ro)+=b;
		z(ro)+=b;
		return ro;
	}
	int mid=(l+r)>>1;
	downdata(ro,l,r,mid);
	l(ro)=add(l(ro),l,mid,L,R,b);
	r(ro)=add(r(ro),mid+1,r,L,R,b);
	z(ro)=max(z(l(ro)),z(r(ro)));
	return ro;
}
inline long long find(int ro,int l,int r,int L,int R){
	if(r<L||l>R)return -(1e18);
	if(!ro)ro=newdata(l,r);
	if(l>=L&&r<=R)return z(ro);
	int mid=(l+r)>>1;
	downdata(ro,l,r,mid);
	return max(find(l(ro),l,mid,L,R),find(r(ro),mid+1,r,L,R));
}
int n,m;
struct _NoDe{
	int x,y,z;
}a[N];
bool operator <(_NoDe a,_NoDe b){
	if(a.x!=b.x)return a.x<b.x;
	if(a.y!=b.y)return a.y<b.y;
	return a.z<b.z;
}
int mt(int l,int r){
	int ax=newdata(l,r);
	if(l==r)return ax;
	l(ax)=newdata(l,(l+r)/2);
	r(ax)=newdata((l+r)/2+1,r);
	return ax;
}
void solve(int w){
	cin>>n>>m>>k>>d;
	tlen=0;
//	root=mt(1,n);
	root=newdata(1,n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
//	if(w!=3)return;
//	if(d==9347600)return;
	sort(a+1,a+m+1);
	long long MAX=0,z;
	for(int i=1;i<=m;i++){
//		if(a[i].x>k){
//			if(a[i].x!=a[i-1].x){
//				root=add(root,1,n,max(a[i-1].x-k+1,1),a[i].x-k,-(long long)(1e16));
//			}
//		}
//		if(a[i].x!=1){
//			z=find(1,1,n,1,a[i].x-1)-(a[i].x-1)*1ll*d;
//			if(z>MAX){
//				if(a[i].x!=n)root=add(1,1,n,a[i].x+1,n,z-MAX);
//				MAX=z;
//			}
//		}
		root=add(root,1,n,a[i].x-k+1,a[i].x-a[i].y+1,a[i].z);
		z=find(1,1,n,a[i].x-k+1,a[i].x)-a[i].x*1ll*d;
		if(z>MAX){
			if(a[i].x+1!=n)root=add(1,1,n,a[i].x+2,n,z-MAX);
			MAX=z;
		}
	}
//	cout<<d<<endl;
//	cout<<MAX2<<endl<<k*1ll*d<<endl;
	printf("%lld\n",MAX);
//	exit(0);
//	mt(1,1,n);
	return;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	z(0)=-1e18;
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}