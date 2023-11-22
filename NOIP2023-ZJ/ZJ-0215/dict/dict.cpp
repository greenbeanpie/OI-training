#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[3002];
int a[3002][27];
int mha,mhb;//min1 2 back
bool hz(int x,int y)
{
	for(int i=25;i>=0;i--)
	{
		if(a[x][i]!=a[y][i])
		{
			return a[x][i]<a[y][i];
		}
	}
	return 0;
}
bool qhz(int x,int y)
{
	int la=0,lb=25;
	while(a[x][la]==0)
	{
		la++;
	}
	while(a[y][lb]==0)
	{
		lb--;
	}
	return la<lb;
	
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<26;j++)
		{
			a[i][j]=0;
		}
		for(int j=0;j<m;j++)
		{
			a[i][s[j]-'a']++;
		}
	}
	if(n==1)
	{
		printf("1");
		return 0;
	}
	mha=1;
	for(int i=2;i<=n;i++)
	{
		if(hz(i,mha))
		{
			mha=i;
		}
	}
	mhb=1;
	if(mha==1)
	{
		mhb=2;
	}
	for(int i=2;i<=n;i++)
	{
		if(i!=mha&&hz(i,mhb))
		{
			mhb=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==mha)
		{
			printf("%d",qhz(i,mhb));
		}
		else
		{
			printf("%d",qhz(i,mha));
		}
	}
	return 0;
}
