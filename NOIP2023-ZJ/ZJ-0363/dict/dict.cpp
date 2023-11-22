#include<bits/stdc++.h>
#define DEBUG puts("en en shui ye mei kan de qi ni");
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
int n,m,ans[3010],tmp1[30],tmp2[30],ma[3010],mi[3010];
string s[3010];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();//zhu yi n m de daxiao guan xi
	memset(ma,0x80,sizeof(ma));
	memset(mi,0x3f,sizeof(mi));
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=" "+s[i];
		for(int j=1;j<=m;j++)
		{
			ma[i]=max(ma[i],(int)s[i][j]);
			mi[i]=min(mi[i],(int)s[i][j]);
		}
		ans[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(ma[j]<=mi[i])ans[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		print(ans[i]);
	}
	return 0;
}