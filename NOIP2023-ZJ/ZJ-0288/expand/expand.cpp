#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,kx,ky,gx[40001],gy[40001];
int px,py,vx,vy,nx[40001],ny[40001];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>gx[i];
	for(int i=1;i<=m;i++)cin>>gy[i];
	if(c==1){
		if(gx[1]!=gy[1]){
			cout<<"1";
		}else cout<<"0";
		while(q--){
			for(int i=1;i<=n;i++)nx[i]=gx[i];
			for(int i=1;i<=m;i++)ny[i]=gy[i];
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>px>>vx;
				nx[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				cin>>py>>vy;
				ny[py]=vy;
			}
			if(nx[1]!=ny[1]){
				cout<<"1";
			}else cout<<"0";
		}
	}
	if(c==2){
		if(gx[1]==gy[1]||gx[n]==gy[m]){
			cout<<"0";
		}else if((gx[1]>gy[1])^(gx[n]>gy[m])){
			cout<<"0";
		}else cout<<"1";
		while(q--){
			for(int i=1;i<=n;i++)nx[i]=gx[i];
			for(int i=1;i<=m;i++)ny[i]=gy[i];
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>px>>vx;
				nx[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				cin>>py>>vy;
				ny[py]=vy;
			}
			if(nx[1]==ny[1]||nx[n]==ny[m]){
				cout<<"0";
			}else if((nx[1]>ny[1])^(nx[n]>ny[m])){
				cout<<"0";
			}else cout<<"1";
		}
	}
	return 0;
}
