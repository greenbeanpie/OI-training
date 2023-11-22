#include<bits/stdc++.h>
 using namespace std;
 const int maxn=200010;
  int c,t,n,m,i,j,ans,a[maxn],b[maxn],flag[maxn];char op[maxn],x[maxn],y[maxn];
  void check(int sum) {
  	 bool f=true;
  	 for (int i=1;i<=n;i++) y[i]=x[i];
  	 for (int i=1;i<=m;i++) {
  	 	 if (op[i]=='T') y[a[i]]='T';
  	 	 if (op[i]=='F') y[a[i]]='F';
  	 	 if (op[i]=='U') y[a[i]]='U';
  	 	 if (op[i]=='+') y[a[i]]=y[b[i]];
  	 	 if (op[i]=='-') {
  	 	 	   if (y[b[i]]=='T') y[a[i]]='F';
  	 	 	   else if (y[b[i]]=='F') y[a[i]]='T';
  	 	 	   else if (y[b[i]]=='U') y[a[i]]='U';
			}
	   }
	 for (int i=1;i<=n;i++) if (y[i]!=x[i]) f=false;
	 if (f==true) ans=min(ans,sum);  
  	return;
  }
  void dfs(int cnt,int sum) {
  	 if (sum>=ans) return;
  	 if (cnt>n) check(sum); else {
  	 	 x[cnt]='T';
  	 	 dfs(cnt+1,sum);
  	 	 x[cnt]='F';
  	 	 dfs(cnt+1,sum);
  	 	 x[cnt]='U';
  	 	 dfs(cnt+1,sum+1);
	   }
  	return;
  }
  int main() {
  	 freopen("tribool.in","r",stdin);
  	 freopen("tribool.out","w",stdout);
  	  scanf("%d%d",&c,&t);
  	   if (c==1||c==2) {
  	   	   while (t--) {
  	   	   	  scanf("%d%d",&n,&m); scanf("\n"); ans=1010;
  	   	   	   for (i=1;i<=m;i++) {
  	   	   	     scanf("%c",&op[i]);
				 if (op[i]=='+') scanf("%d%d",&a[i],&b[i]);
				 else if (op[i]=='-') scanf("%d%d",&a[i],&b[i]);
				 else scanf("%d",&a[i]);	
  	   	   	     scanf("\n");
			   } 
			  dfs(1,0);
			  printf("%d\n",ans);
			}
		 }
	  if (c==3||c==4) {
	  	while (t--) {
  	   	   	  scanf("%d%d",&n,&m); scanf("\n"); ans=0;
  	   	   	  for (i=1;i<=n;i++) x[i]=1;
  	   	   	   for (i=1;i<=m;i++) {
  	   	   	     scanf("%c",&op[i]); scanf("%d",&a[i]);	x[a[i]]=op[i];
  	   	   	     scanf("\n");
			   } 
			   for (i=1;i<=n;i++) if (x[i]=='U') ans++;
			  printf("%d\n",ans);
			}
	  }	 
	  if (c==5||c==6) {
	   	while (t--) {
  	   	   	  scanf("%d%d",&n,&m); scanf("\n"); ans=0;
  	   	   	   for (i=1;i<=n;i++) flag[i]=0;
  	   	   	   for (i=1;i<=m;i++) {
  	   	   	     scanf("%c",&op[i]);
				 if (op[i]=='+') scanf("%d%d",&a[i],&b[i]);
				 if (op[i]=='U') scanf("%d",&a[i]);
  	   	   	     scanf("\n");
			   } 
			for (j=1;j<=400;j++)
			 for (i=1;i<=m;i++) {
			 	if (op[i]=='+') flag[a[i]]=flag[b[i]];
				 if (op[i]=='U') flag[a[i]]=1;
			   } 
			   for (i=1;i<=n;i++) ans+=flag[i];
			  printf("%d\n",ans);
			}
	  }
  	return 0;
  }