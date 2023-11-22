#include<bits/stdc++.h>
using namespace std;
const int MS=5e5+5;
long long c,q,n,m,a[MS],b[MS],ca[MS],cb[MS];
bool cmp(int a,int b,int type){
	if(type==0)return a<b;
	return a>b;
}
bool search(int x,int k,int type){
	if(x==n){
		if(k==m){
			return cmp(ca[x],cb[k],type);
		}
		for(int i=k+1;i<=m;i++)
			if(!cmp(ca[x],cb[i],type))return 0;
		return 1;
	}
	int ans=0;
	if(cmp(ca[x],cb[k],type))
		if(search(x+1,k,type))return 1;
	for(int i=k+1;i<=m;i++){
		if(!cmp(ca[x],cb[i],type))break;
		if(search(x+1,i,type))
			return 1;
	}
	return 0;
}
int cheak(){
	if(ca[1]==cb[1]||ca[n]==cb[m])return 0;
	if(ca[1]<cb[1]&&ca[n]>cb[m])return 0;
	if(ca[1]>cb[1]&&ca[n]<cb[m])return 0;
	if(ca[1]<cb[1])return search(1,1,0);
	return search(1,1,1);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ca[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		cb[i]=b[i];	
	}
	printf("%d",cheak());
	while(q--){
		long long kx,ty;
		scanf("%lld%lld",&kx,&ty);
		for(int i=1;i<=n;i++)ca[i]=a[i];
		for(int i=1;i<=m;i++)cb[i]=b[i];
		for(int i=1;i<=kx;i++){
			long long px,vx;
			scanf("%lld%lld",&px,&vx);
			ca[px]=vx;
		}
		for(int i=1;i<=ty;i++){
			long long py,vy;
			scanf("%lld%lld",&py,&vy);
			cb[py]=vy;
		}
//		printf("\n");
//		for(int i=1;i<=n;i++)printf("%d ",ca[i]);
//		printf("\n");
//		for(int i=1;i<=m;i++)printf("%d ",cb[i]);
//		printf("\n");
		printf("%d",cheak());
	}
}
//伟大的CCF保佑我rp++ 
