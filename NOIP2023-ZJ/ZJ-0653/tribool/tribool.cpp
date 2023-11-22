#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a,b,ans,fa[100010],e[100010];
char f[100010];
char v,q;
int find(int x)
{
	while(x!=fa[x])
	x=fa[x]=fa[fa[x]];
	return x;
}
void hb(int x,int y)
{
	int tx=find(x),ty=find(y);
	if(tx!=ty)
	{
		fa[tx]=ty;
		f[ty]=f[tx];
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			f[i]=q;
			e[i]=0;
		}
		ans=0;
		while(m--)
		{
			cin>>v;
			if(v=='T'||v=='U'||v=='F')
			{
				cin>>a;
				f[find(a)]=v;
			}
			else
			{
				cin>>a>>b;
				if(v=='+')
				hb(a,b);
				else
				{
					int ta=find(a),tb=find(b);
					if(e[ta]!=0)
					hb(e[ta],b);
					if(e[tb]!=0)
					hb(e[tb],a);
					e[ta]=b;
					e[tb]=a;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			int x=find(i);
			//cout<<f[i]<<" ";
			if(f[find(i)]=='U')
			ans+=1;
			else if(e[i]!=0&&find(i)==find(e[i]))
			ans+=1;
		}
		//cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
