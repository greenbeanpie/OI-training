#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[50050],y[50050],qq[50050];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}
	for (int j=1;j<=m;j++){
		cin>>y[j];
	}
	if (c==1){
		if(x[1]>y[1]){
			qq[1]=1;
		}
		for (int i=1;i<=q;i++){
			int kx,ky;
			cin>>kx>>ky;
			for (int j=1;j<=kx;j++){
				int px,vx;
				cin>>px>>vx;
				x[px]=vx;
			}
			for (int k=1;k<=ky;k++){
				int py,vy;
				cin>>py>>vy;
				y[py]=vy;
			}
			if(x[1]>y[1]){
				qq[i+1]=1;
			}
		}
		for (int i=1;i<=q+1;i++){
			cout<<qq[i];
		}
	}//else if(c>=8 and c<=14){
	//	for (int i=1)
	//}
}