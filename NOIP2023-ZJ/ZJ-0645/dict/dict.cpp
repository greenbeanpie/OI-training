#include<bits/stdc++.h>
#define ll long long
#define gch getchar()
#define pch putchar(' ')
using namespace std;
ll rd()
{
	ll f=1,x=0;char c;
	while(!isdigit(c=gch))if(c==45)f=-1;
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=gch;
	return f*x;
}
void wt(ll x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)wt(x/10);
	putchar(x%10+'0');
}
const int N=3005;
int n,m,w[N][N],mn[N][N],mx[N][N];
void in()
{
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)w[i][j]=gch-'a'+1;
		gch;
	}
}
void pre(int x)
{
	sort(w[x]+1,w[x]+m+1);
	for(int i=1;i<=m;i++)mn[x][i]=w[x][i],mx[x][i]=w[x][m-i+1];
}
bool ck(int s,int t)
{
	for(int i=1;i<=m;i++)
	{
		if(mn[s][i]==mx[t][i])continue;
		if(mn[s][i]<mx[t][i])return 1;
		else return 0;
	}
}
bool slv(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(i==x)continue;
		if(!ck(x,i))return 0;
	}
	return 1;
}
int main()
{
	freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	in();
	for(int i=1;i<=n;i++)pre(i);
	for(int i=1;i<=n;i++)wt(slv(i));
	return 0;
}
