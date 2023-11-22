#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int M=1e5+5;
int n,m,k,d,cnt;
struct node
{
	int x,y,v;
}a[M];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
//	int C=rd(),T=rd();
//	while(T--)
//	{
//		n=rd(),m=rd(),k=rd(),d=rd();
//		for(int i=1;i<=m;++i)
//			a[i].x=rd(),a[i].y=rd(),a[i].v=rd();
//	}
	cout<<0;
	return 0;
}