#include <bits/stdc++.h>
const int N=3005;
using namespace std;
int n,m;
string s[N],t[N];
int id;
string Min;
int ans[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		t[i]=s[i];
		reverse(s[i].begin(),s[i].end());
	}
//	for(int i=1;i<=n;i++)cout<<t[i]<<' '<<s[i]<<'\n';
	Min=s[1];id=1;
	for(int i=1;i<=n;i++)
	if(Min>s[i])Min=s[i],id=i;
	for(int i=1;i<=n;i++)
	if(i!=id&&t[i]<Min)ans[i]=1;
	for(int i=1;i<=n;i++)
	if(i!=id&&t[id]>=s[i])goto f;
	ans[id]=1;
	f:;
	for(int i=1;i<=n;i++)cout<<ans[i];
}
