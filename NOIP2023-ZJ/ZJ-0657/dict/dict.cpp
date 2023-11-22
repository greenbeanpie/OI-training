#include<bits/stdc++.h>
using namespace std;
const int MAXN=3110;
int n,m,ans[MAXN],bol[MAXN][101];
struct dic
{
	string s;
	int id;
	bool fl;
}a[MAXN],b[MAXN],c[MAXN];
bool cmp(dic u,dic v)
{
	return u.s<v.s;
}
bool check(int now)
{
	string x=b[now].s;
	for(int i=1;i<=n;++i)
	{
		if(i==now) continue;
		if(x>=c[i].s) return 0;
	}
	return 1;
}
void init()
{
	sort(a+1,a+1+n,cmp);
	//ans[a[1].id]=1;//minn=a[1].s;
	int N=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
			++bol[i][a[i].s[j]-'a'];
		for(int j=0;j<=26;++j)
			for(int k=1;k<=bol[i][j];k++)
				b[i].s+=j+'a';
		for(int j=26;j>=0;--j)
			for(int k=1;k<=bol[i][j];k++)
				c[i].s+=j+'a';
		b[i].id=c[i].id=a[i].id;
		b[i].fl=1,c[i].fl=0;
	}
	//sort(b+1,b+1+N,cmp);
	for(int i=1;i<=n;++i)
		ans[a[i].id]=check(i);
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		cin>>a[i].s,a[i].id=i;
	if(n==1)
	{
		printf("1");
		return 0;
	}
	//for(int i=1;i<=n;i++)
	init();
	for(int i=1;i<=n;++i)
		printf("%d",ans[i]);
	return 0;
}
