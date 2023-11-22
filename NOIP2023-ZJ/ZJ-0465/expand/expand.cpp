#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,q;
int x[N],y[N];
int a[N],b[N];
void solve1(){
	int u=x[1],v=y[1];
	cout<<(x[1]!=y[1]);
	while(q--){
		x[1]=u,y[1]=v;
		int kx,ky;
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++){
			int px,vx;
			cin>>px>>vx;
			x[px]=vx;
		}
		for(int j=1;j<=ky;j++){
			int py,vy;
			cin>>py>>vy;
			y[py]=vy;
		}
		cout<<(x[1]!=y[1]);
	}	
}


int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) {
		cin>>x[i];
		a[i]=x[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>y[i];
		b[i]=y[i];
	}
	if(c==1){
		solve1();
		return 0;
	}
	if(c==2){
		if(n==1&&m==1) {
			solve1();
			return 0;
		}
		if(n==1){
			if(x[1]<min(y[1],y[2])||x[1]>max(y[1],y[2])) cout<<1;
			else cout<<0;
		}
		else if(m==1){
			if(y[1]<min(x[1],x[2])||y[1]>max(x[1],x[2])) cout<<1;
			else cout<<0;
		}
		else if(n==2&&m==2){
			if((x[1]-y[1])*(x[2]-y[2])>0) cout<<1;
			else cout<<0;
		}
		while(q--){
			for(int i=1;i<=n;i++) x[i]=a[i];
			for(int i=1;i<=m;i++) y[i]=b[i];
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				int px,vx;
				cin>>px>>vx;
				x[px]=vx;
			}
			for(int j=1;j<=ky;j++){
				int py,vy;
				cin>>py>>vy;
				y[py]=vy;
			}
			if(n==1){
				if(x[1]<min(y[1],y[2])||x[1]>max(y[1],y[2])) cout<<1;
				else cout<<0;
			}
			else if(m==1){
				if(y[1]<min(x[1],x[2])||y[1]>max(x[1],x[2])) cout<<1;
				else cout<<0;
			}
			else if(n==2&&m==2){
				if((x[1]-y[1])*(x[2]-y[2])>0) cout<<1;
				else cout<<0;
			}		
		}
	}		
	return 0;
}

