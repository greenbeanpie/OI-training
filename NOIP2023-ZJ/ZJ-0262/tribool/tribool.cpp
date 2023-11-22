#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x,y,fx,fy,tx,ans,s[100010][2],d[100010];
int size[100010],f[100010];
map<char,int> p;
char v;
int find(int x)
{
	if(x==f[x]) return x;
	tx=find(f[x]);
	d[x]^=d[f[x]],f[x]=tx;
	return tx;
}
void cal()
{
	for(int i=1;i<=n;++i) if(s[i][0]==i)
	{
		s[i][0]=0;
		if(s[i][1]) s[i][1]=2;
	}
	for(int i=1;i<=n;++i) f[i]=i,size[i]=1,d[i]=0;
	for(int i=1;i<=n;++i)
	{
		if(!s[i][0])	
		{
			if(s[i][1]>1) ans+=size[i];
		}
		else
		{
			fx=find(i);fy=find(s[i][0]);
			//cout<<fx<<' '<<fy<<'\n';
			if(fx!=fy)
			{
				if(!s[fx][0]&&!s[fy][0]) continue;
				else if(s[fx][0])
				{
					if(s[fy][1]>1&&fy<i) ans+=size[fx];
					size[fy]+=size[fx];f[fx]=fy;
					d[fx]=d[x]^s[i][1]^d[y];
				}
				else
				{
					if(s[fx][1]>1&&fx<i) ans+=size[fy];
					size[fx]+=size[fy];f[fy]=fx;
					d[fy]=d[y]^s[i][1]^d[x];
				}
			}
			else
			{
				if(d[i]^d[s[i][0]]!=s[i][1]) s[fx][1]=2,ans+=size[fx];
			}
		}
	}
}
int main()
{
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	cin>>c>>t;p['T']=0,p['F']=1,p['U']=2;
	while(t--)
	{
		cin>>n>>m;ans=0;
		for(int i=1;i<=n;++i) s[i][0]=i,s[i][1]=0;
		while(m--)
		{
			cin>>v;
			if(v=='+') 
			{
				cin>>x>>y;
				s[x][0]=s[y][0],s[x][1]=s[y][1];
			}
			else if(v=='-')
			{
				cin>>x>>y;
				s[x][0]=s[y][0],s[x][1]=s[y][1]^1;
			}
			else
			{
				cin>>x;
				s[x][0]=0,s[x][1]=p[v];
			}
		}
		cal();
		cout<<ans<<'\n';	
	}
	return 0;
}