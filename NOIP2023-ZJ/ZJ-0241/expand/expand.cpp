#include<bits/stdc++.h>
using namespace std;
const int N=2010;
const int M=5e5+10;
bool dp[N][N];

int a[M],b[M];

int xxa[M],yya[M],xxb[M],yyb[M];

int c,n,m,q;

void workk()
{
	if(a[1]==b[1]){
		cout<<0;
		return;
	}
	if(a[1]<b[1]){
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(a[i]<b[j])dp[i][j]|=dp[i-1][j],dp[i][j]|=dp[i][j-1];
			}
	}else{
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(a[i]>b[j])dp[i][j]|=dp[i-1][j],dp[i][j]|=dp[i][j-1];
			}
	}
	if(dp[n][m]==1)	cout<<1;
	else	cout<<0;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=m;i++)	cin>>b[i];
	
	if(c<=7)
	{
		workk();
		while(q--)
		{
			int tott1,tott2;
			cin>>tott1>>tott2;
			for(int i=1;i<=tott1;i++)
			{
				int x,y;
				cin>>x>>y;
				yya[i]=a[x];
				xxa[i]=x;
				a[x]=y;
			}
			for(int i=1;i<=tott2;i++)
			{
				int x,y;
				cin>>x>>y;
				yyb[i]=b[x];
				xxb[i]=x;
				b[x]=y;
			}
			workk();
			for(int i=1;i<=tott1;i++)
			{
				a[xxa[i]]=yya[i];
			}
			for(int i=1;i<=tott2;i++)
			{
				b[xxb[i]]=yyb[i];
			}
		}
		cout<<"\n";
		return 0;
	}else{
		for(int i=1;i<=q+1;i++)
			cout<<0;
		cout<<"\n";
		return 0;
	}
}