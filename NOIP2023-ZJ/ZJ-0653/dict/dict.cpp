#include<bits/stdc++.h>
using namespace std;
int n,m,miny,maxy;
string c[3010],a[3010],f[3010],g[3010];
char minx,maxx;
bool cmp(string x,string y)
{
	return x<y;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=c[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]==a[1])
			cout<<"1";
			else
			cout<<"0";
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=c[i];
			g[i]=c[i];
			minx='z',maxx='a';
			miny=0,maxy=0;
			for(int j=0;j<m;j++)
			{
				if(c[i][j]<=minx)
				{
					minx=c[i][j];
					miny=j;
				}
				if(c[i][j]>=maxx)
				{
					maxx=c[i][j];
					maxy=j;
				}
			}
			for(int j=0;j<m;j++)
			if(j<miny&&f[i][j]!=minx)
			{
				char t=f[i][j];
				f[i][j]=minx;
				f[i][miny]=t;
				break;
			}
			for(int j=0;j<m;j++)
			if(j<maxy&&g[i][j]!=maxx)
			{
				char t=g[i][j];
				g[i][j]=maxx;
				g[i][maxy]=t;
				break;
			}
		}
		sort(g+1,g+n+1,cmp);
		int cnt=0;
		for(int i=1;i<=n;i++)
		if(f[i]==g[1]&&g[1]==c[i])
		cnt+=1;
		for(int i=1;i<=n;i++)
		{
			if((g[1]>f[i])||(f[i]==g[1]&&cnt==1))
			cout<<"1";
			else
			cout<<"0";
		}
	}
	return 0;
}
