#include<bits/stdc++.h>
using namespace std;
char c[3010][3010];
bool cmp(char c1,char c2)
{
	return c1-'0'<c2-'0';
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
		sort(c[i]+1,c[i]+1+m,cmp);
	}
	for(int i=1;i<=n;i++)
	{
		int ans=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(c[i][1]>=c[j][m]) ans=0;
		}
		cout<<ans;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
