#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d,b[30],f[30];
long long maxx;
struct str{
int x,y,v;
}a[100005];
void read(int &x)
{
	char c=getchar();int w=1;x=0;
	while(!isdigit(c)) {if(c=='-') w=-1;c=getchar();}
	while(isdigit(c)) {x=x*10+c-48;c=getchar();}
	x*=w;
}
void dfs(int x,long long s,int li)
{
	if(x==n+1)
	{
	  for(int i=1;i<=m;i++)
	  if(b[a[i].x]-b[a[i].x-a[i].y]==a[i].y&&a[i].y<=k) s=s+1LL*a[i].v;
	  maxx=max(maxx,s);
	}
	else 
	{
		b[x]=b[x-1];
		if(f[x]==1&&li<k){b[x]++;dfs(x+1,s-1LL*d,li+1);b[x]=b[x]-1;}
		dfs(x+1,s,0);
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(c);read(t);
	while(t--)
	{
		read(n);read(m);read(k);read(d);
		for(int i=1;i<=m;i++) {read(a[i].x);read(a[i].y);read(a[i].v);}
		maxx=0;
		if(c==17||c==18)
		{
		  for(int i=1;i<=m;i++)
		  if(1LL*a[i].v>1LL*d*a[i].y&&a[i].y<=k) maxx=maxx+1LL*a[i].v-1LL*d*a[i].y;
		  printf("%lld\n",maxx);
		}
		else if(c==1||c==2)
		{
			for(int i=0;i<=n;i++) f[i]=0;
			for(int i=1;i<=m;i++)
			 for(int j=a[i].x-a[i].y+1;j<=a[i].x;j++)
			 f[j]=1;
			dfs(1,0,0);
			printf("%lld\n",maxx);
		}
	}
	return 0;
}
