#include<bits/stdc++.h>
using namespace std;
const int N=3009;
char c[N][N],d[N][N];
int n,m,flg,t1=1,t2=2;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		putchar('1');
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i]+1);
		memcpy(d[i],c[i],sizeof(d[i]));
		sort(c[i]+1,c[i]+m+1);
		sort(d[i]+1,d[i]+m+1,greater<char>());
	}
	if(strcmp(d[1]+1,d[2]+1)>0) t2=1,t1=2; 
	for(int i=2;i<=n;i++)
	{
		if(strcmp(d[i]+1,d[t1]+1)<0) t2=t1,t1=i;
		else if(strcmp(d[i]+1,d[t2])<0) t2=i; 
	} 
	for(int i=1;i<=n;i++)
	{
		flg=0;
		if(i!=t1&&strcmp(c[i]+1,d[t1]+1)>=0) flg=1;
		else if(strcmp(c[i]+1,d[t2]+1)>=0) flg=1;
		if(flg) putchar('0');
		else putchar('1');
	}
		
}