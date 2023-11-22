#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char s[3001][3001];
char s1[3001][3001];
string ss1[3001];
char s2[3001][3001];
string ss2[3001];

bool cmp(char x,char y)
{
	return x > y;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d %d\n",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j = 1;j <= m;j++)
		{
			s1[i][j] = s[i][j];
			s2[i][j] = s[i][j];
		}
		sort(s1[i]+1,s1[i]+m+1);
		for(int j = 1;j <= m;j++)
		{
			ss1[i] += s1[i][j];
		}
		sort(s2[i]+1,s2[i]+m+1,cmp);
		for(int j = 1;j <= m;j++)
		{
			ss2[i] += s2[i][j];
		}
	}
	string minn1 = "";
	int id1 = 0;
	string minn2 = "";
	int id2 = 0;
	for(int i = 1;i <= n;i++)
	{
		if(id1 == 0||ss2[i] < minn1)
		{
			minn2 = minn1;
			id2 = id1;
			minn1 = ss2[i];
			id1 = i;
		}
		else if(id2 == 0||ss2[i] < minn2)
		{
			minn2 = ss2[i];
			id2 = i;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(id1 == i)
		{
			if(ss1[i] < minn2)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		else
		{
			if(ss1[i] < minn1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
	}
	printf("\n");
	return 0;
}
