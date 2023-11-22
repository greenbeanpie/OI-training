#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
int P[N],Q[N];
int ans[62];
int c,n,m,q;
bool uplif(){
	for(int i=1;i<min(n,m);i++) if((a[i]-b[i])>=0) return 0;
	return 1;
}
bool downlif(){
	for(int i=1;i<min(n,m);i++) if((a[i]-b[i])<=0) return 0;
	return 1;
}
bool check(){
	if(c==1){
		return 1;
	}
	if(a[1]==b[1]) return 0;
	if(a[1]>b[1]&&a[n]<b[m]) return 0;
	if(a[1]<b[1]&&a[n]>b[m]) return 0;
	else{
		if(uplif()) return 1;
		if(downlif()) return 1;
		if(a[1]>b[1]){
			int i=1,j=1;
			while(i<n&&j<m){
				while(j<m&&a[i]>b[j]) j++;
				if(j==m&&a[i]>b[j]) return 1;
				i++;
				if(a[i]<=b[j]||i==n&&j<m) return 0;
			}
		}
		else{
			int i=1,j=1;
			while(i<n&&j<m){
				while(j<m&&a[i]<b[j]) j++;
				if(j==m&&a[i]<b[j]) return 1;
				i++;
				if(a[i]>=b[j]||i==n&&j<m) return 0;	
		}
	}
}
	return 0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&P[i]);
	for(int i=1;i<=n;i++) scanf("%d",&Q[i]);
	for(int i=1;i<=n;i++) a[i]=P[i],b[i]=Q[i];
	ans[1]=check();
	int cnt=1;
	while(q--){
		for(int i=1;i<=n;i++) a[i]=P[i],b[i]=Q[i];
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++){
			int px,vx;
			scanf("%d%d",&px,&vx);
			a[px]=vx;
		}
		for(int i=1;i<=ky;i++){
			int py,vy;
			scanf("%d%d",&py,&vy);
			b[py]=vy;
		}
		ans[++cnt]=check();
		
	}
	for(int i=1;i<=cnt;i++) cout<<ans[i];
	puts("");
	return 0;
}