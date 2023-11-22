#include<bits/stdc++.h>
using namespace std;
int n,m,minp;
int c[3010][3010];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	char cc=getchar();
	minp=n+1;
	for(int i=1;i<=m;i++)
	c[n+1][i]=27;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		c[i][j]=getchar()-'a';
		cc=getchar();
		sort(c[i]+1,c[i]+m+1);
		//cout<<c[i][1]<<endl;
		for(int j=m;j>=1;j--)
		if(c[i][j]<c[minp][j])
		{
			minp=i;
			break;
		}
		else if(c[i][j]>c[minp][j]) break;
//		if(minp!=i)
//		{
//			for(int j=1;j<=m;j++)
//			if(c[i][j]<c[i][minpp])
//			{
//				minpp=i;
//				break;
//			}
//			else if(c[i][j]>c[i][minpp]) break;
//		}
	}
//	cout<<minp<<endl;
	for(int i=1;i<=n;i++)
	{
		int f=0,p=minp;
		if(p==i)
		{
			printf("1");
			continue;
		}
//		if(minp==i) p=minpp;
//		else p=minp;
		for(int j=1;j<=m;j++)
		if(c[i][j]>c[p][m-j+1]) 
		{
			//cout<<c[i][j]<<" "<<c[p][m-j+1]<<endl;
			break;
		}
		else if(c[i][j]<c[p][m-j+1]) 
		{
			f=1;
			break;
		}
		printf("%d",f);
	}
	cout<<endl;
	return 0;
}