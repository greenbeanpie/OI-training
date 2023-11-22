#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
string s;
int n,m,ans[N];

struct node{
	int s[30];
	inline bool operator<(const node& x)const{
		int minn=-1,maxn=-1;
		for(int i=0;i<=25;i++)
			if(s[i]!=0){minn=i;break;}
		for(int i=25;i>=0;i--)
			if(x.s[i]!=0){maxn=i;break;}
		if(minn<maxn) return true;
		return false;
	}
}a[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++)
			a[i].s[s[j]-'a']++;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(i!=j && !(a[i]<a[j]))
			{ans[i]=1;break;}
	for(int i=1;i<=n;i++)
		cout<<(!ans[i]);
    return 0;
}