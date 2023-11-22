#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
int a[500005],b[500005];
void work1()
{
#define c a
#define d b
	if(c[n]<d[m]){cout<<0;return;}
	int mxpl=1;
	for(int x=1;x<=n;x++)
	if(c[x]>c[mxpl])mxpl=x;
	int mx=0;
	for(int x=1;x<=m;x++)
	mx=max(mx,d[x]);
	if(mx>=c[mxpl]){cout<<0;return;}
	vector<pair<int,int>>pr;
	pr.emplace_back(c[1],c[1]);
	for(int x=2;x<=mxpl;x++)
	if(c[x]>pr.back().first)pr.emplace_back(c[x],c[x]);
	else pr.back().second=min(pr.back().second,c[x]);
	int now=0;
	for(int x=1;x<=m;x++)
	{
		if(pr[now].second>d[x])
		{
			now++;
			x--;
			if(now==pr.size())break;
			continue;
		}
		if(pr[now].first<=d[x]){cout<<0;return;}
	}
	if(now!=pr.size()){cout<<0;return;}
	pr.clear();
	pr.emplace_back(c[n],c[n]);
	for(int x=n;x>=mxpl;x--)
	if(c[x]>pr.back().first)pr.emplace_back(c[x],c[x]);
	else pr.back().second=min(pr.back().second,c[x]);
	now=0;
	for(int x=m;x>=1;x--)
	{
		if(pr[now].second>d[x])
		{
			now++;
			x++;
			if(now==pr.size())break;
			continue;
		}
		if(pr[now].first<=d[x]){cout<<0;return;}
	}
	if(now!=pr.size()){cout<<0;return;}
	cout<<1;
#undef c
#undef d
}
void work2()
{
#define c b
#define d a
	if(c[n]<d[m]){cout<<0;return;}
	int mxpl=1;
	for(int x=1;x<=n;x++)
	if(c[x]>c[mxpl])mxpl=x;
	int mx=0;
	for(int x=1;x<=m;x++)
	mx=max(mx,d[x]);
	if(mx>=c[mxpl]){cout<<0;return;}
	vector<pair<int,int>>pr;
	pr.emplace_back(c[1],c[1]);
	for(int x=2;x<=mxpl;x++)
	if(c[x]>pr.back().first)pr.emplace_back(c[x],c[x]);
	else pr.back().second=min(pr.back().second,c[x]);
	int now=0;
	for(int x=1;x<=m;x++)
	{
		if(pr[now].second>d[x])
		{
			now++;
			x--;
			if(now==pr.size())break;
			continue;
		}
		if(pr[now].first<=d[x]){cout<<0;return;}
	}
	if(now!=pr.size()){cout<<0;return;}
	pr.clear();
	pr.emplace_back(c[n],c[n]);
	for(int x=n;x>=mxpl;x--)
	if(c[x]>pr.back().first)pr.emplace_back(c[x],c[x]);
	else pr.back().second=min(pr.back().second,c[x]);
	now=0;
	for(int x=m;x>=1;x--)
	{
		if(pr[now].second>d[x])
		{
			now++;
			x++;
			if(now==pr.size())break;
			continue;
		}
		if(pr[now].first<=d[x]){cout<<0;return;}
	}
	if(now!=pr.size()){cout<<0;return;}
	cout<<1;
#undef c
#undef d
}
void solve()
{
	if(a[1]==b[1]||a[n]==b[m]){cout<<0;return;}
	if(a[1]>b[1])work1();
	else {swap(n,m);work2();swap(n,m);}
}
int main()
{
#ifndef LOCAL
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,q;
	cin>>c>>n>>m>>q;
	for(int x=1;x<=n;x++)
	cin>>a[x];
	for(int x=1;x<=m;x++)
	cin>>b[x];
	solve();
	while(q--)
	{
		int kx,ky;
		cin>>kx>>ky;
		vector<pair<int,int>>va,vb;
		while(kx--)
		{
			int u,v;
			cin>>u>>v;
			va.emplace_back(u,a[u]);
			a[u]=v;
		}
		while(ky--)
		{
			int u,v;
			cin>>u>>v;
			vb.emplace_back(u,b[u]);
			b[u]=v;
		}
		solve();
		while(!va.empty())
		{
			a[va.back().first]=va.back().second;
			va.pop_back();
		}
		while(!vb.empty())
		{
			b[vb.back().first]=vb.back().second;
			vb.pop_back();
		}
	}
}
/*
0 6 1 0
7 6 4 8 4 4 
1
*/
