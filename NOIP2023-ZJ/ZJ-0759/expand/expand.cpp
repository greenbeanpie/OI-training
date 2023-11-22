#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=5e5+3;

int c,n,m,q;
int x[N],y[N];
int xt[N],yt[N];
int maxx,minx=inf,maxy,miny=inf;
int maxxpos,minxpos,maxypos,minypos;
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; ++i) {
		cin>>x[i];
		if(!(8<=c&&c<=14)) {
			if(maxx<x[i]) {
				maxx=x[i];
				maxxpos=i;
			}
			if(minx>x[i]) {
				minx=x[i];
				minxpos=i;
			}
		}

		xt[i]=x[i];
	}
	for(int i=1; i<=m; ++i) {
		cin>>y[i];
		if(!(8<=c&&c<=14)) {
			if(maxy<y[i]) {
				maxy=y[i];
				maxypos=i;
			}
			if(miny>y[i]) {
				miny=y[i];
				minypos=i;
			}
		}
		yt[i]=y[i];
	}
	if(c==1) {
		cout<<"1";
		for(int i=1; i<=q; ++i) {
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1; j<=kx; ++j) {
				int p,v;
				cin>>p>>v;
				xt[p]=v;
			}
			for(int j=1; j<=ky; ++j) {
				int p,v;
				cin>>p>>v;
				yt[p]=v;
			}
			cout<<"1";
			for(int j=1; j<=n; ++j) {
				if(xt[j]!=x[j])xt[j]=x[j];
			}
			for(int j=1; j<=m; ++j) {
				if(yt[j]!=y[j])yt[j]=y[j];
			}
		}
	} else if(c==2) {
		if((x[1]-y[1])*(x[2]-y[2])>0||(x[1]==y[1])||(x[2]==y[2])){
			cout<<"1";
		}else{
			cout<<"0";
		}
		for(int i=1; i<=q; ++i) {
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1; j<=kx; ++j) {
				int p,v;
				cin>>p>>v;
				xt[p]=v;
			}
			for(int j=1; j<=ky; ++j) {
				int p,v;
				cin>>p>>v;
				yt[p]=v;
			}
			if((xt[1]-yt[1])*(xt[2]-yt[2])>0||(xt[1]==yt[1])||(xt[2]==yt[2])){
				cout<<"1";
			}else{
				cout<<"0";
			}
			//init
			for(int j=1; j<=n; ++j) {
				if(xt[j]!=x[j])xt[j]=x[j];
			}
			for(int j=1; j<=m; ++j) {
				if(yt[j]!=y[j])yt[j]=y[j];
			}
		}
	} else {
		int flag=-1;
		if(x[1]>y[1])flag=1;
		else flag=0;
		cout<<flag;
		for(int i=1; i<=q; ++i) {
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1; j<=kx; ++j) {
				int p,v;
				cin>>p>>v;
				xt[p]=v;
			}
			for(int j=1; j<=ky; ++j) {
				int p,v;
				cin>>p>>v;
				yt[p]=v;
			}
			//init()
			cout<<flag;
			for(int j=1; j<=n; ++j) {
				if(xt[j]!=x[j])xt[j]=x[j];
			}
			for(int j=1; j<=m; ++j) {
				if(yt[j]!=y[j])yt[j]=y[j];
			}
		}
	}

	return 0;
}
