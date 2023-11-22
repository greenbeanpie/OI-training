#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=3005;
int n,m;
char str[N],s[N],t[N];
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
#endif
#endif
	scanf("%d%d",&n,&m);
	F(i,0,n)
	{
		scanf("%s",str);
		s[i]='z';t[i]='a';
		F(j,0,m)s[i]=min(s[i],str[j]),t[i]=max(t[i],str[j]);
	}
	F(i,0,n)
	{
		bool ok=true;
		F(j,0,n)if(j!=i)ok=ok&&t[j]>s[i];
		printf("%d",(int)ok);
	}
	puts("");
	return 0;
}
