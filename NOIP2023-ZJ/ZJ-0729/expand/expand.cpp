#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int x[N],y[N];
const int INF=1e9;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q,kx,ky,p,v;
	cin>>c>>n>>m>>q;
	if(c==1){
		cin>>x[1]>>y[1];
		if(x[1]!=y[1]) cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++){
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				cin>>p>>v;
				y[p]=v;
			}
			if(x[1]!=y[1]) cout<<1;
			else cout<<0;
		}
	}
	if(c==2){
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=m;i++) cin>>y[i];
		if((x[1]-y[1])*(x[n]-y[m])>0) cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++){
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				cin>>p>>v;
				y[p]=v;
			}
			if((x[1]-y[1])*(x[n]-y[m])>0) cout<<1;
			else cout<<0;
		}
	}
	if(c>=3&&c<=4){
		int lx=1,ly=1,maxx=0,maxy=0,minx=INF,miny=INF;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			maxx=max(x[i],maxx);
			minx=min(x[i],minx);
		}
		for(int i=1;i<=m;i++){
			cin>>y[i];
			maxy=max(y[i],maxy);
			miny=min(y[i],miny);
		}
		if((x[1]-y[1])*(x[n]-y[m])<=0){
			cout<<0;
		}else{
			if(x[1]>y[1]){
				if(maxx<=maxy||minx<=miny){
					cout<<0;
				}else{
					cout<<1;
				}
			}else{
				if(maxx>=maxy||minx>=miny){
					cout<<0;
				}else{
					cout<<1;
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				cin>>p>>v;
				y[p]=v;
			}
			if((x[1]-y[1])*(x[n]-y[m])<=0){
			cout<<0;
		}else{
			if(x[1]>y[1]){
				if(maxx<=maxy||minx>=miny){
					cout<<0;
				}else{
					cout<<1;
				}
			}else{
				if(maxx>=maxy||minx<=miny){
					cout<<0;
				}else{
					cout<<1;
				}
			}
		}
		}
	}
	return 0;
}

