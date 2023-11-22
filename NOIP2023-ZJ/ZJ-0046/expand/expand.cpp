#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,INF=1e9;
int pn,pm,px[MAXN],py[MAXN],maxn,minn,lx,rx,ly,ry;
int C,n,m,q,tmpx[MAXN],tmpy[MAXN],kx,ky,p,v,x[MAXN],y[MAXN];
int xmin[MAXN],ymin[MAXN],xmax[MAXN],ymax[MAXN];
int posx,posy,w1,w2;
bool flag;
int read()
{
	int x=0;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9')) ch=getchar();
	while('0'<=ch&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x;
}
bool gt()
{
	w1=n;
	w2=m;
	xmin[0]=INF,xmax[0]=-1;
	for(int i=1;i<=n;i++)
		xmin[i]=min(x[i],xmin[i-1]),
		xmax[i]=max(x[i],xmax[i-1]);
	ymin[0]=INF;ymax[0]=-1;
	for(int i=1;i<=m;i++)
		ymin[i]=min(y[i],ymin[i-1]),
		ymax[i]=max(y[i],ymax[i-1]);
	flag=0;
	while(1)
	{
		if(xmax[w1]>=y[w2]||ymin[w2]<=x[w1])
		{
			flag=1;
			break;
		}
		posx=w1-1;
		while(posx>=1)
			if(xmax[posx]>=ymax[w2-1]) posx--;
				else break;
		posy=w2-1;
		while(posy>=1)
			if(ymin[posy]<=xmin[posx]) posy--;
				else break;
		posx=w1-1;
		while(posx>=1)
			if(xmax[posx]>=ymax[posy]) posx--;
				else break;
		if(posx!=w1-1&&posy!=w2-1)
		{
			flag=1;
			break;
		}
		while(posx>=1)
			if(xmin[posx]==xmin[posx-1]) posx--;
				else break;
		while(posy>=1)
			if(ymax[posy]==ymax[posy-1]) posy--;
				else break;
		if(!posx&&!posy) break;
		if(!posx||!posy)
		{
			flag=1;
			break;
		}
		w1=posx;w2=posy;
	}
	return flag;
}
bool cal()
{
	minn=INF;
	for(int i=1;i<=pn;i++)
		minn=min(minn,px[i]);
	lx=pn;rx=1;
	for(int i=1;i<=pn;i++)
		if(minn==px[i]) lx=min(lx,i),rx=max(rx,i);
	maxn=-1;
	for(int i=1;i<=pm;i++)
		maxn=max(maxn,py[i]);
	ly=pm;ry=1;
	for(int i=1;i<=pm;i++)
		if(maxn==py[i]) ly=min(ly,i),ry=max(ry,i);
	for(int i=lx;i<=rx;i++)
		if(px[i]>=maxn) return 0;
	for(int i=ly;i<=ry;i++)
		if(py[i]<=minn) return 0;
	n=0;
	for(int i=1;i<=lx;i++)
		x[++n]=px[i];
	m=0;
	for(int i=1;i<=ly;i++)
		y[++m]=py[i];
	if(gt()) return 0;
	n=0;
	for(int i=pn;i>=rx;i--)
		x[++n]=px[i];
	m=0;
	for(int i=pm;i>=ry;i--)
		y[++m]=py[i];
	if(gt()) return 0;
	return 1;
}
bool calc()
{
	bool ret=0;
	if(cal()) ret=1;
	for(int i=1;i<=max(pn,pm);i++) swap(px[i],py[i]);
	swap(pn,pm);
	if(cal()) ret=1;
	for(int i=1;i<=max(pn,pm);i++) swap(px[i],py[i]);
	swap(pn,pm);
	return ret;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	C=read();pn=read();pm=read();q=read();
	for(int i=1;i<=pn;i++) tmpx[i]=read();
	for(int i=1;i<=pm;i++) tmpy[i]=read();
	for(int i=1;i<=pn;i++) px[i]=tmpx[i];
	for(int i=1;i<=pm;i++) py[i]=tmpy[i];
	if(!calc()) printf("0");
	else printf("1");
	while(q--)
	{
		for(int i=1;i<=pn;i++) px[i]=tmpx[i];
		for(int i=1;i<=pm;i++) py[i]=tmpy[i];
		kx=read();ky=read();
		for(int i=1;i<=kx;i++)
			p=read(),v=read(),px[p]=v;
		for(int i=1;i<=ky;i++)
			p=read(),v=read(),py[p]=v;
		if(!calc()) printf("0");
		else printf("1");
	}
	printf("\n");
	return 0;
}