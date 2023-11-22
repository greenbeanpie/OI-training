#include<bits/stdc++.h>
using namespace std;
const int N = 3e3+5;
int n,m;
string s[N];
int mn[N];
int mx[N];
int sv[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>s[i],s[i]=' '+s[i];
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		int mxx=0,mnn=27;
		for(j=1;j<=m;j++)
		mxx=max(mxx,s[i][j]-'a'),mnn=min(mnn,s[i][j]-'a');
		mx[i]=mxx,mn[i]=mnn;
		sv[i]=mx[i];
//		vis[s[i][j]-'a']++;
	}
	sort(mx+1,mx+1+n);
	for(i=1;i<=n;i++)
	{
		int mxx=sv[i];
		if(mn[i]<mx[1])
		cout<<1;
		else if(mxx==mn[i])
		{
			if(mn[i]==mx[1]&&mn[i]<mx[2])
			cout<<1;
			else
			cout<<0;
		}
		else
		cout<<0;
	}
}