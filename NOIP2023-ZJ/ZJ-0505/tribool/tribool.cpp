#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,x,y,z,t,ans,f[100050],u[100050];
char op;
bool b[100050],flag[100050],dis[100050],l[100050];
void find(long long now,bool round)
{
	if (u[now]>n||u[now]==now) return;
	dis[now]=true;
	if (dis[u[now]]==false) 
	  {
	  	if (b[now]==true) l[now]=!round; else l[now]=round;
	  	if (b[u[now]]==true) find(u[now],!round); else find(u[now],round);
	  }
	else
	  {
	  	if (round!=l[u[now]]) f[now]=0;
	  	u[now]=now;
	  	dis[now]=false;
	  	b[now]=false;
	  	return;
	  }
	dis[now]=false;
	if (u[u[now]]<=n) 
	  {
	  	if (b[now]==true) b[now]=!b[u[now]]; else b[now]=b[u[now]];  
	  	u[now]=u[u[now]];
	  }
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&x,&t);
	while (t--)
	  {
	  	memset(f,63,sizeof(f));
	    memset(u,63,sizeof(u));
	  	memset(b,false,sizeof(b));
	  	memset(flag,false,sizeof(flag));
	  	scanf("%lld%lld",&n,&m);
	  	while (m--)
	  	  {
	  	  	cin>>op;
	  	  	if (op=='T')
	  	  	  {
	  	  	  	scanf("%lld",&x);
	  	  	  	f[x]=1;
	  	  	  	continue;
			  }
	  	  	if (op=='F')
			  {
				scanf("%lld",&x);
				f[x]=-1;
				continue;  	
			  } 
			if (op=='U')
			  {
			  	scanf("%lld",&x);
			  	f[x]=0;
			  	continue;
			  }
			if (op=='+')
			  {
			  	scanf("%lld%lld",&x,&y);
			  	if (f[y]!=1&&f[y]!=0&&f[y]!=-1)
			  	  {
			  	  	f[x]=2;
					u[x]=y;
					b[x]=false;
				  }
				else
				  {
				  	u[x]=n+1;
				  	f[x]=f[y];
				  }
			  	continue;
			  }
			if (op=='-')
			  {
			  	scanf("%lld%lld",&x,&y);
			  	if (f[y]!=1&&f[y]!=0&&f[y]!=-1)
			  	  {
			  	  	f[x]=2;
				    u[x]=y;
					b[x]=true;
				  }
				else
				  {
				  	u[x]=n+1;
				  	f[x]=-f[y];
				  }
				continue;
			  }
		  }
		for (i=1;i<=n;i++)
		  find(i,b[i]);
		for (i=1;i<=n;i++)
		  if ((u[i]==i&&b[i]==true)||(f[i]==0)) flag[i]=true;
		for (i=1;i<=n;i++)
		  if (u[i]<=n)
		    {
		      if (flag[u[i]]==true) flag[i]=true;	
			}
		ans=0;
		for (i=1;i<=n;i++)
		  if (flag[i]==true) ans++;
		printf("%lld\n",ans);
	  }
	return 0;
}