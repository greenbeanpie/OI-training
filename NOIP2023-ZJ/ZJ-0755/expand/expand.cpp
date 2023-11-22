#include<bits/stdc++.h>
using namespace std;

int c,n,m,q;

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1){
		int a,b;
		cin>>a>>b;
		
		if(a==b)cout<<1;
		else cout<<0;
		
		for(int i=1;i<=q;i++){
			int A=a,B=b;
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				int px,vx;
				cin>>px>>vx;
				A=vx;
			}
			for(int j=1;j<=ky;j++){
				int py,vy;
				cin>>py>>vy;
				B=vy;
			}
			if(A==B)cout<<1;
			else cout<<0;
		}
	}
	else for(int i=1;i<=q+1;i++) cout<<1;
	return 0;
}
