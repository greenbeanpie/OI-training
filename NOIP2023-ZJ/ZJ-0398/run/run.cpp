#include<bits/stdc++.h>
 using namespace std;
  const int maxn=3010;
 int c,T,n,m,k,d,x,y,v,i,j;long long ans,f[maxn][maxn],val[maxn][maxn];
  int main() {
  	 freopen("run.in","r",stdin);
  	 freopen("run.out","w",stdout);
  	  scanf("%d%d",&c,&T);
  	   if (c==17||c==18) {
  	   	  while (T--) {
  	   	  	     scanf("%d%d%d%d",&n,&m,&k,&d); ans=0;
  	   	  	      for (i=1;i<=m;i++) {
  	   	  	      	  scanf("%d%d%d",&x,&y,&v);
  	   	  	      	  if (y<=k) ans+=max(0,v-y*d);
				    }  
				   printf("%lld\n",ans); 
			   }
  	   	   return 0;
		 }
  	   while (T--) {
  	   	   scanf("%d%d%d%d",&n,&m,&k,&d); ans=0;
  	   	    for (i=1;i<=n;i++)
  	   	     for (j=0;j<=n;j++)
  	   	      val[i][j]=f[i][j]=0;
  	   	    for (i=1;i<=m;i++) {
  	   	       scanf("%d%d%d",&x,&y,&v);
			   val[x][y]+=v;	 
			 }
			for (i=1;i<=n;i++)
			 for (j=1;j<=n;j++)
			  val[i][j]+=val[i][j-1];
			for (i=1;i<=n;i++) 
			 {
			    for (j=0;j<=k;j++) f[i][0]=max(f[i][0],f[i-1][j]);
				for (j=1;j<=k;j++) f[i][j]=f[i-1][j-1]-d+val[i][j]; 	
			 }  
			for (i=0;i<=k;i++) ans=max(ans,f[n][i]);
			printf("%lld\n",ans); 
		 }
  	return 0;
  }