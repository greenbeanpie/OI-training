#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,x,y,z,f[1050][1050],ans,t,mos,d,sum;
struct node
{
	long long val,wei,day;
}v[100050];
long long min(long long x,long long y)
{
	if (x<=y) return x; else return y;
}
long long max(long long x,long long y)
{
	if (x>=y) return x; else return y;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&x,&t);
	while (t--)
	  {
	  	memset(f,-63,sizeof(f));
	  	scanf("%lld%lld%lld%lld",&n,&m,&mos,&d);
	  	for (i=1;i<=m;i++)
	  	  scanf("%lld%lld%lld",&v[i].day,&v[i].wei,&v[i].val);
	  	f[0][0]=0;
	  	for (i=1;i<=n;i++)
	  	  for (j=0;j<=min(i,mos);j++)
	  	    if (j==0)
			  for (k=1;k<=min(i-1,mos);k++) 
	  	    	f[i][j]=max(f[i-1][k],f[i][j]);
			else
	  	      {
	  	    	sum=0;
	  	    	for (k=1;k<=m;k++)
	  	    	  if (v[k].day==i&&v[k].wei<=j) sum+=v[k].val;
	  	    	for (k=0;k<=j;k++)
	  	    	  f[i][j]=max(f[i-k][j-k]-d*k+sum,f[i][j]);
			  }  
		ans=-2174836470000000;
		for (i=0;i<=min(n,mos);i++)
		  ans=max(ans,f[n][i]);
		printf("%lld\n",ans);
	  }
	return 0;
}