#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e3+5;
int n,m,q,A[N],B[N],p,x,a[N],b[N];
bool f[M][M];
void calc(){
	if(!(n<=2e3&&m<=2e3)){
		int cur=1;
		for(int i=1;i<=m;i++){
			if(a[cur]>=b[i]){
				while(cur>=1&&a[cur]>=b[i]) cur--;
				if(!cur){putchar('0');return ;}
			}
			while(cur<=n&&a[cur]<b[i]) cur++;
		}
		putchar((cur>n)+'0');
		return ;
	}
	int ans=0;
	if(a[1]>b[1]){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) f[i][j]=0;
		f[1][1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) if(f[i][j]){
				if(j<m&&a[i]>b[j+1]) f[i][j+1]=1;
				if(i<n&&a[i+1]>b[j]) f[i+1][j]=1;
				if(i<n&&j<m&&a[i+1]>b[j+1]) f[i+1][j+1]=1;
			}
		ans|=f[n][m];
	}
	if(a[1]<b[1]){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) f[i][j]=0;
		f[1][1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) if(f[i][j]){
				if(j<m&&a[i]<b[j+1]) f[i][j+1]=1;
				if(i<n&&a[i+1]<b[j]) f[i+1][j]=1;
				if(i<n&&j<m&&a[i+1]<b[j+1]) f[i+1][j+1]=1;
			}
		ans|=f[n][m];
	}
	putchar(ans+'0');
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=m;i++) scanf("%d",&B[i]);
	copy(A+1,A+1+n,a+1),copy(B+1,B+1+m,b+1);
	calc();
	while(q--){
		int kx,ky,p,v;
		scanf("%d%d",&kx,&ky);
		copy(A+1,A+1+n,a+1),copy(B+1,B+1+m,b+1);
		for(int i=1;i<=kx;i++)
			scanf("%d%d",&p,&v),a[p]=v;
		for(int i=1;i<=ky;i++)
			scanf("%d%d",&p,&v),b[p]=v;
		calc();
	}
	puts("");
	return 0;
}
