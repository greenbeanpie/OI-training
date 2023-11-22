#include <bits/stdc++.h>
  using namespace std;
int c,t,n,m,a[100005],p,q,s;
char b[100005],o;
bool d[100005];
//void find(int t)
//{
//	if (d[t]==1) return;
//	d[t]=1;
//	if (b[a[t]]=='U' || b[a[t]]=='T' || b[a[t]]=='F')
//	{
//		b[t]=b[a[t]];
//		a[t]=0;
//		return;
//	}
//	find(a[t]);
//	d[t]=0;
//	if (b[a[t]]=='U' || b[a[t]]=='T' || b[a[t]]=='F')
//	{
//		b[t]=b[a[t]];
//		a[t]=0;
//		return;
//	}
//	else if (!d[a[t]]) a[t]=a[a[t]];
//}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>c>>t;
	while (t--)
	{
		s=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=0;
			b[i]=' ';
		}
		cin>>n>>m;
		for (int i=1;i<=m;i++)
		{
			cin>>o>>p;
			if (o=='U' || o=='T'|| o=='F')
			{
				b[p]=o;
				a[p]=0;
			}
			else if (o=='+')
			{
				cin>>q;
				a[p]=q;
				b[p]=b[q];
//				find(p);
				a[p]=0;
			}
			else
			{
				cin>>q;
				a[p]=q;
				if (b[q]=='T') b[p]='F';
				if (b[q]=='F') b[p]='T';
				if (b[q]=='U') b[p]='U';
				a[p]=0;
			}
		}
//		for (int i=1;i<=n;i++)
//		{
//			if (b[i]!='U' && a[i]!=0) find(i);
//		}
		for (int i=1;i<=n;i++)
		{
			if (b[i]=='U') s++;
		}
		cout<<s<<endl;
	}
	return 0;
}

