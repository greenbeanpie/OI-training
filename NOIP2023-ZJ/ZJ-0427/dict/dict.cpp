#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char c1[3010][3010],c[3010][3010],mp[3010];
int n,m,ans1;
bool cmp1(char a,char b)
{
	return a<b;
}
bool cmp2(char a,char b)
{
	return a>b;
}
int bj(char a[3010],char b[3010])
{
	 for (int i=1;i<=m;i++)
	 {
	   if (a[i]<b[i]) return 1;
	   if (a[i]>b[i]) return 0;
     }
     return 2;
}
 int main()
 {
 	 freopen("dict.in","r",stdin);
 	 freopen("dict.out","w",stdout);
 	   scanf("%d%d",&n,&m);
 	    for (int i=1;i<=n;i++)
 	     for (int j=1;j<=m;j++)
 	      while ((c[i][j]<'a')||(c[i][j]>'z'))
 	       c[i][j]=getchar(),c1[i][j]=c[i][j];
 	    for (int i=1;i<=m;i++)
 	     mp[i]='z';
 	    for (int i=1;i<=n;i++)
 	    {
 	     sort(c[i]+1,c[i]+1+m,cmp1);
 	     sort(c1[i]+1,c1[i]+1+m,cmp2);
 	     if (bj(c1[i],mp)==1)
 	     {
 	     	ans1=0;
 	        for (int j=1;j<=m;j++)
			  mp[j]=c1[i][j];
		 }
		 else
	     if (bj(c1[i],mp)==2)
 	     	ans1=1;
 	    }
 	for (int i=1;i<=n;i++)
 	 if (bj(c[i],mp)==1)
 	  printf("1");
 	 else
 	 if ((bj(c[i],mp)==2)&&(!ans1))
 	  printf("1");
 	 else
 	  printf("0");
 	 fclose(stdin);
 	 fclose(stdout);
 	 return 0;
 }