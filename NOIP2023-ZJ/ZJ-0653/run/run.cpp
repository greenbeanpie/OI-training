#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d,cnt,cnt1,cnt2,ans;
struct name{
	int a,b,c;
}bl[100010];
bool cmp(name x,name y)
{
	return x.a>y.a;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>bl[i].a>>bl[i].b>>bl[i].c;
			if(bl[i].b<=k)
			ans=max(ans,ans-bl[i].b*d+bl[i].c);
		}
		cout<<ans<<endl;
	}
}
