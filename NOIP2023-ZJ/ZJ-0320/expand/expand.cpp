#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int tt,n,m,kn,km,t,aa[N],bb[N],a[N],b[N],x,y;

int solve(int *a,int *b,int n,int m){
	if(n==1&&m==1) return a[1]!=b[1];
	if(n==2&&m==2) return (a[1]-b[1])*(a[n]-b[m])>0;
	if((a[1]-b[1])*(a[n]-b[m])<=0) return 0;
	if(a[1]<b[1]) return solve(b,a,m,n);
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
//	printf("\n");
//	for(int i=1;i<=m;i++) printf("%d ",b[i]);
//	printf("\n");
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=m&&a[i]<b[j]) j++;
		if(j>m) return 0;
	}
	return 1;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>tt>>n>>m>>t;
//	if(tt<8||tt>14){
//		for(int i=0;i<=t;i++) printf("0");
//		exit(0);
//	}
	for(int i=1;i<=n;i++) scanf("%d",aa+i),a[i]=aa[i];
	for(int i=1;i<=m;i++) scanf("%d",bb+i),b[i]=bb[i];
	printf("%d",solve(a,b,n,m));
	while(t--){
		cin>>kn>>km;
		for(int i=1;i<=kn;i++) scanf("%d%d",&x,&y),a[x]=y;
		for(int i=1;i<=km;i++) scanf("%d%d",&x,&y),b[x]=y;
		printf("%d",solve(a,b,n,m));
		for(int i=1;i<=n;i++) a[i]=aa[i];
		for(int i=1;i<=m;i++) b[i]=bb[i];
	}
	cout<<"\n";
}
