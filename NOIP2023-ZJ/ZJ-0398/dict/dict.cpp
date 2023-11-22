#include<bits/stdc++.h>
 using namespace std;
  int n,m,i,j,f,a[20010],b[20010];char c;
  int main() {
  	freopen("dict.in","r",stdin);
  	freopen("dict.out","w",stdout);
  	 scanf("%d%d",&n,&m); c=getchar();
  	  for (i=1;i<=n;i++)
	   { 
	    a[i]=0;b[i]=20000;
  	    for (j=1;j<=m;j++) {
  	   	    c=getchar();
  	   	    a[i]=max(a[i],(int)c);b[i]=min(b[i],(int)c);
		 }
		 c=getchar();
	   }
	  for (i=1;i<=n;i++) {
	  	f=1;
	  	for (j=1;j<=n;j++) {
	  		if (i==j) continue;
	  		if (b[i]>=a[j]) f=0;
		  }
		 printf("%d",f); 
	  } 
  	return 0;
  }