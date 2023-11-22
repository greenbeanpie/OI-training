#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,y,b;
string s[3001];
int sum[3001][31];
int main()
{
	freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>s[i];
	for (i=1;i<=n;i++)
	{
		for (j=0;j<m;j++) sum[i][s[i][j]-'a'+1]++;
	}
	for (i=1;i<=n;i++)
	{
		b=1;
		for (x=1;x<27;x++) if (sum[i][x]) break;
		for (j=1;j<=n;j++)
		{
			if (i==j) continue;
			for (y=26;y;y--) if (sum[j][y]) break;
			if (y<=x) 
			{
				b=0;break;
			}
		}
		cout<<b;
	}
}