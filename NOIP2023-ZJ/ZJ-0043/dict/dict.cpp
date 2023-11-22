#include<iostream>
#include<cstdio>
using namespace std;
const int N=3010;
int n,m;
char s[N];
int A[2][N];
int a[N][30];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[i][s[j]-'a'+1]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)
			if(a[i][j]){A[0][i]=j;break;}
		for(int j=26;j>=1;j--)
			if(a[i][j]){A[1][i]=j;break;}
	}
	for(int i=1;i<=n;i++)
	{
		int fl=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(A[0][i]>=A[1][j]) fl=0;
		}
		printf("%d",fl);
	}
	return 0;
}