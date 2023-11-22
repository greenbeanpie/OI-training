#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,o,p,ans,fl[1000000],tr[1000000],v[1000000],k[1000000],m[1000000],g;
char s;
int dfs(int x,int k2)
{
	if(k[x]==1&&m[x]^k2==1)
	{
		v[x]=1;
		ans--;
		return 1;
	}
	if(k[x]==1)
	{
		if(v[x]==1)ans--;
		return v[x];
	}
	k[x]=1;
	m[x]=k2;
	if(v[x]==1)return 1;
	if(fl[x]==x)
	{
		v[x]=1;
		return 1;
	}
	if(tr[x]==x)return 0;
	if(fl[x]!=0)
	{
		int t=dfs(fl[x],k2^=1);
		if(t!=0)
		{
			v[x]=1;
			return t+1;
		}
		else return 0;
	}
	if(tr[x]!=0)
	{
		int t=dfs(tr[x],k2);
		if(t!=0)
		{                   
			v[x]=1;
			return t+1;
		}
		else return 0;
	}
	return 0;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>o>>p;
	while(p>0)
	{
		p--;
		ans=0;
		memset(v,0,sizeof(v));
		memset(fl,0,sizeof(fl));
		memset(tr, 0,sizeof(tr));
		memset(k,0,sizeof(k));
		memset(m,0,sizeof(m));
		cin>>a>>b;
		for(int i=1;i<=a;i++)tr[i]=i;
		for(int i=1;i<=b;i++)
		{
			cin>>s;
			if(s=='+')
			{
				cin>>c>>d;
				v[c]=0;
				fl[c]=fl[d];
				tr[c]=tr[d];
			}
			else if(s=='-')
			{
				cin>>c>>d;
				v[c]=0;
				fl[c]=tr[d];
				tr[c]=fl[d];
			}
			else
			{
				cin>>c;
				if(s=='U')v[c]=1;
				fl[c]=0;
				tr[c]=c;
			}
		}
		for(int i=1;i<=a;i++)
		{
			if(k[i]==0)
			ans+=dfs(i,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}