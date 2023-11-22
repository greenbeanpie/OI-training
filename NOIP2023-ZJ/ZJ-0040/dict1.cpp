#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=3005,S=26;
int n,m,id[2*N],sid[N],tid[N];
char s[N][N],t[N][N],*str[2*N];
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
		scanf("%s",s[i]);
		sort(s[i],s[i]+m);
		F(j,0,m)t[i][j]=s[i][m-1-j];
		str[2*i]=s[i];
		str[2*i+1]=t[i];
		id[2*i]=2*i;id[2*i+1]=2*i+1;
	}
	sort(id,id+2*n,[](int u,int v){return strcmp(str[u],str[v])<0;});
	for(int i=0,j=0;i<2*n;++i)
	{
		if(i&&strcmp(str[id[i-1]],str[id[i]])!=0)++j;
		if(id[i]&1)tid[id[i]>>1]=j;
		else sid[id[i]>>1]=j;
	}
	F(i,0,n)
	{
		bool ok=true;
		F(j,0,n)if(j!=i)ok=ok&&tid[j]>sid[i];
		printf("%d",(int)ok);
	}
	puts("");
	return 0;
}
