#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[3001][3001];
char c[3001];
int cnt[27];
void read(int i)
{
	char ch=getchar();
	while(ch>'z'||ch<'a')
	{
		ch=getchar();
	}
	int p=-1;
	while(ch<='z'&&ch>='a')
	{
		s[i][++p]=ch;
		ch=getchar();
	}
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		read(i);
		for(int j=0;j<m;j++)
		{
			cnt[s[i][j]-'a'+1]++;
		}
		int p=-1;
		for(int j=26;j>=1;j--)
		{
			while(cnt[j]>0)
			{
				s[i][++p]=j-1+'a';
				cnt[j]--;
			}
			
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			c[m-j-1]=s[i][j];
		}
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(j!=i)
			{
				if(strcmp(s[j],c)<=0)
				{
					flag=0;
					break;
				}
			}
		}
		printf("%d",flag);
	}
}