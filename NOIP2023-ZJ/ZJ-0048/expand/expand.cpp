#include<bits/stdc++.h>
using namespace std;
constexpr int N=500010,inf=0x3f3f3f3f;

int n,m,q;
int a[N],b[N],aa[N],bb[N],c[N],cc,l[N],r[N],f[N][22],g[N][22];

inline int read()
{
	char ch=getchar();
	int ret=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9')
	{
		ret=(ret<<1)+(ret<<3)+(ch^48);
		ch=getchar();
	}
	return ret;
}

inline bool check1()
{
	bb[0]=-1;
	bb[m+1]=inf;
	cc=0;
	c[++cc]=0;
	for (int i=1;i<=m;i++)
	{
//		cout<<i<<endl;
		while (bb[i]<=bb[c[cc]]) cc--;
		f[i][0]=c[cc];
		c[++cc]=i;
	}
	cc=0;
	c[++cc]=m+1;
	for (int i=m;i>=1;i--)
	{
//		cout<<i<<endl;
		while (bb[i]>=bb[c[cc]]) cc--;
		g[i][0]=c[cc];
		c[++cc]=i;
	}
	for (int i=0;i<=19;i++)
	{
		g[m+1][i]=m+1;
	}
//	cout<<"OKOK"<<endl;
	for (int j=1;j<=19;j++)
	{
		for (int i=1;i<=m;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
			g[i][j]=g[g[i][j-1]][j-1];
		}
	}
//	cout<<"OK"<<endl;
	l[0]=r[0]=1;
	for (int i=1;i<=n;i++)
	{
		l[i]=l[i-1];
		while (l[i]<=m&&aa[i]<=bb[l[i]]) l[i]++;
		if (l[i]>r[i-1]+1) return 0;
		r[i]=r[i-1]+1;
		r[i]=min(r[i],m);
		if (aa[i]>bb[r[i]])
		{
			for (int j=19;~j;j--)
			{
				if (aa[i]>bb[g[r[i]][j]])
				{
					r[i]=g[r[i]][j];
				}
			}
//			cout<<r[i]<<endl;
			r[i]=g[r[i]][0]-1;
		}
		else
		{
			for (int j=19;~j;j--)
			{
				if (aa[i]<=bb[f[r[i]][j]])
				{
					r[i]=f[r[i]][j];
				}
			}
			r[i]=f[r[i]][0];
			if (r[i]<l[i]) return 0;
		}
//		cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
	}
	return (r[n]==m);
}

inline bool check2()
{
	aa[0]=-1;
	aa[n+1]=inf;
	cc=0;
	c[++cc]=0;
	for (int i=1;i<=n;i++)
	{
		while (aa[i]<=aa[c[cc]]) cc--;
		f[i][0]=c[cc];
		c[++cc]=i;
	}
	cc=0;
	c[++cc]=n+1;
	for (int i=n;i>=1;i--)
	{
		while (aa[i]>=aa[c[cc]]) cc--;
		g[i][0]=c[cc];
		c[++cc]=i;
	}
	for (int i=0;i<=19;i++)
	{
		g[n+1][i]=n+1;
	}
	for (int j=1;j<=19;j++)
	{
		for (int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
			g[i][j]=g[g[i][j-1]][j-1];
		}
	}
	l[0]=r[0]=1;
	for (int i=1;i<=m;i++)
	{
		l[i]=l[i-1];
		while (l[i]<=n&&bb[i]<=aa[l[i]]) l[i]++;
		/*
		if (l[i]>r[i-1]+1)
		{
			cout<<endl;
			cout<<i<<" "<<l[i-1]<<" "<<l[i]<<" "<<r[i-1]<<endl;
			cout<<bb[i-1]<<" "<<bb[i]<<endl;;
			for (int j=l[i-1];j<=l[i];j++)
			{
				cout<<aa[j]<<" ";
			}
			cout<<endl;
		}*/
		if (l[i]>r[i-1]+1) return 0;
		r[i]=r[i-1]+1;
		r[i]=min(r[i],n);
		if (bb[i]>aa[r[i]])
		{
			for (int j=19;~j;j--)
			{
				if (bb[i]>aa[g[r[i]][j]])
				{
					r[i]=g[r[i]][j];
				}
			}
			r[i]=g[r[i]][0]-1;
		}
		else
		{
			for (int j=19;~j;j--)
			{
				if (bb[i]<=aa[f[r[i]][j]])
				{
					r[i]=f[r[i]][j];
				}
			}
			r[i]=f[r[i]][0];
//			if (r[i]<l[i]) cout<<"@@@@@@@"<<endl;
			if (r[i]<l[i]) return 0;
		}
	}
	return (r[m]==n);
}

inline void solve()
{
	if (aa[1]>bb[1])
	{
//		cout<<"!!!"<<endl;
		if (check1()) printf("1");
		else printf("0");
	}
	else if (aa[1]<bb[1])
	{
//		cout<<"@@@"<<endl;
		if (check2()) printf("1");
		else printf("0");
	}
	else
	{
		printf("0");
	}
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
//	freopen("expand4.in","r",stdin);
//	freopen("in.txt","w",stdout);
//	freopen("out.txt","w",stdout);
	n=read();n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=aa[i]=read();
	}
	for (int i=1;i<=m;i++)
	{
		b[i]=bb[i]=read();
	}
//	cout<<"@@@"<<endl;
	solve();
	for (int i=1;i<=q;i++)
	{
//		cout<<i<<endl;
//		memset(c,0,sizeof c);
//		memset(l,0,sizeof l);
//		memset(r,0,sizeof r);
//		memset(f,0,sizeof f);
//		memset(g,0,sizeof g);
		for (int j=1;j<=n;j++)
		{
			aa[j]=a[j];
		}
		for (int j=1;j<=m;j++)
		{
			bb[j]=b[j];
		}
		int s1=read(),s2=read();
		for (int j=1,x,y;j<=s1;j++)
		{
			x=read(),y=read();
			aa[x]=y;
		}
		for (int j=1,x,y;j<=s2;j++)
		{
			x=read(),y=read();
			bb[x]=y;
		}
		/*
		if (i==5)
		{
			for (int j=1;j<=n;j++)
			{
				cout<<aa[j]<<" ";
			}
			cout<<endl;
			for (int j=1;j<=m;j++)
			{
				cout<<bb[j]<<" ";
			}
			cout<<endl;
		}*/
		/*
		if (i==9)
		{
			cout<<endl;
			for (int i=1;i<=n;i++)
			{
				cout<<aa[i]<<" ";
			}
			cout<<endl;
			for (int i=1;i<=m;i++)
			{
				cout<<bb[i]<<" ";
			}
			cout<<endl;
		}*/
		solve();
	}
	return 0;
}