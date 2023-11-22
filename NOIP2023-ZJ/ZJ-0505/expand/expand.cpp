#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,x,y,z,u,v,w,t,a[500050],b[500050],mina,minb,maxa,maxb,la[500050],lb[500050];
bool flag;
long long max(long long x,long long y)
{
	if (x<=y) return y; else return x;
}
long long min(long long x,long long y)
{
	if (x>=y) return y; else return x;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&x,&n,&m,&t);
	for (i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	for (i=1;i<=m;i++)
	  scanf("%lld",&b[i]);
	for (i=1;i<=n;i++)
	  la[i]=a[i];
	for (i=1;i<=m;i++)
	  lb[i]=b[i];
	t++;
	flag=true;
	while (t--)
	  {
	  	if (flag==false)
	  	  {
	  	  	for (i=1;i<=n;i++)
	  	  	  a[i]=la[i];
	  	  	for (i=1;i<=m;i++)
	  	  	  b[i]=lb[i];
	  	  	scanf("%lld%lld",&x,&y);
	  	  	for (i=1;i<=x;i++)
	  	  	  {
	  	  	  	scanf("%lld%lld",&u,&v);
	  	  	  	a[u]=v;
			  }
			for (i=1;i<=y;i++)
			  {
			  	scanf("%lld%lld",&u,&v);
			  	b[u]=v;
			  }
		  }
		maxa=0;
	    mina=2147483647;
	    for (i=1;i<=n;i++)
	      {
	  	    maxa=max(maxa,a[i]);
		    mina=min(mina,a[i]);
	      }  
	    maxb=0;
	    minb=2147483647;
 	    for (i=1;i<=m;i++)
	      {
	  	    maxb=max(maxb,b[i]);
		    minb=min(minb,b[i]);
	      }
	    if (a[1]==b[1]||a[n]==b[m])
	      {
	         printf("0");
	         flag=false;
			 continue;
	      }
	    if ((a[1]<b[1]&&a[n]>b[m])||(a[1]>b[1]&&a[n]<b[m]))
	      {
	      	printf("0");
	      	flag=false;
	      	continue;
		  }
		if (maxa<=maxb&&mina>=minb)
		  {
		  	printf("0");
		  	flag=false;
		  	continue;
		  }
		if ((a[1]<b[1]||a[n]<b[m])&&mina>=minb)
		  {
		  	printf("0");
		  	flag=false;
		  	continue;
		  }
		if ((a[n]>b[m]||a[1]>b[1])&&maxa<=maxb)
		  {
		  	printf("0");
		  	flag=false;
		  	continue;
		  }
		printf("1");
	  	flag=false;
	  }
	return 0;
}