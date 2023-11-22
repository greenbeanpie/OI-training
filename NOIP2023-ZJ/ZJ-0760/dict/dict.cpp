#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
//#define int long long
#define CI const int
using namespace std;
const int N=3e3+5,inf=1e9;
int T,n,m;
int read(int& v)
{
	char ch;int f=1;
	for(ch='*';!isdigit(ch) && ch!='-';ch=getchar());
	if(ch=='-')  f=-1,ch=getchar();
	for(v=0;isdigit(ch);v=v*10+ch-'0',ch=getchar());
	v*=f;
return v;
}
struct node
{
	char a[N];
	bool operator<(const node& x)const
	{
		for(int i=1;i<=m;i++)
			if(a[i]<x.a[i])  return 1;
			else if(a[i]>x.a[i])  return 0;
		return 0;
	}
	bool operator==(const node& x)const
	{
		for(int i=1;i<=m;i++)
			if(a[i]!=x.a[i])  return 0;
		return 1;
	}
	bool operator>=(const node& x)const
	{
		for(int i=1;i<=m;i++)
			if(a[i]>x.a[i])  return 1;
			else if(a[i]<x.a[i])  return 0;
		return 1;
	}
}Mis,Mas,s[N],mas[N];
void solve()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)  scanf("%s",s[i].a+1);
	for(int i=1;i<=n;i++)
	{
		sort(s[i].a+1,s[i].a+1+m);
		reverse(s[i].a+1,s[i].a+1+m);
		mas[i]=s[i];
	}
	sort(mas+1,mas+1+n);
	for(int i=1;i<=n;i++)
	{
		sort(s[i].a+1,s[i].a+1+m);    Mis=s[i];
		reverse(s[i].a+1,s[i].a+1+m); Mas=s[i];
		int pos=1+(Mas==mas[1]);
		if(Mis>=mas[pos])  putchar('0');
		else  putchar('1');
	}
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	/*read(T);
	while(T--)*/  solve();
return 0;
}