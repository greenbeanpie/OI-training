#include<bits/stdc++.h>
using namespace std;
#define file(s) (freopen(#s".in","r",stdin),freopen(#s".out","w",stdout))
#define ll long long
#define il inline
#define ret return
#define cst const
#define gc getchar
#define pc putchar
il ll rd()
{
	ll res=0;int lab=1;char ch=gc();
	while((ch<'0'||ch>'9')&&(ch^EOF))lab^=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=res*10+(ch&15),ch=gc();
	ret lab?res:-res;
}
il void prt(ll x,char tail='\n')
{
	static int s[71];int t=0;
	if(x<0)pc('-'),x=-x;
	do{s[++t]=x%10;x/=10;}while(x);
	while(t)pc(s[t--]|48);
	if(tail)pc(tail);
}
namespace Faust
{
	int n,m,q,x[500005],y[500005],xx[500005],yy[500005];
	int px[500005],vx[500005],py[500005],vy[500005],kx,ky;
	il void cpy()
	{
		for(int i=1;i<=n;++i)xx[i]=x[i];
		for(int i=1;i<=m;++i)yy[i]=y[i];
	}
	namespace bf1
	{
		int q[21];
		il int rmin(int l,int r)
		{
			if(l>r)ret 2e9;
			int res=yy[l];
			for(int i=l+1;i<=r;++i)res=min(res,yy[i]);
			ret res;
		}
		il int gg(int s=1,int p=1)
		{
			if(p==1)
			{
				if(xx[1]>yy[1])
				{
					for(int i=1;i<=n;++i)xx[i]=-xx[i];
					for(int i=1;i<=m;++i)yy[i]=-yy[i];
				}
				if(xx[n]>=yy[m])ret 0;
			}
			if(xx[p]>=yy[s])ret 0;
			q[p]=s;
			if(p==n)
			{
				q[p]=m;
				for(int i=1;i<n;++i)if(rmin(q[i]+1,q[i+1]-1)<=min(xx[i],xx[i+1]))ret 0;
				//for(int i=1;i<=n;++i)cerr<<xx[i]<<" \n"[i==n];
				//for(int i=1;i<=m;++i)cerr<<yy[i]<<" \n"[i==m];
				//for(int i=1;i<=n;++i)cerr<<q[i]<<" \n"[i==n];
				ret 1;
			}
			for(int i=s;i<=n;++i)if(gg(i,p+1))ret 1;
			ret 0;
		}
	}
	il void work()
	{
		rd();n=rd();m=rd();q=rd();
		for(int i=1;i<=n;++i)x[i]=rd();
		for(int i=1;i<=m;++i)y[i]=rd();
		if(m+n<=16)
		{
			cpy();pc(bf1::gg()|48);
			for(int z=1;z<=q;++z)
			{
				cpy();kx=rd();ky=rd();
				for(int i=1;i<=kx;++i)px[i]=rd(),vx[i]=rd(),xx[px[i]]=vx[i];
				for(int i=1;i<=ky;++i)py[i]=rd(),vy[i]=rd(),yy[py[i]]=vy[i];
				pc(bf1::gg()|48);
			}
			pc('\n');
			ret;
		}
	}
}
int main()
{
	file(expand);
	Faust::work();
	ret 0;
}