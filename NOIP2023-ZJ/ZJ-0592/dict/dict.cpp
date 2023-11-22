#include<bits/stdc++.h>
using namespace std;
int read()
{
	int f=1,s=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c-'0');c=getchar();}
	return s*f;
}
struct node
{
	string x;
	string mi;
	string ma;
}a[3010];
int t[30];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	char c;
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		memset(t,0,sizeof(t));
		for(int j=1;j<=m;j++)
		{
			c=getchar();
			while(c=='\n')c=getchar();
			t[c-'a']++;
		}
		for(int j=0;j<=25;j++)
		{
			for(int k=1;k<=t[j];k++)
			{
				a[i].mi+=char(j+'a');
			}
		}
		for(int j=25;j>=0;j--)
		{
			for(int k=1;k<=t[j];k++)
			{
				a[i].ma+=char(j+'a');
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(a[i].mi>=a[j].ma)
			{
				flag=0;break;
			}
		}
		cout<<flag;
	}
	cout<<endl;
	return 0;
}

