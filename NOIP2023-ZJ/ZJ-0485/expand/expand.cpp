#include <stdio.h>
int a,b,c,d,e[600000],f[600000],g[600000],h[600000],x[1000000],y[1000000],n,m,o;
void my_ans()
{
	if(e[0]==f[0]){printf("0");return;}
	else if(e[0]>f[0])
	{
		for(int i=0;i<c;i++)g[i]=0;
		for(int i=0;i<c && f[i]<e[0];i++)g[i]=1;
		for(int i=1;i<b;i++)
		{
			for(int j=0;j<c;j++)
			{
				h[j]=e[i]>f[j]?((j>0?h[j-1]:0)|g[j-1]|g[j]):0;
			}
			for(int j=0;j<c;j++)
			{
				g[j]=h[j];h[j]=0;
			}
		}

		printf("%d",g[c-1]);
	}
	else
	{
		for(int i=0;i<c;i++)g[i]=0;
		for(int i=0;i<c && f[i]>e[0];i++)g[i]=1;
		for(int i=1;i<b;i++)
		{
			for(int j=0;j<c;j++)
			{
				h[j]=e[i]<f[j]?((j>0?h[j-1]:0)|g[j-1]|g[j]):0;
			}
			for(int j=0;j<c;j++)
			{
				g[j]=h[j];h[j]=0;
			}
		}
		printf("%d",g[c-1]);
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<b;i++)scanf("%d",&e[i]);
	for(int i=0;i<c;i++)scanf("%d",&f[i]);
	my_ans();
	while(d--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);x[i]--;
			o=e[x[i]];
			e[x[i]]=y[i];
			y[i]=o;
		}
		for(int i=n;i<n+m;i++)
		{
			scanf("%d%d",&x[i],&y[i]);x[i]--;
			o=f[x[i]];
			f[x[i]]=y[i];
			y[i]=o;
		}
		my_ans();
		for(int i=0;i<n;i++)
		{
			e[x[i]]=y[i];
		}
		for(int i=n;i<n+m;i++)
		{
			f[x[i]]=y[i];
		}
	}
	return 0;
}
