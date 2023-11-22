#include<iostream>
using namespace std;
const int N=5e5+10;
int x[N],y[N],x1[N],y1[N];
int c,n,m,q,kx,px,vx,ky,py,vy;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int j=1;j<=n;j++)
		cin>>y[j];
	if((x[1]-y[1])*(x[n]-y[m])>0) cout<<"1";
	else cout<<"0";
	for(int i=1;i<=q;i++){
		for(int i=1;i<=n;i++)
			x1[i]=x[i];
		for(int i=1;i<=m;i++)
			y1[i]=y[i];
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++){
			cin>>px>>vx;
			x1[px]=vx;
		}
		for(int i=1;i<=ky;i++){
			cin>>py>>vy;
			y1[py]=vy;
		}
		if((y1[m]-x1[n])*(y1[1]-x1[1])>0) cout<<"1";
		else cout<<"2";
	}
	return 0;
}
