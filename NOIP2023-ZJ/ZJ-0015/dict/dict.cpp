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
char a[3003][3003],b[3003],t[3003];
signed main()
{
#ifndef local
	freopen("dict.in","r",stdin),
	freopen("dict.out","w",stdout);
#endif
	int n=read(),m=read(),cnt=0;
    for(int i=1; i<=m; ++i) b[i]='z';
	for(int i=1; i<=n; ++i)
    {
        scanf("%s",a[i]+1);
        sort(a[i]+1,a[i]+m+1);
		for(int j=1; j<=m; ++j)
            t[j]=a[i][m+1-j];
		int geq=0;
		for(int j=1; j<=m; ++j)
			if(t[j]<b[j]){geq=1;break;}
			else if(t[j]>b[j]){geq=-1;break;}
		if(geq==1)
		{
			cnt=1;
			for(int j=1; j<=m; ++j)
				b[j]=t[j];
		}
		else if(geq==0) ++cnt;
	}
	for(int i=1; i<=n; ++i)
	{
		int ans=0;
		for(int j=1; j<=m; ++j)
			if(a[i][j]<b[j]){ans=1;break;}
			else if(a[i][j]>b[j]){ans=-1;break;}
		if(ans==1) putchar('1');
		else if(ans==-1) putchar('0');
		else if(cnt>1) putchar('0');
		else putchar('1');
	}
	puts("");
	return 0;
}