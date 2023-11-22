#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int cc,T,n,m,cnt,s[N],nex[N],last[N],head[N],ans=0,sk;
bool vis[N],vis1[N],w[N];
char c,x[N];
struct arr
{
	int to,w;
}a[N];
char sw(char c)
{
	if(c=='U') return 'U';
	if(c=='T') return 'F';
	return 'T';
}
void dfs(int k,int fa)
{
//	cout<<k<<" "<<vis1[k]<<endl;
	vis1[k]=1;
	
	if(x[k]=='U') ans++;
	for(int i=head[k];i;i=last[i])
	{
		int to=a[i].to,w=a[i].w;
		if(to==fa||vis1[to]) continue;
		if(w) x[to]=sw(x[k]);
		else x[to]=x[k];
		dfs(to,k);
	}
}
bool dfs1(int k,int fa)
{
	vis1[k]=1;
	sk++;
	
	bool f=0;
	for(int i=head[k];i;i=last[i])
	{
		int to=a[i].to,w=a[i].w;
	//	cout<<k<<" "<<to<<endl;
		int p;
		if(w) p=!s[k];
		else p=s[k];
		if(s[to]!=-1&&p!=s[to]) f=1;
		if(to==fa||vis1[to]) continue;
		s[to]=p;
		f=f||dfs1(to,k);
	}
	return f;
}
void add(int x,int y,int z)
{
	last[++cnt]=head[x];
	head[x]=cnt;
	a[cnt].w=z;
	a[cnt].to=y;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&cc,&T);
	while(T--)
	{
		scanf("%d %d\n",&n,&m);
	//	memset(ss);
		ans=0;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			last[i]=0;
			s[i]=-1;
			head[i]=0;
			x[i]='W';
			nex[i]=i;
			w[i]=0;
			vis[i]=0;
			vis1[i]=0;
		}
		
		//cout<<n<<" "<<m<<endl;
		for(int i=1;i<=m;i++)
		{
			char c=getchar();
		//	cout<<c[i]<<endl;
			if(c=='T'||c=='F'||c=='U')
			{
				int id;
				scanf("%d\n",&id);
				if(c=='T') nex[id]=n+1;
				if(c=='F') nex[id]=n+2;
				if(c=='U') nex[id]=n+3;
				w[id]=0;
				//vis[id]=1;
			}
			else 
			{
				int u,v;
				scanf("%d %d\n",&u,&v);
				nex[u]=nex[v];
				if(c=='-') w[u]=!w[v];
				 else w[u]=w[v];
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			
			int p=nex[i]; 
			if(p<=n)
			{
				if(p==i&&(w[i])) x[i]='U';
				else if(p!=i)
				if(w[i]) add(i,p,1),add(p,i,1);
				 else add(i,p,0),add(p,i,0);
			}
			else 
			{
				if(p==n+1) x[i]='T';
				if(p==n+2) x[i]='F';
				if(p==n+3) x[i]='U';
			}
			//cout<<i<<" "<<x[i]<<endl;
		}
		//cout<<cnt<<endl;
		for(int i=1;i<=n;i++)
		if(!vis1[i]&&x[i]!='W') dfs(i,i);
		for(int i=1;i<=n;i++)
		if(!vis1[i])
		{
			s[i]=0;
			sk=0;
			if(dfs1(i,i)) ans+=sk;	
		}	
		printf("%d\n",ans);
	}
	return 0;
}