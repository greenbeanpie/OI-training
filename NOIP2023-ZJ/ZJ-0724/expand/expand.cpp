#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	int x[n+1],y[n+1];
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>y[i];
	bool lb=0;
	if (n==1&&m==1)
		if(x[1]!=y[1]) lb=1;
	bool a[q+1];
	memset(a,0,sizeof(a));
	int p=q;
	while(q>0){
		int xq[n+1],yq[n+1];
		for(int i=1;i<=n;i++) xq[i]=x[i];
		for(int i=1;i<=m;i++) yq[i]=y[i];
		int kx,ky,px,vx,py,vy;
		cin>>kx>>ky;
		if (kx>0)
		for(int i=1;i<=kx;i++) 
		{
			cin>>px>>vx;
			xq[px]=vx;
		}
		if (ky>0)
		for(int i=1;i<=ky;i++) 
		{
			cin>>py>>vy;
			xq[py]=vy;
		}
		if(n==1&&m==1)
			if(xq[1]!=yq[1]) 
				a[q]=1;
		
		q-=1;
	}
	cout<<lb;
	for(int i=p;i>0;i--) cout<<a[i];
	fclose(stdin);fclose(stdout);
	return 0;
}
