#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2010][2010],n,m,q;
int c1[2010],c2[2010];
int x1[2010],x2[2010],*s=x1,*t=x2;
int chk(){
	if((s[1]<t[1])!=(s[n]<t[m]))return 0;
	int a=n,b=m;if(s[1]<t[1])swap(s,t),swap(a,b);
	for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++)
			if(s[i]>t[j]&&dp[i-1][j-1])dp[i][j]=1;
		for(int j=1;j<=b;j++)
			if(s[i]>t[j]&&dp[i-1][j])dp[i][j]=1;
		for(int j=1;j<=b;j++)
			if(s[i]>t[j]&&dp[i][j-1])dp[i][j]=1;
	}
	return dp[a][b];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&n,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&c1[i]),s[i]=c1[i];
	for(int i=1;i<=m;i++)scanf("%d",&c2[i]),t[i]=c2[i];
	cout<<chk();
	for(int a,b;q--;){
		scanf("%d%d",&a,&b);
		for(int i=1;i<=n;i++)s[i]=c1[i];
		for(int i=1;i<=m;i++)t[i]=c2[i];
		for(int i=1,c,d;i<=a;i++)scanf("%d%d",&c,&d),s[c]=d;
		for(int i=1,c,d;i<=b;i++)scanf("%d%d",&c,&d),t[c]=d;
		cout<<chk();
	}
	return 0;
}
