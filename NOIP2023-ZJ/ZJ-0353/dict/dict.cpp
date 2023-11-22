#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5,M=35;
string s[N];
int f[M],g[N],h[M];
int n,m;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int minn=30,maxn=0;
		for(int j=0;j<m;j++)
		{
			minn=min(minn,s[i][j]-'a');
			maxn=max(maxn,s[i][j]-'a');
		}
		f[maxn]++;
		h[maxn]++;
		g[i]=minn;
	}
	for(int i=29;i>=0;i--)
		f[i]+=f[i+1];
	for(int i=1;i<=n;i++)
	{
//		cout<<g[i]<<endl;
//		puts("--");
		int vis=1;
		for(int j=0;j<=g[i];j++)
			if(j==g[i] && h[j]>1 || j!=g[i] && h[j])
				vis=0;
		printf("%d",vis);
	}
}
