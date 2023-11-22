#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,q;
int fa[N];
bool flag[N];
int ans;
int pre[2*N];
int find(int x)
{
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
void merge(int x,int y)
{
	pre[find(x)]=find(y);
}
int dfs(int x)
{
	if(fa[x]==0||fa[x]==-x)
	{
		return 0;
	}
	else if(fa[x]==n+1 || fa[x]==-n-1) 
	{
		return fa[x];
	}
	else
	{
		if(flag[abs(fa[x])]==true)
		{
			return n+1;
		}
		flag[x]=true;
		int y=dfs(abs(fa[x]));
		flag[x]=false;
		return y;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>q;
		//clear
		for(int i=1;i<=n;i++)
			fa[i]=i;	
		for(int i=0;i<=2*n;i++)
			pre[i]=i;		
		ans=0;
		for(int i=1,a,b;i<=q;i++)
		{
			char op;
			cin>>op>>a;
			if(op=='+')
			{
				cin>>b;
				fa[a]=fa[b];
			}
			else if(op=='-')
			{
				cin>>b;
				fa[a]=-fa[b];
			}
			else if(op=='T')
				fa[a]=n+1;
			else if(op=='F')
				fa[a]=-n-1;
			else if(op=='U')
				fa[a]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(fa[i]!=0 && fa[i]!= n+1 && fa[i] !=-n-1 && fa[i]!= i)
			{
				//if(find(i+n)==find(n-i)) cout<<"true";
				merge(fa[i]+n,i+n);
				merge(n-i,n-fa[i]);
				//printf("%d %d %d %d \n",fa[i],i,-fa[i],-i);				
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(find(i+n)==find(-i+n))
			{
				ans++;					
			}
			else
				fa[i]=dfs(i);
			if(fa[i]==0) ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}

