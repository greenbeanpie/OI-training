#include<bits/stdc++.h>
using namespace std;
const int N = 2005,N2 = 5e5+5,INF = 0x3f3f3f3f;
int f[N][N],x[N2],y[N2],nx[N2],ny[N2];
int c,n,m,p,nn,mm;
int px[N2],py[N2],qx[N2],qy[N2];
bool flag = 0;
void DP()
{
	if(x[1] == y[1]) return printf("0"),void();
	bool ty = (x[1] > y[1]);
	memset(f,0,sizeof(f));
	f[1][1] = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(i == 1 && j == 1) continue;
			if(((x[i] > y[j]) ^ ty) || (x[i] == y[j])) continue;
			if(j > 1) f[i][j] |= f[i][j-1];
			if(i > 1) f[i][j] |= f[i-1][j];
		}
	}
	printf("%d",f[n][m]);
}
void solve2()
{
	flag = 0;
	if(1ll*(x[1]-y[1])*(x[n]-y[m]) <= 0) return printf("0"),void();
	if(y[1] < x[1]) swap(x,y),swap(n,m),flag = 1;
	mm = nn = 0;
	for(int i = 1,mx = -1,mn = INF;i <= n;i++)
	{
		mx = max(mx,x[i]);
		if(mn > x[i])
		{
			++nn;
			px[nn] = mn = x[i];
			py[nn] = mx;
			mx = -1;
		}
	}
	for(int i = 1,mx = -1,mn = INF;i <= m;i++)
	{
		mn = min(mn,y[i]);
		if(mx < y[i])
		{
			++mm;
			qx[mm] = mx = y[i];
			qy[mm] = mn;
			mn = INF;
		}
	}
	int c1 = 1,c2 = 1;
	while(c1 < nn && c2 < mm)
	{
		if(c1 < nn && py[c1+1] < qx[c2]) c1++;
		else if(c2 < mm && px[c1] < qy[c2+1]) c2++;
		else return printf("0"),void();
	}
	reverse(x+1,x+1+n);
	reverse(y+1,y+1+m);
	mm = nn = 0;
	for(int i = 1,mx = -1,mn = INF;i <= n;i++)
	{
		mx = max(mx,x[i]);
		if(mn >= x[i])
		{
			++nn;
			px[nn] = mn = x[i];
			py[nn] = mx;
			mx = -1;
		}
	}
	for(int i = 1,mx = -1,mn = INF;i <= m;i++)
	{
		mn = min(mn,y[i]);
		if(mx <= y[i])
		{
			++mm;
			qx[mm] = mx = y[i];
			qy[mm] = mn;
			mn = INF;
		}
	}
	c1 = 1,c2 = 1;
	while(c1 < nn && c2 < mm)
	{
		if(c1 < nn && py[c1+1] < qx[c2]) c1++;
		else if(c2 < mm && px[c1] < qy[c2+1]) c2++;
		else return printf("0"),void();
	}
	printf("1");
}
int main()
{
	//system("fc expand.out expand3.ans");
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int C,q;
	scanf("%d%d%d%d",&C,&n,&m,&q);
	for(int i = 1;i <= n;i++) scanf("%d",nx+i);
	for(int i = 1;i <= m;i++) scanf("%d",ny+i);
	for(int i = 1;i <= n;i++) x[i] = nx[i];
	for(int i = 1;i <= m;i++) y[i] = ny[i];
	if(C > 7) solve2();
	else DP();
	if(flag) swap(n,m),swap(x,y);
	while(q--)
	{
		for(int i = 1;i <= n;i++) x[i] = nx[i];
		for(int i = 1;i <= m;i++) y[i] = ny[i];
		int kx,ky;scanf("%d%d",&kx,&ky);
		while(kx--)
		{
			int p,v;scanf("%d%d",&p,&v);
			x[p] = v;
		}
		while(ky--)
		{
			int p,v;scanf("%d%d",&p,&v);
			y[p] = v;
		}
		if(C > 7) solve2();
		else DP();
		if(flag) swap(n,m),swap(x,y);
	}
	puts("");
	return 0;
}