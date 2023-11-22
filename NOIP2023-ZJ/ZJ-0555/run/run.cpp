#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define FOR(i,x,y) for(int i=x;i>=y;i--)
#define int long long

const int N=1e3+4;
int c,t,n,m,k,d;
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	IOS;
	cin>>c>>t;
	int sum,X,Y,V;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		sum=0;
		For(i,1,m)
		{
			cin>>X>>Y>>V;
			if(Y<=k)sum+=max(V-Y*d,0ll);
		}
		cout<<sum<<"\n";
	}

	return 0;
}
