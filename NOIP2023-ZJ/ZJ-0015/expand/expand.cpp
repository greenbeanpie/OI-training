//Author: dXqwq with Haitang0520
//You are my irreplaceable treasure.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
	int x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c&15),c=getchar();
	return x;
}
int ra[500003],rb[500003];
int a[500003],b[500003];
int stk[500003];
signed main()
{
#ifndef local
	freopen("expand.in","r",stdin),
	freopen("expand.out","w",stdout);
#endif
	int HaitangSuki=read();
	int n=read(),m=read(),q=read();
	for(int i=1; i<=n; ++i) ra[i]=read();
	for(int i=1; i<=m; ++i) rb[i]=read();
	for(int Case=0; Case<=q; ++Case)
	{
		for(int i=1; i<=n; ++i) a[i]=ra[i];
		for(int i=1; i<=m; ++i) b[i]=rb[i];
		int X=0,Y=0;
		if(Case) X=read(),Y=read();
		for(int x; X--;) x=read(),a[x]=read();
		for(int x; Y--;) x=read(),b[x]=read();
		if(a[1]==b[1]){putchar('0');continue;}
		int sw=(a[1]<b[1]);
		if(sw) swap(a,b),swap(n,m);
		int left=0,right=0,top=0,ln=1;
		for(int i=2; i<=n; ++i)
			if(a[i]<=a[ln]) ln=i;
		stk[0]=0;
		for(int i=1,x=0,mn=a[1]; i<=ln; ++i)
		{
			mn=min(mn,a[i]);
			while(x<m&&a[i]>b[x+1])
			{
				++x;
				while(top&&b[x]<=b[stk[top]]) --top;
				stk[++top]=x;
			}
			while(top&&b[stk[top]]>=mn) --top;
			if(top==0) break;
		}
		left=stk[top],stk[top=0]=m+1;
		for(int i=n,x=m+1,mn=a[n]; i>=ln; --i)
		{
			mn=min(mn,a[i]);
			while(x>1&&a[i]>b[x-1])
			{
				--x;
				while(top&&b[x]<=b[stk[top]]) --top;
				stk[++top]=x;
			}
			while(top&&b[stk[top]]>=mn) --top;
			if(top==0) break;
		}
		right=stk[top],printf("%d",left>=right);
		// cerr<<ln<<" "<<left<<" "<<right<<endl;
		if(sw) swap(n,m);
	}
	puts("");
    return 0;
}