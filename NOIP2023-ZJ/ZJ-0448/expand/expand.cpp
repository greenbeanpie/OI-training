#include<bits/stdc++.h>
using namespace std;
int c,m,n,q;
int x[500050],y[500050];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>m>>n>>q;
	if(c==1){
		int xx,yy;
		cin>>xx>>yy;
		if(xx!=yy) cout<<1<<endl;
		else cout<<0<<endl;
		while(q--){
			int kx,ky,p,v;
			cin>>kx>>ky;
			while(kx--){
				cin>>p>>v;
				xx=v;
			}
			while(ky--){
				cin>>p>>v;
				yy=v;
			}
			if(xx!=yy) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
}