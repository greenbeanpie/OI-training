#include<bits/stdc++.h>
using namespace std;
int n,m,mn,smn;
char ch[6010][3010];
bool check(int x,int y)
{
	for(int i=1;i<=m;++i)
		if(ch[x][i]!=ch[y][i])
			return (ch[x][i]<ch[y][i]);
	return false;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ch[i]+1);
		sort(ch[i]+1,ch[i]+m+1);
		for(int j=1;j<=m;++j)
			ch[n+i][j]=ch[i][m-j+1];
	}
	if(n==1)
	{
		puts("1");
		return 0;
	}
	mn=2;
	smn=1;
	if(check(n+1,n+2))
		swap(mn,smn);
	for(int i=3;i<=n;++i)
		if(check(n+i,n+mn))
		{
			smn=mn;
			mn=i;
		}
		else
			if(check(n+i,n+smn))
				smn=i;
	for(int i=1;i<=n;++i)
		if(i==mn)
			printf("%d",check(i,n+smn));
		else
			printf("%d",check(i,n+mn));
	puts("");
	return 0;
}
