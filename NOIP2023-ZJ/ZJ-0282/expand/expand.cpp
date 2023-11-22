//it's obviously wrong,but no idea
#include<bits/stdc++.h>
const int N=500001,M=500001,inf=0x7fffffff;
int c,n,m,q,x[N],_x[N],minx,maxx,y[M],_y[M],miny,maxy;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr),std::cout.tie(nullptr);
	std::cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i)std::cin>>_x[i];
	for(int i=1;i<=m;++i)std::cin>>_y[i];
	if(c>=8&&c<=14){
		for(int T=0,kx,ky,p,v;T<=q;++T){
			for(int i=1;i<=n;++i)x[i]=_x[i];
			for(int i=1;i<=m;++i)y[i]=_y[i];
			if(T){
				std::cin>>kx>>ky;
				while(kx--)std::cin>>p>>v,x[p]=v;
				while(ky--)std::cin>>p>>v,y[p]=v;
			}
			if(1ll*(x[1]-y[1])*(x[n]-y[m])<=0){std::cout<<0;continue;}
			minx=miny=inf,maxx=maxy=-inf;
			for(int i=1;i<=n;++i)minx=std::min(minx,x[i]),maxx=std::max(maxx,x[i]);
			for(int i=1;i<=m;++i)miny=std::min(miny,y[i]),maxy=std::max(maxy,y[i]);
			if(y[m]>maxx)std::cout<<1;
			else std::cout<<0;
		}
		return 0;
	}
	for(int T=0,kx,ky,p,v;T<=q;++T){
		for(int i=1;i<=n;++i)x[i]=_x[i];
		for(int i=1;i<=m;++i)y[i]=_y[i];
		if(T){
			std::cin>>kx>>ky;
			while(kx--)std::cin>>p>>v,x[p]=v;
			while(ky--)std::cin>>p>>v,y[p]=v;
		}
		if(1ll*(x[1]-y[1])*(x[n]-y[m])<=0){std::cout<<0;continue;}
		minx=miny=inf,maxx=maxy=-inf;
		for(int i=1;i<=n;++i)minx=std::min(minx,x[i]),maxx=std::max(maxx,x[i]);
		for(int i=1;i<=m;++i)miny=std::min(miny,y[i]),maxy=std::max(maxy,y[i]);
		if(x[1]>y[1]){
			if(minx>miny&&maxx>maxy)std::cout<<1;
			else std::cout<<0;
		}
		else{
			if(minx<miny&&maxx<maxy)std::cout<<1;
			else std::cout<<0;
		}
	}
	return 0;
}