#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int fa[maxn<<2];
set<int> k;
set<int> qk;
void init(int n)
{
	for(int i=1;i<=n*3;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	int x_fa=find(x);
	int y_fa=find(y);
	fa[x_fa]=y_fa;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,tt;
	cin>>c>>tt;
	while(tt--)
	{
		int cnt=0;
		int n,m;
		cin>>n>>m;
		init(n);
		for(int i=1;i<=m;i++)
		{
			char v;
			int x,y;
			cin>>v;
			if(v=='-')
			{
				cin>>x>>y;
				unionn(y,x+n);
				unionn(y+n,x);
			}
			else if(v=='+')
			{
				cin>>x>>y;
				unionn(y,x);
				unionn(y+n,x+n);
			}
			else if(v=='T')
			{
				cin>>x;
				unionn(x,x+n);
				unionn(x,x+n*2);
			}
			else if(v=='U')
			{
				unionn(x+n*2,x+n);
				unionn(x+n*2,x);
			}
			else
			{
				unionn(x+n,x);
				unionn(x+n,x+n*2);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(find(i)==find(i+n)) cnt++;
		}
		cout<<cnt<<endl;
	}
}