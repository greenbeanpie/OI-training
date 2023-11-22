#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int c,n,m,q;
int X[N],Y[N];
int t1[N],t2[N];
int MINX,MINY,MAXX,MAXY;
int minx,miny,maxx,maxy;
string ans;
int cnt;
bool check()
{
	if(c>=8&&c<=14)
	{
		if(t1[n]>t2[m]) return true;
	}
	if( (t1[1]-t2[1]) * (t1[n]-t2[m]) <=0) return false;
	if(t1[1]-t2[1]<0) // X < Y
	{
		if( maxx >= miny ) return false;
	}
	else // X > Y
	{
		if( maxx <= maxy ) return false;
	}
	return true;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",X+i);
		MAXX=max(MAXX,X[i]); 
		MINX=min(MINX,X[i]); 
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",Y+i);
		MAXY=max(MAXY,Y[i]); 
		MINY=min(MINY,Y[i]); 
	}
	for(int i=1;i<=n;i++) t1[i]=X[i];
	for(int i=1;i<=m;i++) t2[i]=Y[i];
	maxx=MAXX,maxy=MAXY,minx=MINX,miny=MINY;
	if(check()) putchar('1');
	else putchar('0');
	for(int i=1;i<=q;i++)
	{
		maxx=0,minx=1e9+1,maxy=0,miny=1e9+1;
		for(int j=1;j<=n;j++) t1[i]=X[i];
		for(int j=1;j<=m;j++) t2[i]=Y[i];
		int kx,ky,idx,v;
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++)
		{
			scanf("%d%d",&idx,&v);
			t1[idx]=v;
		}
		for(int j=1;j<=ky;j++)
		{
			scanf("%d%d",&idx,&v);
			t2[idx]=v;
		}
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,t1[i]);
			minx=min(minx,t1[i]);
		}
		for(int j=1;j<=m;j++)
		{
			maxy=max(maxy,t2[i]);
			miny=min(miny,t2[i]);
		}
		if(check()) putchar('1');
		else putchar('0');
	}
	return 0;
}