#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[301],b[301],a1[301],b1[301];
int kx,ky;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i],a1[i]=a[i];
	for(int i=1;i<=m;i++) cin>>b[i],b1[i]=b[i];
	if(c==1){
		if(a[1]==b[1]) cout<<'1';
		else cout<<'0';
		for(int i=1;i<=q;i++){
			cin>>kx>>ky;
			a1[1]=a[1];
			b1[1]=b[1];
			for(int j=1;j<=kx;j++){
				int px,v;
				cin>>px>>v;
				a1[px]=v;
			}
			for(int j=1;j<=ky;j++){
				int py,v;
				cin>>py>>v;
				b1[py]=v;
			}
			if(a1[1]==b1[1]) cout<<'1';
			else cout<<'0';
		}
	}
	else{
		if(a[1]==b[1]) cout<<'1';
		else cout<<'0';
		int flag=0;
		for(int i=1;i<=q;i++){
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				int px,v;
				cin>>px>>v;
			}
			for(int j=1;j<=ky;j++){
				int py,v;
				cin>>py>>v;
			}
			cout<<flag;
			flag=1-flag;
		}
	}
}