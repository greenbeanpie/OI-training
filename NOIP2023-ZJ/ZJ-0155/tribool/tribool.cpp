#include <bits/stdc++.h>
using namespace std;
int GI()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
char GC()
{
	char ch=getchar();
	while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-')ch=getchar();
	return ch;
}
const int N=1e5+5;
int h[N],f[N],from[N<<1];
bitset<N<<1> U;
int find(int u)
{
	if(u!=from[u])from[u]=find(from[u]);
	return from[u];
}
void merge(int u,int v)
{
	int ru=find(u),rv=find(v);
	from[ru]=rv;
	return;
}
void solve()
{
	U.reset();
	int n=GI(),m=GI(),ans=0;
	for(int i=1;i<=n;i++)h[i]=i,f[i]=0;
	while(m--)
	{
		char v=GC();
		if(!isalpha(v))
		{
			int x=GI(),y=GI();
			h[x]=h[y],f[x]=f[y]^(v=='-');
		}
		else
		{
			int x=GI();
			if(v=='T')h[x]=n+1;
			if(v=='F')h[x]=n+2;
			if(v=='U')h[x]=n+3;
			f[x]=0;
		}
	}
	int k=n+3;
	for(int i=1;i<=2*k;i++)from[i]=i;
	merge(n+3,n+3+k);
	merge(n+1,n+2+k),merge(n+1+k,n+2);
	for(int i=1;i<=n;i++)
	{
		if(f[i])merge(i,h[i]+k),merge(i+k,h[i]);
		else merge(i,h[i]),merge(i+k,h[i]+k);
	}
	for(int i=1;i<=n;i++)if(find(i)==find(i+k))U[find(i)]=true;
	for(int i=1;i<=n;i++)ans+=(U[find(i)]||U[find(i+k)]);
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	GI();
	for(int T=GI();T--;)solve();
	return 0;
}