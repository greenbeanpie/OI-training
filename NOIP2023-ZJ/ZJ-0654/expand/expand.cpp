#include <bits/stdc++.h>
using namespace std;
int arx[500005],ary[500005];
int c,n,m,q;
//10 1   2  54 5 545 5
//1  151 23 23 1 2   4
bool check()
{
	if(arx[1]==ary[1]) return false;
	if(arx[n]==ary[m]) return false;
	if((arx[1]-ary[1])*(arx[n]-ary[m])<=0) return false;
//	bool f1=true;
//	for(int i=1;i<m;i++)
//	{
//		if(arx[1]<ary[i])
//			f1=false;
//	}
//	bool f2=true;
//	for(int i=2;i<=n;i++)
//	{
//		if(ary[m]>arx[i])
//			f2=false;
//	}
//	bool f3=true;
//	for(int i=1;i<n;i++)
//	{
//		if(ary[1]<arx[i])
//			f3=false;
//	}
//	bool f4=true;
//	for(int i=2;i<=m;i++)
//	{
//		if(arx[m]>ary[i])
//			f4=false;
//	}
//	return (f1&&f2)||(f3&&f4);
	return true;
}
vector<pair<int,int>> mx,my;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
//	printf("%d\n",__LINE__);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&arx[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&ary[i]);
//	printf("%d\n",__LINE__);
	if(check())
		printf("1");
	else
		printf("0");
//	printf("%d\n",__LINE__);
	for(int i=1;i<=q;i++)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
//		printf("l:%d\n",__LINE__);
		for(int j=1;j<=kx;j++)
		{
			int t,v;
			scanf("%d%d",&t,&v);
			mx.push_back({t,arx[t]});
			arx[t]=v;
		}
//		printf("l:%d\n",__LINE__);
		for(int j=1;j<=ky;j++)
		{
			int t,v;
			scanf("%d%d",&t,&v);
			my.push_back({t,ary[t]});
			ary[t]=v;
		}
//		printf("l:%d\n",__LINE__);
		if(check())
			printf("1");
		else
			printf("0");
//		printf("l:%d\n",__LINE__);
		for(int j=0;j<kx;j++)
		{
			int t=mx[j].first,v=mx[j].second;
			arx[t]=v;
		}
//		printf("l:%d\n",__LINE__);
		for(int j=0;j<ky;j++)
		{
			int t=my[j].first,v=my[j].second;
			ary[t]=v;
		}
//		printf("l:%d\n",__LINE__);
		if(!mx.empty())
			mx.clear();
		if(!my.empty())
			my.clear();
	}
	puts("");
	fclose(stdin);
	fclose(stdout);
}
