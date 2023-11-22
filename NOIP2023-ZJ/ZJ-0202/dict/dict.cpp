#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=3114;
const ll B1=131,B2=13331,MOD1=1e9+9,MOD2=1e9+7;
int n,m;
char s[M][M];
char a[M][M],b[M][M];
ll h1[M][M][2],h2[M][M][2];
void calc(int i,int j,char s[M])
{
	for(int k=1;k<=m;k++)
	{
		h1[i][k][j]=(h1[i][k-1][j]*B1%MOD1+(s[k]-'a'))%MOD1;
		h2[i][k][j]=(h2[i][k-1][j]*B2%MOD2+(s[k]-'a'))%MOD2;
	}
}
int calc(int i,int s1,int j,int s2,char a[M],char b[M])
{
	int L=1,R=m,pos=m+1;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if((h1[i][mid][s1]!=h1[j][mid][s2])||(h2[i][mid][s1]!=h2[j][mid][s2])) pos=mid,R=mid-1;
		else L=mid+1;
	}
	return pos;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=b[i][j]=s[i][j];
		sort(a[i]+1,a[i]+1+m),sort(b[i]+1,b[i]+1+m,greater<char>());
	}
	for(int i=1;i<=n;i++) calc(i,0,a[i]),calc(i,1,b[i]);
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			int p=calc(i,0,j,1,a[i],b[j]);
			if(p==m+1||a[i][p]>b[j][p])
				{flag=false;break;}
		}
		cout<<flag;
	}
	return 0;
}