#include <bits/stdc++.h>
  using namespace std;
int n,m;
char a[3005][3005],c[3005][3005],d[3005][3005];
bool b,t;
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			c[i][j]=a[i][j];
			d[i][j]=a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		sort(c[i]+1,c[i]+m+1);
		for (int j=1;j<=m;j++)
		{
			d[i][j]=c[i][m-j+1];
		}
	}
	for (int i=1;i<=n;i++)
	{
		b=1;
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			t=1;
			for (int k=1;k<=m;k++)
			{
				if (c[i][k]>d[j][k])
				{
					b=0;
					break;
				}
				if (c[i][k]<d[j][k])
				{
					t=0;
					break;
				}
			}
			if (t) b=0;
			if (!b) break;
		}
		cout<<b;
	}
	cout<<endl;
	return 0;
}

