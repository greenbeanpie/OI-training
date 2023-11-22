#include <bits/stdc++.h>

/*
T#YMS@4
Y@T2L32#
*/

using std::cin;
using std::cout;

const int N=3e3+3;

std::string a[N];
int ans[N];

struct P
{
	std::string s;
	int k,id;
}p[N<<1];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;std::cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		p[i].s=p[i+n].s=a[i];
		std::sort(p[i].s.begin(),p[i].s.end());
		std::sort(p[i+n].s.rbegin(),p[i+n].s.rend());
		p[i].k=0;p[i+n].k=1;
		p[i].id=p[i+n].id=i;
	}
	std::sort(p+1,p+n+n+1,[](const P &p1,const P &p2){return p1.s!=p2.s?p1.s>p2.s:(p1.id==p2.id?p1.k>p2.k:p1.k<p2.k);});
	for(int i=1;i<=n;++i)ans[i]=1;
	for(int i=1,j=0;j<n;++i)
	{
		if(p[i].k)++j;
		else ans[p[i].id]=0;
	}
	for(int i=1;i<=n;++i)cout<<ans[i];
		
	return 0;
}