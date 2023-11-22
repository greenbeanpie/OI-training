#include<cstdio>
#include<cstring>
using namespace std;
long long inf;
const long long N=1005;
long long count,t,n,m,k,d,x,y,v;
long long ton[N][N][2],to[N],f[N][N],maxf,maxfo,zz,num;
int main()
{
	inf= (long long)(1024*1024*1024);
	inf= (long long)inf * (long long)inf;
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&count,&t);
while(t--)
{	
	memset(to,0,sizeof(to));
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&v);
		ton[x][to[x]][0]=y;
		ton[x][to[x]][1]=v;
		to[x]++;
	}
	for(int j=k;j>0;j--)
		f[0][j]=-inf;
	f[0][0]=0;
	maxfo=0;
	for(int i=1;i<=n;i++)
	{
		maxf=-inf;
		zz=num=0;
		for(int j=1;j<=k;j++)
		{
			while(to[i] && j>=ton[i][zz][0] && zz<to[i])
			{
				num+=ton[i][zz][1];
				zz++;
			}
			f[i][j]=f[i-1][j-1]-d+num;
			if(f[i][j]>maxf)
				maxf=f[i][j];
		}
		f[i][0]=maxfo;
		if(f[i][0]>maxf)
			maxf=f[i][0];
		maxfo=maxf;
	}
	
//	for(int i=0;i<=5;i++){
//		for(int j=0;j<=k;j++)
//			printf("%lld ",f[i][j]);
//		printf("\n");
//		}
	printf("%lld\n",maxf);
	
}
	fclose(stdin);fclose(stdout);
}

