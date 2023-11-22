//expand
#include <bits/stdc++.h>
#define Max 500010
#define re register
using namespace std;
int x[Max],y[Max];
int c,n,m,q;
int f=1;
queue<int> ps1,ps2,og1,og2;
int maxx=-1,maxy=-1,ogxx=0,ogxy=0;
int minx=1e9+10,miny=1e9+10,ognx=0,ogny=0;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

inline void solve(){
	if((maxx-maxy)*(minx-miny)<=0||(x[1]-y[1])*(x[n]-y[m])<=0) cout<<0;
	else cout<<1;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(re int i=1;i<=n;i++) {
		x[i]=read();
		if(x[i]>maxx) maxx=x[i];
		if(x[i]<minx) minx=x[i];
	}
	for(re int i=1;i<=m;i++) {
		y[i]=read();
		if(y[i]>maxy) maxy=y[i];
		if(y[i]<miny) miny=y[i];
	}
	solve();
	while(q--){
		int kx=read(),ky=read();
		ogxx=maxx,ogxy=maxy;
		ognx=minx,ogny=miny;
		while(kx--) {
			int pos=read(),inf=read();
			ps1.push(pos);og1.push(x[pos]);
			x[pos]=inf;
			if(inf>maxx) maxx=inf;
			if(inf<minx) minx=inf;
		}
		while(ky--) {
			int pos=read(),inf=read();
			ps2.push(pos);og2.push(y[pos]);
			y[pos]=inf;
			if(inf>maxy) maxy=inf;
			if(inf<miny) miny=inf;
		}
		solve();
		while(!ps1.empty()){
			int pos=ps1.front(),inf=og1.front();
			ps1.pop(),og1.pop();
			x[pos]=inf;
		}
		while(!ps1.empty()){
			int pos=ps2.front(),inf=og2.front();
			ps2.pop(),og2.pop();
			y[pos]=inf;
		}
		maxx=ogxx,maxy=ogxy;
		minx=ognx,miny=ogny;
	}
	return 0;
}
