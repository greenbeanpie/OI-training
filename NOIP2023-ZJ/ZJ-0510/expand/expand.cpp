#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int C,n,m,q;
int A[N],B[N],a[N],b[N];
int st[N],top;
bool isc;
int o;
inline bool sol(){
	if(a[1]==b[1]||a[n]==b[m]){
		return 0;
	}
	if(a[1]>b[1]&&a[n]<b[m]){
		return 0;
	}
	if(a[1]<b[1]&&a[n]>b[m]){
		return 0;
	}
	top=0;
	if(a[1]>b[1]){
		int j=1;
		for(int i=1;i<=n;i++){
			while(j<=m&&a[i]>b[j]) ++j;
			while(j>1&&a[i]<=b[j-1]) --j;
			if(j<=1) return 0;
		}      
		if(j>m) return 1;
	}
	if(a[1]<b[1]){
		int j=1;
		for(int i=1;i<=m;i++){
			while(j<=n&&b[i]>a[j]) ++j;
			while(j>1&&b[i]<=a[j-1]) --j;
			if(j<=1) return 0;
		}
		if(j>n) return 1;
	}
	return 0;
//	printf("1");
}
/*
1101100011110101110101111111111111111110011111111101101100000

1101100011110101110101111111111111111110011111111101101100000

1121122011112121110101111111111111111112211111111121121122022
1111111011111111110101111111111111111111111111111111111111011


*/
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);

//	freopen("expand4.in","r",stdin);
//	freopen("my.out","w",stdout);
	
	scanf("%d%d%d%d",&C,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),a[i]=A[i];
	for(int i=1;i<=m;i++) scanf("%d",&B[i]),b[i]=B[i];
	printf("%d",sol());
	for(o=1;o<=q;o++){
		for(int i=1;i<=n;i++) a[i]=A[i];
		for(int i=1;i<=m;i++) b[i]=B[i];
		int kx,ky,x,y;
		scanf("%d%d",&kx,&ky);
		while(kx--){
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		while(ky--){
			scanf("%d%d",&x,&y);
			b[x]=y;
		}
		printf("%d",sol());
		if(o==6){
			
//		puts("---");
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
//		for(int i=1;i<=m;i++)printf("%d ",b[i]);puts("");
//		puts("---");
		}
	}
	return 0;
}