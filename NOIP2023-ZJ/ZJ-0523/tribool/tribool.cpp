#include<bits/stdc++.h>
using namespace std;
int arr[100005],num[100005];
bool vis[100005];
int f(int i,int tmp)
{
	if(num[i]==0||num[i])
	{
		return arr[i];
	}
	if(vis[i])
	{
		if(tmp==-1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	vis[i]=true;
	arr[i]=arr[i]*f(num[i],tmp*arr[i]);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	int n,m;
	char v;
	int a,b;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(c==3||c==4)
		{
			memset(arr,0,sizeof(arr));
			for(int i=1;i<=m;++i)
			{
				getchar();
				scanf("%c%d",&v,&a);
				if(v=='U')arr[a]=1;
				else arr[a]=0;
			}
			int res=0;
			for(int i=1;i<=n;++i)
			{
				if(arr[i]==1)res++;
			}
			printf("%d\n",res);
		}
		else
		{
			memset(arr,0,sizeof(arr));
			memset(num,-1,sizeof(num));
			memset(vis,false,sizeof(vis));
			for(int i=1;i<=m;++i)
			{
				getchar();
				scanf("%c",&v);
				if(v=='T'||v=='F'||v=='U')
				{
					scanf("%d",&a);
					num[a]=0;
					switch(v)
					{
						case 'T':
							arr[a]=1;
							break;
						case 'F':
							arr[a]=-1;
							break;
						case 'U':
							arr[a]=0;
							break;
					}
				}
				else
				{
					scanf("%d%d",&a,&b);
					switch(v)
					{
						case '+':
							if(num[b]==0)
							{
								arr[a]=arr[b];
								num[a]=0;
							}
							else
							{
								arr[a]=1;
								num[a]=b;
							}
							break;
						case '-':
							if(num[b]==0)
							{
								arr[a]=-arr[b];
								num[a]=0;
							}
							else
							{
								arr[a]=-1;
								num[a]=b;
							}
							break;
					}
				}	
				for(int i=1;i<=n;i++)
				{
					if(!vis[i])
					{
						arr[i]=f(i,1);
						num[i]=0;
					}
				}
			}
			int res=0;
			for(int i=1;i<=n;i++)
			{
				if(arr[i]==0&&num[i]!=-1)
				{
					res++;
				}
			}
			printf("%d\n",res);
		}
	}
}
