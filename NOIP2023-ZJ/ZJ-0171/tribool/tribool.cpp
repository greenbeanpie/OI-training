#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
bool as[200050];int a[1000005];
const int T=100005,F=-T,U=0,D=100005;
vector<int> son[7][200100];
void dfs(int u)
{
//	cout<<'u'<<u<<endl;
	as[u]=1;
	int l=son[t][u].size();
//	cout<<"l="<<l<<'\n';
	for(int i=0;i<l;i++)
	{
		dfs(son[t][u][i]+D);
		dfs(-son[t][u][i]+D);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	if(c==3||c==4)
	{
		bool a[100005]={0};
		while(t--)
		{
			cin>>n>>m;
			memset(a,0,sizeof a);
			char v;long long u,ans=0;
			for(int i=1;i<=m;i++)
			{
				cin>>v;cin>>u;
				if(v=='U')
					a[u]=1;
				else
					a[u]=0;
			}
			for(int i=1;i<=n;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>m;
		memset(as,0,sizeof as);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
			a[i]=i;
		for(int i=1;i<=m;i++)
		{
			char v;
			int u,w;
			cin>>v;
			cin>>u;
			if(v=='U')
				a[u]=U;
			if(v=='T')
				a[u]=T;
			if(v=='F')
				a[u]=F;
			if(v=='+')
			{
				cin>>w;
				a[u]=a[w];
			}
			if(v=='-')
			{
				cin>>w;
				a[u]=-a[w];
			}
		}
		for(int i=1;i<=n;i++)
		{
//			cout<<a[i]<<' '<<i<<'\n';
			bool fl=1;int p=i,tnt=0;
			while(tnt<=300)
			{
				if(a[p]*fl==-i)
				{
					a[i]=U;
					break;
				}
				if(a[p]==T||a[p]==F||a[p]==U||a[p]==p)
					break;
				if(a[p]<0)
				{
					p=-a[p];
					fl*=-1;
				}
				else
					p=a[p];
				tnt++;
			}
			if(a[i]==-i)a[i]=U;
			son[t][a[i]+D].push_back(i);
		}
		dfs(U+D);
		long long ans=0;
		for(int i=-n+D;i<=n+D;i++)
			ans+=as[i];
		ans=(ans-1)/2;
		cout<<ans<<'\n';
	}
	
//	if(c==5||c==6)
//	{
//		
//	}
	return 0;
}

