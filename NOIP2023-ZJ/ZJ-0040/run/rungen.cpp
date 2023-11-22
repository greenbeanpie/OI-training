#include<cstdio>
#include<chrono>
#include<random>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=25,V=1000000000;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rnd() (int)(rnd()&(~0u>>1))
int tt=rnd()%200+1,n,m,k,d;
int main()
{
	printf("0 %d\n",tt);
	while(tt--)
	{
		n=rnd()%(rnd()&7?14:18)+1;
		m=rnd()%60+1;
		k=rnd()%n+1;
		d=rnd()%(rnd()&7?V/5:V)+1;
		printf("%d %d %d %d\n",n,m,k,d);
		F(i,0,m)
		{
			int l=rnd()%n,r=rnd()%n;
			if(l>r)swap(l,r);
			printf("%d %d %d\n",r+1,r-l+1,rnd()%V+1);
		}
	}
	return 0;
}
