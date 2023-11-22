#include<bits/stdc++.h>
using namespace std;
constexpr int N=3030;
int n,m,cnt[32];
string s[N];
struct node
{
	string t;
	int id;
	inline bool operator <(const node &b)const
	{
		return t<b.t;
	}
}a[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==1)
	{
		cout<<'1'<<'\n';
		return 0;
	}
	for(int i=1; i<=n; ++i)
	{
		cin>>s[i];
		for(int j=1; j<=26; ++j)
			cnt[j]=0;
		for(int j=0; j<m; ++j)
			++cnt[(s[i][j]^=96)];
		int now=0;
		for(int j=26; j; --j)
			while(cnt[j])
				s[i][now++]=j^96,--cnt[j];
		a[i].t=s[i],a[i].id=i;
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; ++i)
	{
		for(int l=0,r=m-1; l<r; ++l,--r)
			swap(s[i][l],s[i][r]);
		int fir=((a[1].id==i)? 2:1);
		if(s[i]<a[fir].t)
			cout<<'1';
		else
			cout<<'0';
	}
	cout<<'\n';
	return 0;
}