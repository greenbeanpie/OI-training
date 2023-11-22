#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x[500005],y[500005],a[500005],b[500005];
int px[500005],py[500005];
struct Seg{
	int mx[2000005],mi[2000005];
	void modify(int p,int l,int r,int x,int v){
		if(l==r){
			mi[p]=mx[p]=v;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)modify(p<<1,l,mid,x,v);
		else modify(p<<1|1,mid+1,r,x,v);
		mx[p]=max(mx[p<<1],mx[p<<1|1]);
		mi[p]=min(mi[p<<1],mi[p<<1|1]);
	}
}tx,ty;
int solve(){
	int f=0,i=1,j=1;
	if(tx.mi[1]>ty.mi[1])f=1;
	else if(tx.mi[1]<ty.mi[1]) f=-1;
	else return 0;
	if(tx.mx[1]>ty.mx[1]){
		if(f==0)f=1;
		if(f==-1)return 0;
	}
	if(tx.mx[1]<ty.mx[1]){
		if(f==0)f=-1;
		if(f==1)return 0;
	}
	if(tx.mx[1]==ty.mx[1])return 0;
	if(x[1]>y[1]){
		if(f==-1)return 0;
		f=1;
	}
	if(x[1]<y[1]){
		if(f==1)return 0;
		f=-1;
	}
	if(x[n]>y[m]){
		if(f==-1)return 0;
		f=1;
	}
	if(x[n]<y[m]){
		if(f==1)return 0;
		f=-1;
	}
	if(x[1]==y[1]||x[n]==y[m])return 0;
	if(f==0)return 0;
	while(i<n&&j<m){
		if(f==1){
			if(x[i]>y[j+1])j++;
			else if(x[i+1]>y[j])i++;
			else if(x[i+1]>y[j+1])i++,j++;
			else return 0;
		}
		else{
			if(x[i]<y[j+1])j++;
			else if(x[i+1]<y[j])i++;
			else if(x[i+1]<y[j+1])i++,j++;
			else return 0;
		}
	}
	if(i!=n){
		while(i<=n){
			if(f==1&&x[i]<=y[m])return 0;
			if(f==-1&&x[i]>=y[m])return 0;
			i++;
		}
	}
	if(j!=m){
		while(j<=m){
			if(f==1&&x[n]<=y[j])return 0;
			if(f==-1&&x[n]>=y[j])return 0;
			j++;
		}
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i,j;
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(i=1;i<=n;i++)scanf("%d",&x[i]),tx.modify(1,1,n,i,x[i]),a[i]=x[i];
	for(i=1;i<=m;i++)scanf("%d",&y[i]),ty.modify(1,1,m,i,y[i]),b[i]=y[i];
	printf("%d",solve());
	for(i=1;i<=q;i++){
		int kx,ky,p,v;
		scanf("%d%d",&kx,&ky);
		for(j=1;j<=kx;j++){
			scanf("%d%d",&px[j],&v);
			x[px[j]]=v;
			tx.modify(1,1,n,px[j],v);
		}
		for(j=1;j<=ky;j++){
			scanf("%d%d",&py[j],&v);
			y[py[j]]=v;
			ty.modify(1,1,m,py[j],v);
		}
//		puts("!!");
//		for(j=1;j<=n;j++)printf("%d ",x[j]);
//		puts("");
//		for(j=1;j<=m;j++)printf("%d ",y[j]);
		printf("%d",solve());
		for(j=1;j<=kx;j++){
			x[px[j]]=a[px[j]];
			tx.modify(1,1,n,px[j],a[px[j]]);
		}
		for(j=1;j<=ky;j++){
			y[py[j]]=b[py[j]];
			ty.modify(1,1,m,py[j],b[py[j]]);
		}
	}
	return 0;
}