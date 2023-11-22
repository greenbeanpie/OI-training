#include<bits/stdc++.h>
using namespace std;
struct node{
	char v;
	int x,y;
}stc[100001];
char a[100001],b[100001];
int n,m,mn;
char _(char o)
{
	switch(o)
	{
		case 'T':return 'F';break;
		case 'F':return 'T';break;
		case 'U':return 'U';break;
	}
	return 0;
}
void dfs(int p,int t)
{
	if(p==n+1)
	{
		for(int i=1;i<=m;i++)
		{
			if(isupper(stc[i].v))
			a[stc[i].x]=stc[i].v;
			else if(stc[i].v=='+')
			a[stc[i].x]=a[stc[i].y];
			else if(stc[i].v=='-')
			a[stc[i].x]=_(a[stc[i].y]);
			else exit(1);
		}
		for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
		return;
		mn=min(mn,t);
		return;
	}
	a[p]=b[p]='T';
	dfs(p+1,t);
	a[p]=b[p]='F';
	dfs(p+1,t);
	a[p]=b[p]='U';
	dfs(p+1,t+1);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t,i;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=m;i++)
		{
			cin>>stc[i].v;
			if(isupper(stc[i].v))
			cin>>stc[i].x;
			else
			cin>>stc[i].x>>stc[i].y;
		}
		mn=n;dfs(1,0);
		printf("%d\n",mn);
	}
	return 0;
}
