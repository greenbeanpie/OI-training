#include<cstdio>
#include<chrono>
#include<random>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=3005;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rnd() (int)(rnd()&(~0u>>1))
int n=rnd()%(rnd()&3?5:500)+1,m=rnd()%(rnd()&3?5:500)+1,v=rnd()%(rnd()&1?4:26)+1;
int main()
{
	printf("%d %d\n",n,m);
	F(i,0,n)
	{
		int l=rnd()%v,r=rnd()%v;
		if(l>r)swap(l,r);
		++r;
		F(j,0,m)putchar(rnd()%(r-l)+l+'a');
		puts("");
	}
	return 0;
}
