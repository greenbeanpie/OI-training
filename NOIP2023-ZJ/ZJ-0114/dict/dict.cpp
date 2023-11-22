#include<bits/stdc++.h>
using namespace std;
#define file(s) (freopen(#s".in","r",stdin),freopen(#s".out","w",stdout))
#define ll long long
#define il inline
#define ret return
#define cst const
#define gc getchar
#define pc putchar
il ll rd()
{
	ll res=0;int lab=1;char ch=gc();
	while((ch<'0'||ch>'9')&&(ch^EOF))lab^=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=res*10+(ch&15),ch=gc();
	ret lab?res:-res;
}
il void prt(ll x,char tail='\n')
{
	static int s[71];int t=0;
	if(x<0)pc('-'),x=-x;
	do{s[++t]=x%10;x/=10;}while(x);
	while(t)pc(s[t--]|48);
	if(tail)pc(tail);
}
int n,m,pre[3005],suf[3005];char s[3005][3005];
il bool cmp(int i,int j)
{
	for(int x=m;x>=1;--x)
	{
		if(s[i][x]<s[j][x])ret 1;
		if(s[i][x]>s[j][x])ret 0;
	}
	ret 0;
}//i<j
il bool cmp2(int i,int j)
{
	for(int x=1;x<=m;++x)
	{
		if(s[i][x]<s[j][m+1-x])ret 1;
		if(s[i][x]>s[j][m+1-x])ret 0;
	}
	ret 0;
}
int main()
{
	file(dict);
	n=rd();m=rd();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1),sort(s[i]+1,s[i]+1+m);
	pre[2]=1;suf[n-1]=n;
	for(int i=3;i<=n;++i)
	{
		pre[i]=pre[i-1];
		if(cmp(i-1,pre[i]))pre[i]=i-1;
	}
	for(int i=n-2;i>=1;--i)
	{
		suf[i]=suf[i+1];
		if(cmp(i+1,suf[i]))suf[i]=i+1;
	}
	for(int i=1;i<=n;++i)
	{
		int f=1;
		if(i>1&&!cmp2(i,pre[i]))f=0;
		if(i<n&&!cmp2(i,suf[i]))f=0;
		pc(f|48);
	}
	pc('\n');
	ret 0;
}