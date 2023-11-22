#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9'){x = x*10+ch-48;ch = getchar();}
	return x*f;
}
int x[N],y[N];int bian,n,m,q;
string check()
{
	if(x[1]<y[1]&&x[n]<y[m])return "1";
	if(x[1]>y[1]&&x[n]>y[m])return "1";
	return "0";
}
int ask[N],askv[N];
int ori[N],oriy[N];
int asky[N],askvy[N];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	bian = read(),n = read(),m = read(),q = read();
	for(int i = 1;i<=n;i++)x[i] = read();
	for(int i = 1;i<=m;i++)y[i] = read();
	string ans = "";ans+=check();
	for(int i = 1;i<=q;i++)
	{
		int n1 = read(),n2 = read();
		for(int j = 1;j<=n1;j++)
		{
			ask[j] = read(),askv[j] = read();
			ori[j] = x[ask[j]];
			x[ask[j]] = askv[j];
		}
		for(int j = 1;j<=n2;j++)
		{
			asky[j] = read(),askvy[j] = read();
			oriy[j] = y[asky[j]];
			y[asky[j]] = askvy[j];
		}
		ans+=check();
		for(int j = 1;j<=n1;j++)x[ask[j]] = ori[ask[j]];
		for(int j = 1;j<=n2;j++)y[asky[j]] = oriy[asky[j]];
	}
	cout<<ans;
	return 0;
}
