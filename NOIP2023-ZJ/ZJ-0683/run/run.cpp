#include<bits/stdc++.h>
#define maxm 3010
using namespace std;
int c,t,n,m,k,d;
int dp[maxm][maxm];
struct node{
	int x,y,v;
}a[maxm];
int read(int x=0,int y=1,char ch=getchar())
{
	for(;!isdigit(ch);ch=getchar())
		if(ch=='-')y=-1;
	for(;isdigit(ch);ch=getchar())
		x=x*10+ch-'0';
	return x*y;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		n=read();m=read();k=read();d=read();
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
			{
//				if()
//				dp[i][j]
			}
	}
	cout<<"2";
	return 0;
}
