#include<cstdio>
#include<chrono>
#include<random>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=25;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rnd() (int)(rnd()&(~0u>>1))
int tt=rnd()%200+1,n,m;
int main()
{
	printf("0 %d\n",tt);
	while(tt--)
	{
		n=rnd()%(rnd()&7?10:14)+1;m=rnd()%(rnd()&7?16:30)+1;
		printf("%d %d\n",n,m);
		F(i,0,m)
		{
			char op="TFU+-"[rnd()%5];
			if(op=='+'||op=='-')printf("%c %d %d\n",op,rnd()%n+1,rnd()%n+1);
			else printf("%c %d\n",op,rnd()%n+1);
		}
	}
	return 0;
}
