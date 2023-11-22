#include<bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int c,t;
int n,m;
int cnt;
char ch[N];
int st[N];

int e[N],h[N],ne[N],idx;

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dfs(int u,int fa)
{
	//st[u]=1;
	cout<<u<<endl;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=e[i];
		ch[v]='U';
		if(v!=fa) dfs(v,u);
	}
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	
	if(c==3||c==4)
	{
		while(t--)
		{
			for(int i=1;i<=n;i++) ch[i]='T';
			cnt=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				char op;
				int ii,jj;
				cin>>op;
				if(op=='T'||op=='F'||op=='U')
				{
					cin>>ii;
					ch[ii]=op;
				}
			}
			
			for(int i=1;i<=n;i++)
			{
				if(ch[i]=='U')
					cnt++;
			}
		}
		cout<<cnt<<endl;
		return 0;
	}
	else if(c==5||c==6)
	{
		memset(h,-1,sizeof(h));
		while(t--)
		{
			for(int i=1;i<=n;i++) ch[i]='T';
			cnt=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				char op;
				int ii,jj;
				cin>>op;
				if(op=='U')
				{
					cin>>ii;
					ch[ii]='U';
				}
				else
				{
					cin>>ii>>jj;
					add(jj,ii);
					if(ch[jj]=='U') ch[i]='U',dfs(ii,-1);
					else ch[ii]='T';
				}
			}
			
			for(int i=1;i<=n;i++)
			{
				if(ch[i]=='U') dfs(i,-1);
			}
			for(int i=1;i<=n;i++)
			{
				if(ch[i]=='U') cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

/*0
0
206
15
275
891*/

