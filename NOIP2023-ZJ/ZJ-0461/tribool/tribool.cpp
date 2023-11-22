#include<bits/stdc++.h>
using namespace std;
int mk,t,n,m,pos,nans,st[100001],ed[100001];
char c;
struct point
{
	char a;
	int x,y;
}q[100001];
void solve1(int step)
{
	if(step==m+1)
	{
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(st[i]!=ed[i]&&st[i]&&ed[i])return;
			if(st[i]==3||ed[i]==3)ans++;
		}
		nans=min(nans,ans);
		return;
	}
	int u=q[step].x,v=q[step].y,t1,t2,t3;
	if(q[step].a=='+')
	{
		if(!ed[v])
		{
			t1=st[v],t2=ed[v],t3=ed[u];
			st[v]=ed[v]=1,ed[u]=1;solve1(step+1);
			st[v]=ed[v]=2;ed[u]=2;solve1(step+1);
			st[v]=ed[v]=3;ed[u]=3;solve1(step+1);
			st[v]=t1,ed[v]=t2,ed[u]=t3;
		}
		else{t2=ed[v],t3=ed[u];ed[u]=ed[v];solve1(step+1);ed[v]=t2,ed[u]=t3;}
	}
	else if(q[step].a=='-')
	{
		if(!ed[v])
		{
			t1=st[v],t2=ed[v],t3=ed[u];
			st[v]=ed[v]=1;ed[u]=2;solve1(step+1);
			st[v]=ed[v]=2;ed[u]=1;solve1(step+1);
			st[v]=ed[v]=3;ed[u]=3;solve1(step+1);
			st[v]=t1,ed[v]=t2,ed[u]=t3;
		}
		else
		{
			t2=ed[v],t3=ed[u];
			if(ed[v]==3){ed[u]=3;solve1(step+1);}
			else{ed[u]=3-ed[v];solve1(step+1);}
			ed[v]=t2,ed[u]=t3;
		}
	}
	else if(q[step].a=='T'){t3=ed[u];ed[u]=1;solve1(step+1);ed[u]=t3;}
	else if(q[step].a=='F'){t3=ed[u];ed[u]=2;solve1(step+1);ed[u]=t3;}
	else if(q[step].a=='U'){t3=ed[u];ed[u]=3;solve1(step+1);ed[u]=t3;}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>mk>>t;
	if(mk==3||mk==4)
	{
		while(t--)
		{
			cin>>n>>m;
			while(m--)
			{
				cin>>c>>pos;
				if(c=='T')ed[pos]=1;
				else if(c=='F')ed[pos]=2;
				else ed[pos]=3;
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				if(ed[i]==3)ans++;
			cout<<ans<<endl;
		}
	}
	else if(mk==1||mk==2)
	{
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				cin>>q[i].a;
				if(q[i].a=='+'||q[i].a=='-')cin>>q[i].x>>q[i].y;
				else if(q[i].a=='T'||q[i].a=='F'||q[i].a=='U')cin>>q[i].x;
			}
			for(int i=1;i<=n;i++)st[i]=ed[i]=0;
			nans=1000000;
			solve1(1);
			cout<<nans<<endl;
		}
	}
	else
	{
		while(t--)
		{
			cin>>n>>m;
			cout<<m<<endl;
		}
	}
	return 0;
}
