#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch;int res;
	while((ch=getchar())<'0'||ch>'9');
	res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')
		res=(res<<3)+(res<<1)+ch-48;
	return res;
}
int c,n,m,q,k,x[100005],y[100005];
int kx,ky,ix[500005],iy[500005],tx[500005],ty[500005];
int ans[65];
int ask(int sx,int sy,int f)
{
	if(sy!=0&&(x[sx]-y[sy-1])*f>0) 
		if(ask(sx+1,sy,f)) return 1;
	for(k=sy;k<m;++k)
	{
		if((x[sx]-y[k])*f>0) 
		{
			if(ask(sx+1,k+1,f)) return 1;
		}	
		else break;
	}
	if(sx==n-1&&k==m) return 1;	
	return 0;
}
int main()
{
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=0;i<n;++i) x[i]=read();
	for(int i=0;i<m;++i) y[i]=read();
	ans[0]=ask(0,0,1)|ask(0,0,-1);
	for(int i=1;i<=q;++i)
	{
		kx=read(),ky=read();
		for(int j=0;j<kx;++j) ix[j]=read(),tx[j]=x[ix[j]],x[ix[j]]=read();
		for(int j=0;j<ky;++j) iy[j]=read(),ty[j]=y[iy[j]],y[iy[j]]=read();
 		ans[i]=ask(0,0,1)|ask(0,0,-1);
		for(int j=0;j<kx;++j) swap(x[ix[j]],tx[j]);
		for(int j=0;j<ky;++j) swap(y[iy[j]],ty[j]);
	}
	for(int i=0;i<=q;++i) cout<<ans[i];
	cout<<'\n';
	return 0;
}