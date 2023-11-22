#include<bits/stdc++.h>
using namespace std;
struct node 
{
	long long x,y,v;
};
node xx[100001];
long long f[2][100001];
bool cmp(node aa,node bb)
{
	if(aa.x==bb.x)
	{
		return aa.y<=bb.y;
	}
	return aa.x<bb.x;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	long long c,t,n,m,k,d,i,ans,j,cc,fr=0;
	cin>>c>>t;
	while(t!=0)
	{
		t--;
		cin>>n>>m>>k>>d;
		for(i=0;i<=1;i++)
		{
			for(j=0;j<=k;j++)
			{
				f[i][j]=0;
			}
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&xx[i].x,&xx[i].y,&xx[i].v);
		}
		sort(xx+1,xx+m+1,cmp);
		cc=1;
		fr=1;
		for(i=1;i<=n;i++)
		{
			cc=1-cc;
			for(j=0;j<=k;j++)
			{
				f[cc][j]=0;
			}
			while(xx[fr].x==i)
			{
				for(j=xx[fr].y;j<=k;j++)
				{
					f[cc][j]+=xx[fr].v;
				}
				fr++;
			}
			for(j=0;j<=k;j++)
			{
				f[cc][0]=max(f[cc][0],f[1-cc][j]);
			}
			for(j=1;j<=k;j++)
			{
				f[cc][j]=f[cc][j]+f[1-cc][j-1]-d;
			}
		}
		ans=0;
		for(i=0;i<=k;i++)
		{
			ans=max(ans,f[cc][i]);
		}
		cout<<ans<<endl;
	}
}
