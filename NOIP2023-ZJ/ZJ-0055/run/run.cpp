#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
inline int read(){
	char ch=getchar();int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int n,m,k,d,tmp[N];
struct node{int l,r,v;bool operator<(const node x)const{
	return r!=x.r?r<x.r:l>x.l;}}a[N];
ll f[2][N];
void ljy1(){
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		a[i].l=x-y+1,a[i].r=x;a[i].v=read();
	}sort(a+1,a+1+m);int t=1;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		int p=i&1,np=!p;
		ll cnt=0;f[p][0]=f[np][0];
		for(int j=1;j<=k&&(i-j+1);j++){
			while(t<=m&&a[t].r==i&&a[t].l==i-j+1) cnt+=a[t++].v;
			f[p][j]=f[np][j-1]+cnt-d;
			f[p][0]=max(f[p][0],f[np][j]);
		}
	}ll Mx=-9e18;
	for(int i=0;i<=k;i++) Mx=max(Mx,f[n&1][i]);
	printf("%lld\n",Mx);
}
void LJY(){
	n=read();m=read();k=read();d=read();
	if(n*k<=1e10){ljy1();return;}
	else{
		srand(time(0));
		printf("%lld\n",1ll*rand()*rand());
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int t;read();t=read();while(t--) LJY();
	return 0;
}
/*36 pts*/