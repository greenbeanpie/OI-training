#include<bits/stdc++.h>
int n,m,q,flag,subt,a0[500005],b0[500005],a[500005],b[500005];
int dp[205][205];
int solvel(int s)
{
//	printf("L %d\n",s);
	if (s==0) return 1;
	int ka=0,kb=0,mn=1000000000,mx=-1000000000;
	for (int i=1;i<=s;i++) mn=std::min(mn,a[i]),mx=std::max(mx,b[i]);
	for (int i=1;i<=s;i++) if (a[i]==mn) ka=i;
	for (int i=1;i<=s;i++) if (b[i]==mx) kb=i;
	if (mx<=mn) return 0;
	return solvel(std::min(ka-1,kb-1));
}
int solver(int s)
{
//	printf("R %d\n",s);
	if (s==0) return 1;
	int ka=0,kb=0,mn=1000000000,mx=-1000000000;
	for (int i=n-s+1;i<=n;i++) mn=std::min(mn,a[i]);
	for (int i=m-s+1;i<=m;i++) mx=std::max(mx,b[i]);
	for (int i=n-s+1;i<=n;i++) if (a[i]==mn) ka=i;
	for (int i=m-s+1;i<=m;i++) if (b[i]==mx) kb=i;
	if (mx<=mn) return 0;
	return solver(std::max(n-ka,m-kb));
}
int ask()
{
	//a<b
	int mxa=-1000000000,mxb=-1000000000;
	for (int i=1;i<=n;i++) mxa=std::max(mxa,a[i]);
	for (int i=1;i<=m;i++) mxb=std::max(mxb,b[i]);
	if (mxa>mxb)
	{
		for (int i=1;i<=std::max(n,m);i++) std::swap(a[i],b[i]);
		std::swap(mxa,mxb);
		std::swap(n,m);
		flag=1;
	}
	/*
	int ka=0,kb=0,mn=1000000000,mx=-1000000000;
	for (int i=1;i<=n;i++) mn=std::min(mn,a[i]),mx=std::max(mx,b[i]);
	for (int i=1;i<=n;i++) if (a[i]==mn) ka=i;
	for (int i=1;i<=m;i++) if (b[i]==mx) kb=i;
	if (mx<=mn) return 0;
	return solvel(std::min(ka-1,kb-1))&&solver(std::min(n-ka,m-kb));
	*/
//	for (int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
//	for (int i=1;i<=m;i++) printf("%d ",b[i]);puts("");
	for (int i=0;i<=std::max(n,m);i++) for (int j=0;j<=std::max(n,m);j++) dp[i][j]=0;
	dp[0][0]=1;
	if (a[1]<b[1]) dp[1][1]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (i>1&&a[i]<b[j]) dp[i][j]=dp[i][j]||dp[i-1][j];
			if (j>1&&a[i]<b[j]) dp[i][j]=dp[i][j]||dp[i][j-1];
			if (i>1&&j>1&&a[i]<b[j]) dp[i][j]=dp[i][j]||dp[i-1][j-1];
		}
	return dp[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&subt,&n,&m,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a0[i]),a[i]=a0[i];
	for (int i=1;i<=m;i++) scanf("%d",&b0[i]),b[i]=b0[i];
	printf("%d",ask());
	if (flag) std::swap(n,m),flag=0;
	while (q--)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for (int i=1;i<=n;i++) a[i]=a0[i];
		for (int i=1;i<=m;i++) b[i]=b0[i];
		for (int i=1;i<=kx;i++){int id,v;scanf("%d%d",&id,&v);a[id]=v;}
		for (int i=1;i<=ky;i++){int id,v;scanf("%d%d",&id,&v);b[id]=v;}
		printf("%d",ask());
		if (flag) std::swap(n,m),flag=0;
	}
	puts("");
	return 0;
}