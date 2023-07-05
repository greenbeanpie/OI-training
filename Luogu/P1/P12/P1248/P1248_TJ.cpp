#include<bits/stdc++.h>
using namespace std;
struct number
{
	int num,ind;
	bool sign;
	bool operator<(const number& ano)const
	{
		return num<ano.num;
	}
}p[2001];
int a[1001],b[1001],s[1001];
bool vis[1001];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("P1248.in", "r", stdin);
	freopen("P1248_TJ.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[i].num=a[i];
		p[i].ind=i;
		p[i].sign=true;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		p[i+n].num=b[i];
		p[i+n].ind=i;
		p[i+n].sign=false;
	}
	sort(p+1,p+2*n+1);
	int l=1,r=n;
	for(int i=1;i<=2*n;i++)
	{
		if(vis[p[i].ind])
			continue;
		vis[p[i].ind]=true;
		if(p[i].sign)
			s[l++]=p[i].ind;
		else
			s[r--]=p[i].ind;
		if(l>r)
			break;
	}
	int ta=0,tb=0;
	for(int i=1;i<=n;i++)
	{
		ta+=a[s[i]];
		tb=max(tb,ta);
		tb+=b[s[i]];
	}
	printf("%d\n",tb);
	for(int i=1;i<=n;i++)
		printf("%d ",s[i]);
	return 0;
}
