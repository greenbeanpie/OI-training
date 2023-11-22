#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int ans[100];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	int a,b;
	cin>>a>>b;
	ans[1]=(int)(a!=b);
	for(int i=1;i<=q;i++){
		int kx,ky;
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++){
			int px,vx;
			cin>>px>>vx;
			a=vx;
		}
		for(int j=1;j<=ky;j++){
			int py,vy;
			cin>>py>>vy;
			b=vy;
		}
		ans[i+1]=(int)(a!=b);
	}
	for(int i=1;i<=q+1;i++) cout<<ans[i];
	return 0;
}

