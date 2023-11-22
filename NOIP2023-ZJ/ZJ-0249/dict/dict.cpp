#include <bits/stdc++.h>
using namespace std;
const int MAXN=3010;
int n,m,a[MAXN][30],b[MAXN],c[MAXN],cmp1,cmp2;
char s[MAXN][MAXN];
int f(int a[],int b[])
{
	for(int i=26;i>=1;i--)
	{
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}
int g(int a[],int b[])
{
	int i=1,j=26;
	while(!a[i]) i++;
	while(!b[j]) j--;
	if(i<j) return -1;
	else if(i>j) return 1;
	else
	{
		int i1=26,j1=1;
		while(!a[i1]) i1--;
		while(!b[j1]) j1++;
		if(i1==i&&j1==j) return 0;
		else return 1;
	} 
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%s",&s[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		a[i][int(s[i][j])-96]++;
	}
	memcpy(b,a[1],4*27),cmp1=1;
	memcpy(c,a[2],4*27),cmp2=2;
	if(f(b,c)==1)
	{
		for(int i=1;i<=26;i++) swap(b[i],c[i]);
		swap(cmp1,cmp2);
	}
	for(int i=3;i<=n;i++)
	{
		if(f(a[i],b)<=0)
		{
			memcpy(c,b,4*27),memcpy(b,a[i],4*27);
			cmp2=cmp1,cmp1=i;
		}
		else if(f(a[i],c)<=0) memcpy(c,a[i],4*27),cmp2=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(cmp1!=i)
		{
			if(g(a[i],b)==-1) printf("1");
			else printf("0");
		}
		else
		{
			if(g(a[i],c)==-1) printf("1");
			else printf("0");
		}
	}
	return 0;
}