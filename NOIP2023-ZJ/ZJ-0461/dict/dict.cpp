#include<bits/stdc++.h>
using namespace std;
int n,m,posmin=0;
char s[3001][3001];
bool f[3001],flag;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)sort(s[i]+1,s[i]+1+m);
	for(int i=1;i<=m;i++)s[0][i]='z';
	for(int i=1;i<=n;i++)
	{
		flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j||f[j])continue;
			for(int p=1,q=m;p<=m;p++,q--)
			{
				if(s[i][p]<s[j][q])break;
				else if(s[i][p]>s[j][q]){flag=0;break;}
			}
			if(!flag)break;
		}
		if(flag)printf("1");
		else printf("0");
		for(int p=m,q=m;p>=1;p--,q--)
		{
			if(s[posmin][p]<s[i][q]){f[i]=1;break;}
			else if(s[posmin][p]>s[i][q]){f[posmin]=1;posmin=i;break;}
		}
	}
	return 0;
}
