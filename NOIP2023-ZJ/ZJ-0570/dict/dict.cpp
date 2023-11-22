#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=3005,INF=0x3f3f3f3f;
int n,m,a[N],minn;
int num[N][205];
char str[N][N];
string tmax[N],tmin[N];
namespace sub1
{
	inline void S1()
	{
		printf("1");
	}
}
namespace sub2
{
	inline void S2()
	{
		int t=0;
		for(int i=1;i<=n;i++)
			if(int(str[i][1])==minn)
				t++;
		if(t>1) t=0;
		for(int i=1;i<=n;i++)
			if(int(str[i][1])==minn)
				a[i]=t;
		for(int i=1;i<=n;i++) printf("%d",a[i]);
	}
}
namespace sub3
{
	inline void S3()
	{
		for(int i=1;i<=n;i++)
		{
			string s1=tmin[i];
			bool flag=true;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(s1>=tmax[j])
				{
					flag=false;
					break;
				}
			}
			if(flag) a[i]=1;
		}
		for(int i=1;i<=n;i++) printf("%d",a[i]);
	}
}
inline void init()
{
	n=read(),m=read();
	minn=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>str[i][j];
			minn=min(minn,int(str[i][j]));
			num[i][int(str[i][j])]++;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=int('z');j>=int('a');j--)
			for(int k=1;k<=num[i][j];k++)
				tmax[i]+=char(j);
		for(int j=int('a');j<=int('z');j++)
			for(int k=1;k<=num[i][j];k++)
				tmin[i]+=char(j);
	}
}
inline void work()
{
	if(n==1) sub1::S1();
	else if(m==1) sub2::S2();
	else sub3::S3();
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	init();
	work();
	return 0;
}
