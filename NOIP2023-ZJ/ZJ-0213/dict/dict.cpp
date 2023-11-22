#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
int n,m;
vector<string> a,b;
string s,ans,minx;
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)
	{
		cin>>s;
		sort(s.begin(),s.end());
		a.push_back(s);
		reverse(s.begin(),s.end());
		b.push_back(s);
	}
	minx=b[0];
	for(string &i:b)if(i<minx)minx=i;
	for(string &i:a)
		if(i<=minx)ans+='1';
		else ans+='0';
	cout<<ans;
}