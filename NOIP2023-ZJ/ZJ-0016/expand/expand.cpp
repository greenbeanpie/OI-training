#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=5e5+5;
int sid,T,n,m,x[N],y[N];
namespace A{
	int dp[2005][2005];
	void solve(){
		if(x[1]==y[1]){putchar('0');return;}
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(x[i]!=y[j]&&((x[i]>y[j])^(x[1]<y[1]))){
					dp[i][j]|=dp[i-1][j-1];
					dp[i][j]|=dp[i][j-1];
					dp[i][j]|=dp[i-1][j];
				}
		putchar('0'+dp[n][m]);
	}
}
namespace B{
	int a[N],b[N],minx[N],miny[N],maxx[N],maxy[N];
	bool solve(int n,int m){
		minx[1]=miny[1]=maxx[1]=maxy[1]=1;
		for(int i=2;i<=n;i++){
			maxx[i]=maxx[i-1];minx[i]=minx[i-1];
			if(a[i]>a[maxx[i]])maxx[i]=i;
			if(a[i]<a[minx[i]])minx[i]=i;
		}
		for(int i=2;i<=m;i++){
			maxy[i]=maxy[i-1];miny[i]=miny[i-1];
			if(b[i]>b[maxy[i]])maxy[i]=i;
			if(b[i]<b[miny[i]])miny[i]=i;
		}
		int nown=n,nowm=m;
		while(nown){
			if(b[miny[nowm]]<=a[nown])return false;
			if(a[maxx[nown]]>=b[nowm])return false;
			if(b[miny[nowm]]<=a[minx[nown-1]])nowm=maxy[miny[nowm]];
			else nown=minx[nown-1];
		}
		return true;
	}
	void solve(){
		if(x[1]==y[1]){putchar('0');return;}
		bool tag=(x[1]>y[1]),ans=1;
		if(tag){
			int t=max(n,m);swap(n,m);
			for(int i=1;i<=t;i++)swap(x[i],y[i]);
		}
		if(x[n]>=y[m])ans=0;
		else{
			int mnx=1,mxy=1;
			for(int i=1;i<=n;i++)if(x[i]<x[mnx])mnx=i;
			for(int i=1;i<=m;i++)if(y[i]>y[mxy])mxy=i;
			for(int i=1;i<=mnx;i++)a[i]=x[i];
			for(int i=1;i<=mxy;i++)b[i]=y[i];
			ans&=solve(mnx,mxy);
			for(int i=n;i>=mnx;i--)a[n-i+1]=x[i];
			for(int i=m;i>=mxy;i--)b[m-i+1]=y[i];
			ans&=solve(n-mnx+1,m-mxy+1);
		}
		putchar('0'+ans);
		if(tag){
			int t=max(n,m);swap(n,m);
			for(int i=1;i<=t;i++)swap(x[i],y[i]);
		}
	}
}
void solve(){
	if(sid<=7)A::solve();
	else B::solve();
}
int kx,ky,px[N],py[N],vx[N],vy[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	sid=read();n=read();m=read();T=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=m;i++)y[i]=read();
	solve();
	while(T--){
		kx=read();ky=read();
		for(int i=1;i<=kx;i++)
			px[i]=read(),vx[i]=x[px[i]],x[px[i]]=read();
		for(int i=1;i<=ky;i++)
			py[i]=read(),vy[i]=y[py[i]],y[py[i]]=read();
		solve();
		for(int i=1;i<=kx;i++)x[px[i]]=vx[i];
		for(int i=1;i<=ky;i++)y[py[i]]=vy[i];
	}
	return 0;
}