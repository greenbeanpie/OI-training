#include<bits/stdc++.h>
using namespace std;
int T,n,m,c,a[100001],ans,fa[100001];
bool bj;
int find(int k)
{
	while(fa[k]!=k)
	{
		k=fa[k];
		a[k]=max(a[k],a[fa[k]]);
		a[fa[k]]=max(a[k],a[fa[k]]);
		fa[k]=fa[fa[k]];
		a[fa[k]]=max(a[fa[fa[k]]],a[fa[k]]);
		a[fa[fa[k]]]=max(a[fa[fa[k]]],a[fa[k]]);
	}
	a[k]=max(a[k],a[fa[k]]);
	a[fa[k]]=max(a[k],a[fa[k]]);
	return k;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i;
	cin>>c>>T;
	if(c==1 || c==2)
	{
		int x[11],y[11],j[11],t[11];
		char v[11];
		while(T--)
		{
			scanf("%d%d",&n,&m);
			int mi=n+1;
			for(i=1;i<=n;i++)
			{
				cin>>v[i];
				scanf("%d",&x[i]);
				if(v[i]=='+' || v[i]=='-')
				{
					scanf("%d",&y[i]);
				}
			}
			for(j[1]=1;j[1]<=3;j[1]++)
			for(j[2]=1;j[2]<=3;j[2]++)
			for(j[3]=1;j[3]<=3;j[3]++)
			for(j[4]=1;j[4]<=3;j[4]++)
			for(j[5]=1;j[5]<=3;j[5]++)
			for(j[6]=1;j[6]<=3;j[6]++)
			for(j[7]=1;j[7]<=3;j[7]++)
			for(j[8]=1;j[8]<=3;j[8]++)
			for(j[9]=1;j[9]<=3;j[9]++)
			for(j[10]=1;j[10]<=3;j[10]++)
			{
				bj=true;
				int cnt=0;
				for(i=1;i<=n;i++)
				{
					t[i]=j[i];
				}
				for(i=1;i<=m;i++)
				{
					if(v[i]=='T')
					{
						t[x[i]]=1;
					}
					if(v[i]=='F')
					{
						t[x[i]]=2;
					}
					if(v[i]=='U')
					{
						t[x[i]]=3;
					}
					if(v[i]=='+')
					{
						t[x[i]]=t[y[i]];
					}
					if(v[i]=='-')
					{
						if(t[y[i]]==1 || t[y[i]]==2)
						{
							t[x[i]]=3-t[y[i]];
						}
						else
						{
							t[x[i]]=3;
						}
					}
				}
				for(i=1;i<=n;i++)
				{
					if(t[i]!=j[i])
					{
						bj=false;
						break;
					}
				}
				if(bj)
				{
					for(i=1;i<=n;i++)
					{
						if(j[i]==3)
						{
							cnt++;
						}
					}
					mi=min(mi,cnt);
				}
			}
			printf("%d\n",mi);
		}
	}
	if(c==3 || c==4)
	{
		int x,y;
		char v;
		while(T--)
		{
			ans=0;
			memset(a,0,sizeof(a));
			scanf("%d%d",&n,&m);
			for(i=1;i<=m;i++)
			{
				cin>>v;
				scanf("%d",&x);
				if(v=='T')
				{
					a[x]=1;
				}
				if(v=='F')
				{
					a[x]=2;
				}
				if(v=='U')
				{
					a[x]=3;
				}
			}
			for(i=1;i<=n;i++)
			{
				if(a[i]==3)
				{
					ans++;	
				}
			}
			printf("%d\n",ans);
		}
	}
	if(c==5 || c==6)
	{
		int x,y;
		char v;
		while(T--)
		{
			ans=0;
			memset(a,0,sizeof(a));
			scanf("%d%d",&n,&m);
			for(i=1;i<=n;i++)
			{
				fa[i]=i;
			}
			for(i=1;i<=m;i++)
			{
				cin>>v;
				scanf("%d",&x);
				if(v=='U')
				{
					a[x]=3;
				}
				if(v=='+')
				{
					scanf("%d",&y);
					fa[x]=find(y);
				}
			}
			for(i=1;i<=n;i++)
			{
				if(a[find(i)]==3)
				{
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
5 1
3 3
U 1
+ 2 1
+ 3 1
*/
