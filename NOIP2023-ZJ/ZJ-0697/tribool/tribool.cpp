#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0)
using namespace std;
int cl,t,n,m,f,w,u,minn,b[100],c[100],x[100005],y[100005];
char v;
struct str{
int i,j;char v;
}a[100005];
void dfs(int k,int s)
{
	if(k==n+1)
	{
		for(int i=1;i<=n;i++) c[i]=b[i];
		for(int i=1;i<=m;i++)
		{
			if(a[i].v=='+') c[a[i].i]=c[a[i].j];
			else if(a[i].v=='-') c[a[i].i]=c[a[i].j]==2?2:c[a[i].j]^1;
			else 
			{
				if(a[i].v=='T') c[a[i].i]=1;
				if(a[i].v=='F') c[a[i].i]=0;
				if(a[i].v=='U') c[a[i].i]=2;
			}
		}
		f=0;
		for(int i=1;i<=n;i++) 
		if(c[i]!=b[i]) {f=1;break;}
		if(f==0) minn=min(minn,s); 
	}
	else 
	{
		b[k]=1;dfs(k+1,s);
		b[k]=0;dfs(k+1,s);
		b[k]=2;dfs(k+1,s+1);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	IOS;
	cin>>cl>>t;
	while(t--)
	{
		cin>>n>>m;
		if(cl==1||cl==2)
		{
			for(int i=1;i<=m;i++) 
			{
				cin>>a[i].v;
				if(a[i].v=='+'||a[i].v=='-') cin>>a[i].i>>a[i].j;
				else cin>>a[i].i;
			}
			minn=n;
			dfs(1,0);
			cout<<minn<<endl;
		}
		else if(cl==3||cl==4)
		{
			minn=0;
			for(int i=1;i<=n;i++) x[i]=-1;
			for(int i=1;i<=m;i++)
			{
				cin>>v;cin>>w;
				if(v=='T') x[w]=1;
				if(v=='U') x[w]=2;
				if(v=='F') x[w]=0;
			}
			for(int i=1;i<=n;i++)
			if(x[i]==2) minn++;
			cout<<minn<<endl;
		}
		else if(cl==5||cl==6)
		{
			minn=0;
			for(int i=1;i<=n;i++) x[i]=-1;
			for(int i=1;i<=m;i++)
			{
				cin>>v;cin>>w;a[i].v=v;a[i].i=w;
				if(v=='U') x[w]=2;
				else if(v=='+')
				{
					cin>>u;x[w]=x[u];
					a[i].j=u;
				}
			}
			for(int k=1;k<=100;k++)
			{
			for(int i=1;i<=m;i++)
			{
				if(a[i].v=='U') x[a[i].i]=2;
				else x[a[i].i]=x[a[i].j];
			}
		    }
			for(int i=1;i<=n;i++)
			if(x[i]==2) minn++;
			cout<<minn<<endl;
		}
	}
}
/*#include<bits/stc++.h>
using namespace std;
int find(int v)
{
	if(f[v].fa!=v) f[v].fa=find(f[v].fa);
	return f[v].fa;
}
int main()
{
	scanf("%d%d",&c,&t);
	while(t--)
	{
	   scanf("%d%d",&n,&m);
	   for(int i=1;i<=n;i++) 
	   {
	   	 f[i].fa=i;f[i].qu=0;sum[i]=0;
	   }
	   for(int i=1;i<=m;i++)
	   {
	   	 scanf("%c",&v);
	   	 if(v=='+')
	   	 {
	   	   scanf("%d%d",&x,&y);
		   fx=find(x);fy=find(y);
		   if(fx!=fy)
		   {
		   	 f[fx].fa=fy;
		   	 if(f[fx].qu<=0&&f[fy].qu>0) f[fx].qu=f[fy].qu;
		     if(f[fy].qu<=0&&f[fx].qu>0) f[fy].qu=f[fx].qu; 
		     if(f[fx].qu!=f[fy].qu) f[fx].qu=f[fy].qu=3;
		     sum[fy]+=sum[fx];
		   }
		 }
	   	 else if(v=='-')
	   	 {
	   	   scanf("%d%d",&x,&y);
		   fx=find(x);fy=find(y);
		   if(fx==fy) f[fx].qu=f[fy].qu=3;
		   else if(f[fx].qu==f[fy].qu&&f[fx].qu!=0)
		   {
		   	 f[fx].qu=f[fy].qu=3;
		   }
		 }
	   	 else 
	   	 {
	   	   scanf("%d",&x);
		   	
		 }
	   }
	}
}*/
