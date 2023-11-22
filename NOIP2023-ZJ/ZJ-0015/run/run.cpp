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
struct SGT
{
	ll f[1<<19],g[1<<19];
	void clr(){memset(f,0,sizeof(f)),memset(g,0,sizeof(g));}
	inline void update(int nl,int nr,int l,int r,int x,ll k)
	{
		if(nr<l||r<nl) return ;
		if(l<=nl&&nr<=r)
		{
			f[x]+=k,g[x]+=k;
			return ;
		}
		if(g[x])
			f[x<<1]+=g[x],f[(x<<1)+1]+=g[x],
			g[x<<1]+=g[x],g[(x<<1)+1]+=g[x],g[x]=0;
		int mid=(nl+nr)>>1;
		update(nl,mid,l,r,x<<1,k),
		update(mid+1,nr,l,r,(x<<1)+1,k),
		f[x]=max(f[x<<1],f[(x<<1)+1]);
	}
	inline ll query(int nl,int nr,int l,int r,int x)
	{
		if(nr<l||r<nl) return -1e18;
		if(l<=nl&&nr<=r) return f[x];
		if(g[x])
			f[x<<1]+=g[x],f[(x<<1)+1]+=g[x],
			g[x<<1]+=g[x],g[(x<<1)+1]+=g[x],g[x]=0;
		int mid=(nl+nr)>>1;
		return max(query(nl,mid,l,r,x<<1),
			query(mid+1,nr,l,r,(x<<1)+1));
	}
}T;
int lsh[200003];
int l[100003],r[100003],w[100003];
vector<pair<int,int>> q[200003];
signed main()
{
#ifndef local
	freopen("run.in","r",stdin),
	freopen("run.out","w",stdout);
#endif
	int HaitangSuki=read();
	for(int Case=read(); Case--;)
	{
		int n=read(),m=read(),k=read(),d=read(),L=1;
		lsh[1]=0,T.clr();
		for(int i=1,x,y; i<=m; ++i)
			x=read(),y=read(),w[i]=read(),
			lsh[++L]=l[i]=x-y,lsh[++L]=r[i]=x;
		sort(lsh+1,lsh+L+1),
		L=unique(lsh+1,lsh+L+1)-lsh-1;
		for(int i=1; i<=L; ++i) q[i].clear();
		for(int i=1; i<=m; ++i)
			l[i]=lower_bound(lsh+1,lsh+L+1,l[i])-lsh,
			r[i]=lower_bound(lsh+1,lsh+L+1,r[i])-lsh,
			q[r[i]].push_back({l[i],w[i]});
		ll ans=0;
		for(int i=1,j=1; i<=L; ++i)
		{
			while(lsh[i]-lsh[j]>k) ++j;
			T.update(1,L,i,i,1,ans+1ll*lsh[i]*d);
			for(auto to:q[i])
			{
				int p=to.first,w=to.second;
				T.update(1,L,1,p,1,w);	
			}
			ans=max(ans,T.query(1,L,j,i,1)-1ll*lsh[i]*d);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
//现在是 11:00。
//我通过了四个题的全部大样例。
//我不会两个半小时 AK 了吧。