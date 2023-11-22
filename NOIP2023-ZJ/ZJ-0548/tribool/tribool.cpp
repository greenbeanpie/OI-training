#include<bits/stdc++.h>
using namespace std;

int c,t,n,m,fa[100005],ans[100005],u[100005];
char zhi[100005];

int dfs(int now,int beg,int flag)
{
	if(now==beg)
	{
		if(zhi[now]=='+')
		{
			if(flag==1) return 1;
			else return 2;
		}
		if(zhi[now]=='-')
		{
			if(flag==0) return 1;
			else return 2;
		}
	}
	if(zhi[now]=='+') return dfs(fa[now],beg,flag);
	else return dfs(fa[now],beg,!flag);
}

int find(int x)
{
	if(fa[x]==0)
	{
		u[x]=1;
		if(zhi[x]=='U') ans[x]=2;
		else ans[x]=1;
		return ans[x];
	}
	if(u[x]==0)
	{
		u[x]=1;
		if(fa[x]!=x) return ans[x]=find(fa[x]);
		else if(zhi[x]=='+') return ans[x]=1;
		else return ans[x]=2;
	}
	else
		if(ans[x]!=0) return ans[x];
		else return ans[x]=dfs(fa[x],x,1);
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		
		for(int i=1;i<=n;i++) fa[i]=i;
		memset(ans,0,sizeof(ans));
		memset(u,0,sizeof(u));
		for(int i=1;i<=n;i++) zhi[i]='+';
		
		for(int i=1;i<=m;i++)
		{
			char ch;
			cin>>ch;
			if(ch=='T'||ch=='F'||ch=='U') 
			{
				int x;
				cin>>x;
				fa[x]=0;
				zhi[x]=ch;
			}
			if(ch=='+'||ch=='-')
			{
				int x,y;
				cin>>x>>y;
				fa[x]=fa[y];
				if(ch=='+') zhi[x]=zhi[y];
				else if(zhi[y]=='+') zhi[x]='-';
				else if(zhi[y]=='-') zhi[x]='+';
				else fa[x]=0,zhi[x]=zhi[y];
			}
		}
//		for(int i=1;i<=n;i++) cout<<zhi[i]<<" ";
		for(int i=1;i<=n;i++)
			if(u[i]==0)
			{
				if(fa[i]!=i) ans[i]=find(i);
				else if(zhi[i]=='+') u[i]=1,ans[i]=1;
				else u[i]=1,ans[i]=2;
			}
		
		int sum=0;
		for(int i=1;i<=n;i++)
			if(ans[i]==2) sum++;
		cout<<sum<<endl;
	}
}
/*
1 1
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
*/
/*
2 6
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
10 10
- 7 5
+ 5 1
+ 1 7
+ 2 3
+ 3 4
+ 4 6
+ 6 8
- 8 9
+ 9 10
- 10 2
10 10
- 1 1
U 1
T 7
U 8
- 9 6
U 3
- 9 3
- 6 3
+ 9 3
- 9 8
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
*/