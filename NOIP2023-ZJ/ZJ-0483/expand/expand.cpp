#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,q,a[N],b[N],na[N],nb[N];
bool flg;
void dfs(int l,int r)
{
//	cout<<"::"<<l<<" "<<r<<endl;
	if(l>n)
	{
		if(r==m)
		{
			flg=1;
		}
		return;
	}
	if(na[n]>nb[m]&&na[l]<=nb[r]&&r!=0)
	{
		r++;
	}
	if(na[n]<nb[m]&&na[l]>=nb[r]&&r!=0)
	{
		r++;
	}
	if(r==0)
	{
		r++;
	}
	for(int i=r;i<=m;i++)
	{
		if(na[n]>nb[m]&&na[l]<=nb[i])
		{
			break;
		}
		if(na[n]<nb[m]&&na[l]>=nb[i])
		{
			break;
		}
		dfs(l+1,i);
		if(flg)
		{
			return;
		}
	}
}
void solve()
{
	if(na[n]==nb[m])
	{
		cout<<0;
		return;
	}
	flg=0;
	dfs(1,0);
	cout<<flg;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x,y,t1,t2;
	cin>>x>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		na[i]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		nb[i]=b[i];
	}
	solve();
	while(q--)
	{
		for(int i=1;i<=n;i++)
		{
			na[i]=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			nb[i]=b[i];
		}
		cin>>t1>>t2;
//		cout<<":::"<<t1<<endl;
		for(int i=1;i<=t1;i++)
		{
			cin>>x>>y;
			na[x]=y;
		}
		for(int i=1;i<=t2;i++)
		{
			cin>>x>>y;
			nb[x]=y;
		}
		solve();
	}
}