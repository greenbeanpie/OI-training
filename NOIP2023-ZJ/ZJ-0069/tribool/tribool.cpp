#include<bits/stdc++.h>
using namespace std;
long long c,t,i,j,k,n,m,b,d,e[100001],f,g,a[100001],u[100001],v[100001],w[11]={1,3,9,27,81,243,729,2187,6561,19683,59049};
char s[100001][2];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==1||c==2)
	{
		for(k=1;k<=t;k=k+1)
		{
			scanf("%lld%lld",&n,&m);d=n;
			for(i=1;i<=m;i=i+1)
			{
				scanf("%s",s[i]);
				if(s[i][0]=='+'||s[i][0]=='-')scanf("%lld%lld",&u[i],&v[i]);
				else scanf("%lld",&u[i]);
			}
			for(j=0;j<w[n];j=j+1)
			{
				f=j;g=1;b=0;
				for(i=1;i<=n;i=i+1)
				{
					a[i]=f%3+1;
					e[i]=f%3+1;
					f=f/3;if(a[i]==3)b=b+1;
				}
				for(i=1;i<=m;i=i+1)
				{
					if(s[i][0]=='T')a[u[i]]=1;
					if(s[i][0]=='F')a[u[i]]=2;
					if(s[i][0]=='U')a[u[i]]=3;
					if(s[i][0]=='+')a[u[i]]=a[v[i]];
					if(s[i][0]=='-')
					{
						if(a[v[i]]==3)a[u[i]]=3;
						else a[u[i]]=3-a[v[i]];
					}
				}
				for(i=1;i<=n;i=i+1)if(a[i]!=e[i])g=0;
				if(g==1&&b<d)d=b;
			}
			printf("%lld\n",d);
		}
		return 0;
	}
	if(c==3||c==4||c==5||c==6)
	{
		for(k=1;k<=t;k=k+1)
		{
			scanf("%lld%lld",&n,&m);b=0;
			for(i=1;i<=n;i=i+1)a[i]=1;
			for(i=1;i<=m;i=i+1)
			{
				scanf("%s",s[i]);
				if(s[i][0]=='+'||s[i][0]=='-')scanf("%lld%lld",&u[i],&v[i]);
				else scanf("%lld",&u[i]);
			}
			while(1)
			{
				d=b;b=0;
				for(i=1;i<=m;i=i+1)
				{
					if(s[i][0]=='T')a[u[i]]=1;
					if(s[i][0]=='F')a[u[i]]=2;
					if(s[i][0]=='U')a[u[i]]=3;
					if(s[i][0]=='+')a[u[i]]=a[v[i]];
					if(s[i][0]=='-')
					{
						if(a[v[i]]==3)a[u[i]]=3;
						else a[u[i]]=3-a[v[i]];
					}
				}
				for(i=1;i<=n;i=i+1)if(a[i]==3)b=b+1;
				if(b==d)break;
			}
			printf("%lld\n",b);
		}
		return 0;
	}
	if(c==7||c==8||c==9||c==10)
	{
		for(k=1;k<=t;k=k+1)
		{
			scanf("%lld%lld",&n,&m);
			for(i=1;i<=m;i=i+1)
			{
				scanf("%s",s[i]);
				if(s[i][0]=='+'||s[i][0]=='-')scanf("%lld%lld",&u[i],&v[i]);
				else scanf("%lld",&u[i]);
			}
			printf("%lld\n",n);
		}
		return 0;
	}
	return 0;
}
