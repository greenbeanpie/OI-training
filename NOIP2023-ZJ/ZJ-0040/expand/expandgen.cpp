#include<cstdio>
#include<chrono>
#include<random>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=500005;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rnd() (int)(rnd()&(~0u>>1))
int n=rnd()%(rnd()&7?500:5000)+1,m=rnd()%(rnd()&7?500:5000)+1,q=rnd()%10+1,v=rnd()%(rnd()&7?1000:10000)+1,s=rnd()%v;
int main()
{
	printf("0 %d %d %d\n",n,m,q);
	F(i,0,n)printf("%d ",rnd()%v);
	puts("");
	F(j,0,m)printf("%d ",rnd()%v+s);
	puts("");
	while(q--)
	{
		int kx=rnd()%80,ky=rnd()%80;
		printf("%d %d\n",kx,ky);
		F(i,0,kx)printf("%d %d\n",rnd()%n+1,rnd()%v);
		F(i,0,ky)printf("%d %d\n",rnd()%m+1,rnd()%v+s);
	}
	return 0;
}
