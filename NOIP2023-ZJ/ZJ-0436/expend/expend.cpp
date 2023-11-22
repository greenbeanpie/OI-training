#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,q;
int kx,ky;
int x[N],y[N],xd[N],yd[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	for(int i=1;i<=m;i++)
	cin>>y[i];
	if(x[1]-y[1]>0&&x[n]-y[m]>0)
	cout<<1<<endl;
	if(x[1]-y[1]<0&&x[n]-y[m]<0)
	cout<<1<<endl;
	if(x[1]-y[1]<=0&&x[n]-y[m]>=0)
	cout<<0<<endl;
	if(x[1]-y[1]>=0&&x[n]-y[m]<=0)
	cout<<0<<endl;

	while(q--){
		cin>>kx>>ky;
		int a,b;
		for(int i=1;i<=n;i++)
		xd[i]=x[i];
		for(int i=1;i<=kx;i++)
		{
			cin>>a>>b;
			xd[a]=b;
		}
			for(int i=1;i<=n;i++)
		yd[i]=y[i];
		for(int i=1;i<=ky;i++)
		{
			cin>>a>>b;
			yd[a]=b;
		}
		if(xd[1]-yd[1]>=0&&xd[n]-yd[m]<=0)cout<<0<<endl;
		if(xd[1]-yd[1]>0&&xd[n]-yd[m]>0)cout<<1<<endl;
	if(xd[1]-yd[1]<0&&xd[n]-yd[m]<0)cout<<1<<endl;
	if(xd[1]-yd[1]<=0&&xd[n]-yd[m]>=0)cout<<0<<endl;
	
	}
}
