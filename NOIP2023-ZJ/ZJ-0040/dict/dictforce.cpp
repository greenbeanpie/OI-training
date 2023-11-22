#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=505;
bool cmp(const char *s,const char *t)
{
	for(;*s;++s,++t)if(*s!=*t)return *s<*t;
	return false;
}
int n,m;
char s[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	F(i,0,n)scanf("%s",s[i]);
	F(i,0,n)
	{
		F(j,0,n)if(j!=i)sort(s[j],s[j]+m,greater<char>());
		sort(s[i],s[i]+m);
		bool ok=true;
		F(j,0,n)if(j!=i)ok=ok&&cmp(s[i],s[j]);
		printf("%d",(int)ok);
	}
	puts("");
	return 0;
}
