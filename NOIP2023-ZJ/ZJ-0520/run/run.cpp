#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5,K=1e3+5;

inline int get()
{
	register char ch;
	while((ch=getchar())<'0'||ch>'9');
	register int res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=(res<<3)+(res<<1)+ch-'0';
	return res;
}

inline long long getll()
{
	register char ch;
	while((ch=getchar())<'0'||ch>'9');
	register long long res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=(res<<3)+(res<<1)+ch-'0';
	return res;
}

long long add[N][N];
long long f[N][K];

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c=get(),t=get();
	while(t--)
	{
		memset(add,0,sizeof(add));
		memset(f,0,sizeof(f));
		int n=get(),m=get(),k=get();
		long long d=getll();
		for(int i=1;i<=m;i++)
			add[get()][get()]=getll();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(add[i][j]==0)add[i][j]=add[i][j-1];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
				f[i][0]=max(f[i][0],f[i-1][j]);
			for(int j=1;j<=min(k,i);j++)
				f[i][j]=f[i-1][j-1]-d+add[i][j];
		}
		long long ans=0;
		for(int i=0;i<=k;i++)
			ans=max(ans,f[n][i]);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
