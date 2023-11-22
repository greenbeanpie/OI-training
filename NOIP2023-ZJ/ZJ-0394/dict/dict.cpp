#include<bits/stdc++.h>
using namespace std;
const int N=3050;
int n,m,k[N],p[N];
string s,zx,cx;
struct node
{
	string a,b;
}c[N];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		memset(k,0,sizeof(k));
		memset(p,0,sizeof(p));
		cin>>s;
		for(int j=0;j<m;j++)
		{
			k[j]=s[j]-'a';
			p[j]=k[j];
		}
		sort(k,k+m);
		for(int j=0;j<m;j++)
		{
			c[i].a+=char(k[j]+'a');
		}
		sort(p,p+m,cmp);
		for(int j=0;j<m;j++)
		{
			c[i].b+=char(p[j]+'a');
		}
	}
	cx="";
	zx=c[1].b;
	for(int i=2;i<=n;i++)
	{
		if(cx==""||c[i].b<cx)
			cx=c[i].b;
		if(cx<zx)
			swap(zx,cx);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i].b==zx)
		{
			if(c[i].a<cx)
				cout<<'1';
			else
				cout<<'0';
		}
		else
		{
			if(c[i].a<zx)
				cout<<'1';
			else
				cout<<'0';
		}
	}
	return 0;
}
