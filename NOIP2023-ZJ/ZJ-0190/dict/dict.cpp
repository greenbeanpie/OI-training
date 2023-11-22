#include<bits/stdc++.h>
using namespace std;
char c[3005][3005],d[3005][3005];
bool cmp(char x,char y){return x<y;}
int judge(int x,int y)
{
	int k=1;
	while(d[x][k]==d[y][k]) k++;
	return d[x][k]>d[y][k];
}
int get(int x,int y)
{
	int k=1;
	while(c[x][k]==d[y][k]) k++;
	return c[x][k]<d[y][k];
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		getchar();
		for(j=1;j<=m;j++)
			c[i][j]=getchar();
		sort(c[i]+1,c[i]+m+1,cmp);
		for(j=1;j<=m;j++)
			d[i][j]=c[i][m-j+1];
	}
	int mini=1,minc=0;
	for(i=2;i<=n;i++)
	{
		if(judge(mini,i)) minc=mini,mini=i;
	}
	int flag;
	for(i=1;i<=n;i++)
	{
		if(i==mini) flag=get(i,minc);
		else flag=get(i,mini);
		putchar(flag+48);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
