//Author: dXqwq with Haitang0520
//You are my irreplaceable treasure.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
	int x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c&15),c=getchar();
	return x;
}
int a[100003],b[100003],c[100003],sv;
bool ft,ff,fu;
vector<pair<int,int>> e[100003];
inline void dfs(int x)
{
	++sv;
	if(!a[x])
	{
		int val=c[x]^b[x];
		if(val==1) ft=1;
		else if(val==0) ff=1;
		else fu=1;
	}
	for(auto to:e[x])
	{
		int y=to.first;
		int z=to.second;
		if(c[y]==-1) c[y]=c[x]^z,dfs(y);
		else if(c[y]!=(c[x]^z)) fu=1;
	}
}
signed main()
{
#ifndef local
	freopen("tribool.in","r",stdin),
	freopen("tribool.out","w",stdout);
#endif
	int HaitangSuki=read();
	for(int T=read(); T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) a[i]=i,b[i]=0,c[i]=-1,e[i].clear();
		for(int i=1; i<=m; ++i)
		{
			char c=getchar();
			while(c!='+'&&c!='-'&&c!='T'&&c!='F'&&c!='U') c=getchar();
			int x=read(),y;
			if(c=='+') y=read(),a[x]=a[y],b[x]=b[y];
			else if(c=='-') y=read(),a[x]=a[y],b[x]=max(-1,b[y]^1);
			else if(c=='T') a[x]=0,b[x]=1;
			else if(c=='F') a[x]=0,b[x]=0;
			else a[x]=0,b[x]=-1;
		}
		for(int i=1; i<=n; ++i)
			if(a[i])
				e[i].push_back({a[i],b[i]}),
				e[a[i]].push_back({i,b[i]});
		int sum=0;
		for(int i=1; i<=n; ++i)
			if(c[i]==-1)
			{
				sv=0,ft=ff=fu=0,c[i]=0,dfs(i);
				if((ft&&ff)||fu) sum+=sv;
			}
		printf("%d\n",sum);
	}
	return 0;
}