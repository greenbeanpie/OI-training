#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct Node
{
	 long long x,y,z;
}me[1000010];
/*long long max(long long x,long long y)
{
	 return (x>y?:x,y);
}*/
bool cmp(Node x,Node y)
{
	 return x.x==y.x?:(x.x-x.y)>(y.x-y.y),x.x<y.x;
}
long long c,t,n,m,k,d,x,y,z,maxt,maxn,jl,f[1000010],jl1,xl;
 int main()
 {
 	 freopen("run.in","r",stdin);
 	 freopen("run.out","w",stdout);
 	 scanf("%lld%lld",&c,&t);
 	while (t--)
 	{
 		memset(f,0,sizeof(f));
 	  scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
 	  for (int i=1;i<=m;i++)
 	  {
 	    scanf("%lld%lld%lld",&x,&y,&z);
 	    me[i].x=x;
 	    me[i].y=y;
 	    me[i].z=z;
 	  }
 	  me[0].x=-1;
 	  sort(me+1,me+1+m,cmp);
 	  /*for (int i=1;i<=m;i++)
 	  printf("%d\n",me[i].x-me[i].y);*/
 	  maxt=0;
 	 /* for (int i=1;i<=m&&me[i].x<=n;i++)
 	  if ((me[i].y<=k)&&(me[i].x-me[i].y>=0))
 	  {
 	  	jl=-me[i].y*d;
 	  	jl1=i;
 	    for (int j=i;j>=1;j--)
 	    {
 	      if (me[i].x-me[i].y>=me[j].x)
 	      break;
 	      if ((me[i].x-me[i].y<=me[j].x-me[j].y))
 	      jl+=me[j].z;
 	      jl1=j;
 	    }
 	   while ((me[i].x-me[i].y<=me[jl1].x)&&(jl1>0))
 	    jl1--;
 	    for (int j=jl1;j>=0;j--)
 	    if (f[j]+jl>f[i])
 	    f[i]=f[j]+jl;
 	    if (maxt<f[i])
 	    maxt=f[i];
      }*/
 	 /* maxt=0;
 	  maxn=0;
 	  for (int i=1;i<=m;i++)
 	  if (me[i].x>n)
 	  continue;
	   else
 	   if ((me[i].x)/(k+1)*k+(me[i].x)%(k+1)>=(me[i].y))
 	    {
 	    	if (maxt<0)
 	    	printf("%lld\n",maxt);
 	    	if (maxn-(me[i].y)*d+me[i].z>maxt)
 	    	maxt=maxn-(me[i].y)*d+me[i].z;
            maxn+=me[i].z;
		}
		printf("%lld\n",maxt);*/
		for (int i=1;i<=m;i++)
		if (me[i].y<=k)
		{
		  jl=-me[i].y*d;
		  for (int j=i;j>=1;j--)
		     if (me[j].x-me[j].y>=me[i].x-me[i].y)
		     jl+=me[j].z;
		 for (int j=0;j<=i;j++)
		   if (me[j].x<me[i].x-me[i].y)
		   {
		   	  if (jl+f[j]>f[i])
		   	  f[i]=jl+f[j];
		   }
		   else
		   break;
		  /*for (int j=i-1;j>=1;j--)
		    if ((me[i].x-me[j].x+1<=k)&&(me[j].x<me[i].x))
		      if (((me[i].z+f[j]+(me[j].x-me[i].x-1)*d)>maxt)&&(me[i].x<=n))
		      maxt=me[i].z+f[j]+(me[j].x-me[i].x)*d;*/
		   /*for (int j=i-1;j>=1;j--)
		    if ((me[i].x-(me[j].x-me[j].y+1)+1)<=k)
		    if (f[j]+((me[j].x-me[i].x)*d+me[i].z)>f[i])
		    f[i]=f[j]+((me[j].x-me[i].x)*d+me[i].z);*/
	       if ((me[i].x<=n)&&(f[i]>maxt))
	       maxt=f[i];
	    }
		printf("%lld\n",maxt);
     }
 	  fclose(stdin);
 	  fclose(stdout);
 	  return 0;
 }