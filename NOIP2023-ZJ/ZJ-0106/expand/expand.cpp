#include<bits/stdc++.h>
using namespace std;
int a[500100],b[500100];
int a1[500100],b1[500100];
int stsn[500010][20],stdx[500010][20];
int db[500100];
int lgxx[500100];
int c,n,m,q;
void jst_mx(int* b,int (&st)[500010][20],int m){
	for(int i=0;i<=m+1;i++)
	stsn[i][0]=b[i];
	for(int i=1;i<=lgxx[m+2];i++)
	for(int j=0;j<=m+1;j++)
		st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
void jst_mn(int* b,int (&st)[500010][20],int m){
	for(int i=0;i<=m+1;i++)
	stsn[i][0]=b[i];
	for(int i=1;i<=lgxx[m+2];i++)
		for(int j=0;j<=m+1;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	
	
}
int rfc_ALLLOW(int (&st)[500010][20],int l,int x,int m){
	for(int i=lgxx[m+1];i>=0;i--){
		if(l+(1<<i)<=m+1&&st[l][i]<x)l+=(1<<i);
	}
	return l;
}
int rfc_NTALLLOW(int (&st)[500010][20],int l,int x,int m){
	for(int i=lgxx[m+1];i>=0;i--){
		if(l+(1<<i)<=m+1&&st[l][i]>=x)l+=(1<<i);
	}
	return l;
} 
bool slove(int* a,int *b,int n,int m){
	b[0]=-1e9;
	b[m+1]=1e9+7;
	jst_mx(b,stsn,m);
	for(int i=0;i<=m+1;i++){
		db[m-i+1]=b[i];
	}
	jst_mn(db,stdx,m);
	int d=0;
	for(int i=1;i<=n;i++){
		if(b[d]<a[i]){
			d=rfc_ALLLOW(stsn,d+1,a[i],m)-1;
		}
		else {
			d=m+1-rfc_NTALLLOW(stdx,m+1-d,a[i],m);
		}
	}
	return (d>=m);
	
}
void sl(int* a,int *b,int n,int m){
	bool t=slove(a,b,n,m)||slove(b,a,m,n);
	if(t)putchar('1');
	else putchar('0');
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	lgxx[1]=0;
	for(int i=2;i<=500010;i++)
	lgxx[i]=1+lgxx[i/2];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%d",&b[i]);
	sl(a,b,n,m);
	while(q--){
		int qx,qy;
		scanf("%d%d",&qx,&qy);
		for(int i=1;i<=n;i++)
		a1[i]=a[i];
		for(int i=1;i<=m;i++)
		b1[i]=b[i];
		for(int i=1;i<=qx;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a1[x]=y;
		}
		for(int i=1;i<=qy;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			b1[x]=y;
		}
		sl(a1,b1,n,m);
	}
	return 0;
}