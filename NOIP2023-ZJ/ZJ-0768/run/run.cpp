#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int ans,c,t,n,m,k,d,x[N],y[N],v[N],w[N],fla;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run,out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	for (int k=1;k<=t;k++)
	{
		ans=0;
		cin >> n >>m >> k >> d;
		for (int i=1;i<=m;i++) 
		{
			cin >> x[i] >> y[i] >> v[i],w[i]=v[i]-d*y[i];
			if (y[i]>k) w[i]=0;
//			else for (int j=x[i]-y[i]+1;j<=x[i];j++) c[j]+=1;
		}
		fla=1;
		for (int i=1;i<=m;i++) if (w[i]>0) fla=0;
		if (fla) cout << 0 << endl;
		else
		{
			for (int i=1;i<=m;i++) if (w[i]>0) ans+=w[i];
		}
		cout << ans << endl;
	}
	return 0;
}
