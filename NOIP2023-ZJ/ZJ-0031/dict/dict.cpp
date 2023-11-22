#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
namespace __Clonoth__
{
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=3010;
int a[Max],f[Max],b[Max],g[Max],buc[26];
int n,m;
signed main()
{
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;++i)
	{
		memset(buc,0,sizeof(buc));
		for(int j=1;j<=m;++j)
			cin>>ch,++buc[ch-'a'];
		for(int j=0;j<26;++j)
			if(buc[j])
			{
				a[i]=j,f[i]=buc[j];
				break;
			}
		for(int j=25;~j;--j)
			if(buc[j])
			{
				b[i]=j,g[i]=buc[j];
				break;
			}
	}
	for(int i=1;i<=n;++i)
	{
		bool flag=true;
		for(int j=1;j<=n&&flag;++j)
		{
			if(i==j)
				continue;
			if(b[j]<=a[i])
				flag=false;
		}
		if(flag)
			cout<<"1";
		else
			cout<<"0";
	}
	cout<<"\n";
	return 0;
}
}
signed main()
{
	freopen("dict.in","r",stdin),freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	__Clonoth__::main();
	return 0;
}
