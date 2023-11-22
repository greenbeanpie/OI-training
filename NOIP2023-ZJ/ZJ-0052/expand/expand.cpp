#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
const int N=5e5+10,M=4e4+10;
int C,n,m,q;
int a[N],b[N],ta[N],tb[N],ans[N];
namespace Work1
{
	bitset<M>dp[M];
	int solve()
	{
		for(int i=1;i<=n;i++)dp[i].reset();
		dp[1][1]=1;
		if(a[1]==b[1]||a[n]==b[m])return 0;
		int opt=a[1]>b[1];
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(dp[i][j])
		{
			if((opt&&(a[i+1]>b[j]))||(!opt&&(a[i+1]<b[j])))dp[i+1][j]=1;
			if((opt&&(a[i]>b[j+1]))||(!opt&&(a[i]<b[j+1])))dp[i][j+1]=1;
		}
//		for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++)
//			printf("%d",(int)dp[i][j]);puts("");
		return dp[n][m];
	}
}
namespace Work2
{
	int Ra[N],Rb[N];
	stack<int>st;
	int solve()
	{
		for(int i=1;i<=n;i++)
		{
			while(!st.empty()&&a[st.top()]>=a[i])Ra[st.top()]=i,st.pop();
			st.push(i);
		}
		while(!st.empty())Ra[st.top()]=n,st.pop();
//		for(int i=1;i<=n;i++)cout<<Ra[i]<<' ';cout<<endl;
		int l=0,r=0,res=0;;
		auto get=[&](const int&L,const int&R)
		{
			if(l!=L||R!=R)
			{
				l=L,r=R;
				res=0;for(int i=l;i<=r;i++)res=max(res,a[i]);
				return res;
			}
			return res;
		};
		int pd=1;for(int i=1,j=1&&pd;j<=m;j++)
		{
			if(a[i]>b[j])pd=0;
			while(i!=n&&get(i,Ra[i])<b[j])i=Ra[i];
		}
		return pd;
	}
}
int solve()
{
	if(C>=8&&C<=14)return Work2::solve();
	return Work1::solve();
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i],ta[i]=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],tb[i]=b[i];
	ans[0]=solve();
	for(int i=1;i<=q;i++)
	{
		int kx,ky,p,v;cin>>kx>>ky;
		for(int j=1;j<=kx;j++)cin>>p>>v,a[p]=v;
		for(int j=1;j<=ky;j++)cin>>p>>v,b[p]=v;
		ans[i]=solve();
		for(int j=1;j<=n;j++)a[j]=ta[j];
		for(int j=1;j<=m;j++)b[j]=tb[j];
	}
	for(int i=0;i<=q;i++)cout<<(char)(ans[i]+'0');cout<<endl;
	return 0;
}
/*
3 3 3 0
4 7 1
8 6 9
*/