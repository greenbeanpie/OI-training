#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=3005;
int n,m,id,b[N];
string s[N],t[N];
inline bool cmp(int u,int v){return t[u]<t[v];}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if (n==1)return 0*puts("1");
	F(i,1,n)
	{
		cin>>s[i];sort(s[i].begin(),s[i].end());
		t[i]=s[i];reverse(t[i].begin(),t[i].end());
		b[i]=i;
	}
	sort(b+1,b+1+n,cmp);
	F(i,1,n)
	{
		if (b[1]==i)id=2;else id=1;
		if (s[i]<t[b[id]])cout<<1;else cout<<0;
	}
	return 0;
}
