#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n,m,tmp;
int pre[maxn],sur[maxn],num[maxn][30];
char str[maxn][maxn];
string a,b;
bool check(int x,int y)
{
	for(int i=25;i>=0;i--)
		if(num[x][i]!=num[y][i]) return num[x][i]<num[y][i];
	return true;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			num[i][str[i][j]-'a']++;
	num[0]['z'-'a']=3001;
	for(int i=1;i<=n;i++)
	{
		if(check(pre[i-1],i)) pre[i]=pre[i-1];
		else pre[i]=i;
	}
	for(int i=n;i>=1;i--)
	{
		if(check(sur[i+1],i)) sur[i]=sur[i+1];
		else sur[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		a=b="";
		if(check(pre[i-1],sur[i+1])) tmp=pre[i-1];
		else tmp=sur[i+1];
		for(int j=0;j<=25;j++) for(int k=1;k<=num[i][j];k++) a+=(char)('a'+j);
		for(int j=25;j>=0;j--) for(int k=1;k<=num[tmp][j];k++) b+=(char)('a'+j);
		printf("%d",(a<=b));
	}
}
