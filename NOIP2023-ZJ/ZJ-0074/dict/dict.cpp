#include<bits/stdc++.h>
using namespace std;
const int NUM=3005;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
int n,m,mx[NUM],mn[NUM];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	char s[NUM];
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		mx[i]=-1,mn[i]=27;
		for(int j=0;j<m;j++)
		{
			mx[i]=max(mx[i],s[j]-'a');
			mn[i]=min(mn[i],s[j]-'a');
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(mn[i]>=mx[j]) flag=false;
		}
		if(flag) printf("1");
		else printf("0");
	}
}