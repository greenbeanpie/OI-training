#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
int c,n,m,q;
long long x[maxn],y[maxn];
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	long long p,v;
	long long maxx=0,minx=1e9,maxy=0,miny=1e9;
	for(int i=1; i<=n; ++i) cin>>x[i],maxx=max(maxx,x[i]),minx=min(minx,x[i]);
	for(int j=1; j<=m; ++j) cin>>y[j],maxy=max(maxy,y[j]),miny=min(miny,y[j]);
	if(x[1]==y[1]) cout<<0;
	if(x[1]<y[1]) {
		if(maxx>maxy||minx>miny) cout<<0;
		else cout<<1;
	}
	if(x[1]>y[1]) {
		if(maxx<maxy||minx<miny) cout<<0;
		else cout<<1;
	}
	while(q--) {
		cin>>p>>v;
		maxx=max(maxx,min(x[p],v));
		minx=min(minx,max(x[p],v));
		cin>>p>>v;
		maxy=max(maxy,min(y[p],v));
		miny=min(miny,max(y[p],v));
		if(x[1]==y[1]) cout<<0;
		if(x[1]<y[1]) {
			if(maxx>maxy||minx>miny) cout<<0;
			else cout<<1;
		}
		if(x[1]>y[1]) {
			if(maxx<maxy||minx<miny) cout<<0;
			else cout<<1;
		}
	}
	return 0;
}
