#include <bits/stdc++.h>
#define re register
using namespace std;
int Maxx,Maxy,Minx,Miny;
int x[500010],y[500010],n;
int c,m,q,kx,ky,px,py;
int vx,vy,X[500010],Y[500010];
string T;
int solve()			
{
	if (Maxx>Maxy) 
	{
//		dax
		if (Minx<Miny) return false;
		if (x[1]<=y[1]||x[n]<=y[m]) return false;
//		if (Y[n]>=Minx) return false;
		return true;
	}else{
//		day
		if (Miny<Minx) return false;
		if (y[1]<=x[1]||y[m]<=x[n]) return false;
//		if (X[n]>=Miny) return false;
		return true;
	}
}		
int solve1()			
{
	if (Maxx>Maxy) 
	{
//		dax
		if (Minx<Miny) return false;
		if (X[1]<=Y[1]||X[n]<=Y[n]) return false;
//		if (Y[n]>=Minx) return false;
		return true;
	}else{
//		day
		if (Miny<Minx) return false;
		if (Y[1]<=X[1]||Y[n]<=X[n]) return false;
//		if (X[n]>=Miny) return false;
		return true;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	Maxx=0,Minx=2147483647;
	Maxy=0,Miny=2147483647;
	for (re int i=1;i<=n;i++) cin>>x[i],Maxx=max(Maxx,x[i]),Minx=min(Minx,x[i]);
	for (re int i=1;i<=m;i++) cin>>y[i],Miny=min(Miny,y[i]),Maxy=max(Maxy,y[i]);
	
	T+=char(solve()+48);
	
	while(q--)
	{
		for (re int i=1;i<=n;i++) X[i]=x[i];
		for (re int i=1;i<=m;i++) Y[i]=y[i];
		Maxx=0,Minx=2147483647;
		Maxy=0,Miny=2147483647;
		cin>>kx>>ky;
		for (re int i=1;i<=kx;i++) cin>>px>>vx,X[px]=vx;
		for (re int i=1;i<=ky;i++) cin>>py>>vy,Y[py]=vy;
		
		for (re int i=1;i<=n;i++) Maxx=max(Maxx,X[i]),Minx=min(Minx,X[i]);
		for (re int i=1;i<=m;i++) Miny=min(Miny,Y[i]),Maxy=max(Maxy,Y[i]);
		
//		cout<<Maxx<<" "<<Maxy<<endl;
		T+=char(solve1()+48);
	}
	cout<<T<<endl;
	return 0;
}