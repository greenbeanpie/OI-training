#include<bits/stdc++.h>
 using namespace std;
  const int maxn=500100;
  int c,n,m,q,i,j,kx,ky,px,vx,py,vy,r1,r2,f1,f2,x[maxn],y[maxn],a[maxn],b[maxn]; bool f[3010][3010];
  int main() {
  	 freopen("expand.in","r",stdin);
  	 freopen("expand.out","w",stdout);
  	  scanf("%d%d%d%d",&c,&n,&m,&q);
  	   for (i=1;i<=n;i++) scanf("%d",&x[i]); for (i=1;i<=n;i++) a[i]=x[i];
  	   for (j=1;j<=m;j++) scanf("%d",&y[j]); for (j=1;j<=m;j++) b[j]=y[j];
  	     for (i=1;i<=n;i++)
  	      for (j=1;j<=m;j++) 
  	       f[i][j]=false;
  	        if (x[1]==y[1]) printf("0");
  	        if (x[1]<y[1]) {
  	    	 f[1][1]=true;
  	    	  for (i=1;i<=n;i++)
  	    	   for (j=1;j<=m;j++) {
  	    	   	   if (f[i][j]==true&&x[i]<y[j+1]) f[i][j+1]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]<y[j]) f[i+1][j]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]<y[j+1]) f[i+1][j+1]=true;
				 }
		     if (f[n][m]==true) printf("1"); else printf("0");		 
		    }
		    if (x[1]>y[1]) {
		     f[1][1]=true;
  	    	  for (i=1;i<=n;i++)
  	    	   for (j=1;j<=m;j++) {
  	    	   	   if (f[i][j]==true&&x[i]>y[j+1]) f[i][j+1]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]>y[j]) f[i+1][j]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]>y[j+1]) f[i+1][j+1]=true;
				 }
		     if (f[n][m]==true) printf("1"); else printf("0");
			}
	     while (q--) {
	     	scanf("%d%d",&kx,&ky);
	     	 for (i=1;i<=n;i++) x[i]=a[i]; for (j=1;j<=m;j++) y[j]=b[j];
	     	 for (i=1;i<=kx;i++) { scanf("%d%d",&px,&vx); x[px]=vx; }
	     	 for (i=1;i<=ky;i++) { scanf("%d%d",&py,&vy); y[py]=vy; }
	     	  for (i=1;i<=n;i++)
  	           for (j=1;j<=m;j++) 
  	            f[i][j]=false;
  	        if (x[1]==y[1]) printf("0");
  	        if (x[1]<y[1]) {
  	    	 f[1][1]=true;
  	    	  for (i=1;i<=n;i++)
  	    	   for (j=1;j<=m;j++) {
  	    	   	   if (f[i][j]==true&&x[i]<y[j+1]) f[i][j+1]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]<y[j]) f[i+1][j]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]<y[j+1]) f[i+1][j+1]=true;
				 }
		     if (f[n][m]==true) printf("1"); else printf("0");	 
		    }
		    if (x[1]>y[1]) {
		     f[1][1]=true;
  	    	  for (i=1;i<=n;i++)
  	    	   for (j=1;j<=m;j++) {
  	    	   	   if (f[i][j]==true&&x[i]>y[j+1]) f[i][j+1]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]>y[j]) f[i+1][j]=true;
  	    	   	   if (f[i][j]==true&&x[i+1]>y[j+1]) f[i+1][j+1]=true;
				 }
		     if (f[n][m]==true) printf("1"); else printf("0");
			}
		 }
  	return 0;
  }