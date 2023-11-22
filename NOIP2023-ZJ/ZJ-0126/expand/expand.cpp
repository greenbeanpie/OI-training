#include<bits/stdc++.h>
#define ll long long
#define ord(i,l,r) for(int i=l;i<=r;i++)
#define dord(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=2e3+20;
int n,m,Q,A[N],B[N],a[N],b[N]; bool f[N][N];
bool solve(){
	if(a[1]==b[1]||a[n]==b[m]) return 0;
	if((a[1]<b[1])!=(a[n]<b[m])) return 0;
	bool fl=0;
	if(fl=(a[1]>b[1])){ ord(i,1,n) a[i]=-a[i]; ord(i,1,m) b[i]=-b[i]; }
	ord(i,0,n) ord(j,0,m) f[i][j]=0;
	f[1][1]=1;
	ord(i,1,n) ord(j,1,m) if((i+j)>2&&a[i]<b[j]) f[i][j]|=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
	if(fl){ ord(i,1,n) a[i]=-a[i]; ord(i,1,m) b[i]=-b[i]; }
//	ord(i,1,n) { ord(j,1,m) putchar('0'+f[i][j]); puts(""); }
	return f[n][m];
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int Yao,k1,k2,x,v;
	scanf("%d%d%d%d",&Yao,&n,&m,&Q);
	ord(i,1,n) scanf("%d",&A[i]),a[i]=A[i];
	ord(i,1,m) scanf("%d",&B[i]),b[i]=B[i];
	putchar('0'+solve());
	while(Q--){
		scanf("%d%d",&k1,&k2);
		ord(i,1,n) a[i]=A[i];
		ord(i,1,m) b[i]=B[i];
		ord(i,1,k1) scanf("%d%d",&x,&v),a[x]=v;
		ord(i,1,k2) scanf("%d%d",&x,&v),b[x]=v;
		putchar('0'+solve());
	}
	return 0;
}