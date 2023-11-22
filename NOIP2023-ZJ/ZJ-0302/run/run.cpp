#include<bits/stdc++.h>
#define N1 1005
#define N2 100005
#define ll long long
#define inf 1000000000000000009
using namespace std;
int read(){
	int cnt=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while ('0'<=ch&&ch<='9') cnt=cnt*10+ch-'0',ch=getchar();
	return cnt;
}
ll readll(){
	ll cnt=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while ('0'<=ch&&ch<='9') cnt=cnt*10+ch-'0',ch=getchar();
	return cnt;
}
struct node{
	int x,y,v;
}a[N2];
bool cmp(node x,node y){
	return x.x<y.x;
}
int n,m,k,d;
ll a1[N1][N1],f1[N1][N1];
void point36(){
	memset(a1,0,sizeof(a1));
	memset(f1,0,sizeof(f1));
	n=read(),m=read(),k=read(),d=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		ll v=readll();
		a1[x][y]+=v;
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<=min(i,k);j++)
			f1[i][j]=-inf;
	f1[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=min(i,k);j++)
			a1[i][j]+=a1[i][j-1],f1[i][j]=max(f1[i][j],f1[i-1][j-1]+a1[i][j]-d),
			f1[i][0]=max(f1[i][0],f1[i-1][j-1]);
		if (i>k) f1[i][0]=max(f1[i][0],f1[i-1][k]);
	}
	ll ans=0;
	for (int i=0;i<=min(n,k);i++) ans=max(ans,f1[n][i]);
	printf("%lld\n",ans);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int opt=read(),T=read();
	while (T--) point36();
	return 0;
}
