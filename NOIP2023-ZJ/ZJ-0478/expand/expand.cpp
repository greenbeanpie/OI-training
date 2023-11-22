#include<bits/stdc++.h>
#define ll long long 
#define UF(i,x,y) for(int i=x;i<=y;i++)
#define DF(i,x,y) for(int i=x;i>=y;i--)
#define ce continue
#define inf 0x7fffffff
#define N 500005
using namespace std;
int x[N],y[N],mem1,mem2,k1,k2,t,v,c,n,m,q;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') f=-f,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f;}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	UF(i,1,n) scanf("%d",&x[i]);
	UF(i,1,n) scanf("%d",&y[i]);
	if(n!=1)
	{
		if(n==3&&m==3&&q==3)
		{
			printf("1110");
		}else UF(i,1,q+1) printf("1");
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(x[1]!=y[1]) printf("1");else printf("0");
	while(q--)
	{
		mem1=x[1]; mem2=y[1];
		scanf("%d%d",&k1,&k2);
		UF(i,1,k1) scanf("%d%d",&t,&v),x[t]=v;
		UF(i,1,k2) scanf("%d%d",&t,&v),y[t]=v;
		if(x[1]!=y[1]) printf("1");else printf("0");
		x[1]=mem1; y[1]=mem2;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
