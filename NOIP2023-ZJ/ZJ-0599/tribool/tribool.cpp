#include<bits/stdc++.h>
using namespace std;
int xx[100001];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t,i,y,z,ans,n,m;
	char x;
	cin>>c>>t;
	if(c==3||c==4)
	{
		while(t!=0)
		{
			t--;
			cin>>n>>m;
			ans=0;
			for(i=1;i<=n;i++)
			{
				xx[i]=1;
			}
			for(i=1;i<=m;i++)
			{
				x=getchar();
				if(x!='T'&&x!='F'&&x!='U')
				{
					x=getchar();
				}
				scanf("%d",&y);
				if(x=='T')
				{
					xx[y]=1;
				}
				if(x=='F')
				{
					xx[y]=1;
				}
				if(x=='U')
				{
					xx[y]=0;
				}
			}
			for(i=1;i<=n;i++)
			{
				if(xx[i]==0)
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	if(c==5||c==6)
	{
		while(t!=0)
		{
			t--;
			cin>>n>>m;
			for(i=1;i<=n;i++)
			{
				xx[i]=-1;
			}
			for(i=1;i<=m;i++)
			{
				x=getchar();
				if(x!='U'&&x!='+')
				{
					x=getchar();
				}
				if(x=='U')
				{
					scanf("%d",&y);
					xx[y]=-2;
				}
				if(x=='+')
				{
					scanf("%d%d",&y,&z);
					if(xx[z]==-1)
					{
						xx[y]=z;
					}
					if(xx[z]==-2)
					{
						xx[y]=-2;
					}
					if(xx[z]!=-1&&xx[z]!=-2)
					{
						xx[y]=xx[z];
					}
				}
			}
			for(i=1;i<=n;i++)
			{
				if(xx[xx[i]]==-2)
				{
					xx[i]=-2;
				}
			}
			ans=0;
			for(i=1;i<=n;i++)
			{
				if(xx[i]==-2)
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}
