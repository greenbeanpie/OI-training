#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
void read(int &x)
{
	x=0;
	char ch=getchar();
	while (ch>'9' || ch<'0')
		ch=getchar();
	while (ch>='0' && ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
}
char inalpha()
{
	char ch=getchar();
	while (ch<'a' || ch>'z')
		ch=getchar();
	return ch;
}
int n,m;
string word[3005],mi[3005],mx[3005];
int cnt[3001][26];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	read(n),read(m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			word[i]+=inalpha();
	for (int i=1;i<=n;i++)
		for (int j=0;j<m;j++)
			cnt[i][word[i][j]-'a']++;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++)
			for (int k=0;k<cnt[i][j];k++)
				mi[i]+=char(j+'a');
		for (int j=25;j>=0;j--)
			for (int k=0;k<cnt[i][j];k++)
				mx[i]+=char(j+'a');
	}
	for (int i=1;i<=n;i++)
	{
		bool fl=1;
		for (int j=1;j<=n;j++)
		{
			if (j==i)
				continue ;
			if (mx[j]<=mi[i])
			{
				fl=0;
				break;
			}
		}
		printf("%d",fl);
	}
	return 0;
}