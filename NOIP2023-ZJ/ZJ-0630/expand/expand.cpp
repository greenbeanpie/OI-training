#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x[500005],y[500005],xx[500005],yy[500005],kx,ky;
string ans;
bool getans(){
	int u=1,v=1;
	if(x[1]==y[1]||x[n]==y[m])return false;
	if((x[1]>y[1]&&x[n]<y[m])||(x[1]<y[1]&&x[n]>y[m]))return false;
	return true;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>xx[i];x[i]=xx[i];
	}
	for(int i=1;i<=m;i++){
		cin>>yy[i];y[i]=yy[i];
	}
	ans+=char(int(getans())+'0');
	while(q--){
		cin>>kx>>ky;
		int px,vx,py,vy;
		for(int i=1;i<=n;i++){
			x[i]=xx[i];
		}
		for(int i=1;i<=m;i++)y[i]=yy[i];
		for(int i=1;i<=kx;i++){
			cin>>px>>vx;
			x[px]=vx;
		}
		for(int i=1;i<=ky;i++){
			cin>>py>>vy;
			y[py]=vy;
		}
		//cout<<x[1]<<' '<<y[1]<<' '<<x[n]<<' '<<y[m]<<endl;
		ans+=char(int(getans())+'0');
	}cout<<ans;
}