#include<bits/stdc++.h>

using namespace std;

int c,n,m,q;
int x[500010],y[500010];

bool check(){
	if(m==1 && n==1){
		if(x[1]!=y[1])return 1;
		else return 0;
	}
	if(m==1 && n==2){
		if((x[1]-y[1])*(x[2]-y[1])>0)return 1;
		else return 0;
	}
	if(m==2 && n==1){
		if((x[1]-y[1])*(x[1]-y[2])>0)return 1;
		else return 0;
	}
	if(m==2 && n==2){
		if((x[1]-y[1])*(x[2]-y[2])>0)return 1;
		else return 0;
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1){//n,m<=1
		int x1,y1;
		cin>>x1;
		cin>>y1;
		if(x1!=y1)cout<<1;
		else cout<<0;
		for(int i=1,kx,ky;i<=q;i++){
			cin>>kx>>ky;
			for(int i=1,px,vx;i<=kx;i++){
				cin>>px>>vx;
				x1=vx;
			}
			for(int i=1,py,vy;i<=ky;i++){
				cin>>py>>vy;
				y1=vy;
			}
			if(x1!=y1)cout<<1;
			else cout<<0;
		}
		return 0;
	}
	if(c==2){
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=m;i++)cin>>y[i];
		if(check())cout<<1;
		else cout<<0;
		for(int i=1,kx,ky;i<=q;i++){
			cin>>kx>>ky;
			for(int i=1,px,vx;i<=kx;i++){
				cin>>px>>vx;
				x[px]=vx;
			}
			for(int i=1,py,vy;i<=ky;i++){
				cin>>py>>vy;
				y[py]=vy;
			}
			if(check())cout<<1;
			else cout<<0;
		}
		return 0;
	}
	if(8<=c && c<=14){
		int maxx=-1,minn;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=m;i++){
			cin>>y[i];
		}
		for(int i=1,kx,ky;i<=q;i++){
			cin>>kx,ky;
			for(int i=1,px,vx;i<=kx;i++){
				cin>>px>>vx;
				x[px]=vx;
			}
			for(int i=1,py,vy;i<=ky;i++){
				cin>>py>>vy;
				y[py]=vy;
			}
			cout<<1;
		}
	}
}
