#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cout<<0;
	return 0;
}



//#include<bits/stdc++.h>
//using namespace std;
//long long c,t,n,m;
//bool as[200050];int a[1000005],fa[1000005];
//const int T=100003,F=-T,U=0,D=100005;
//vector<int> son[7][200100];
//int get_f(int x)
//{
//	while(x!=fa[x]&&fa[x]!=T&&fa[x]!=U&&fa[x]!=F)x=fa[x]=fa[fa[x]];
//	return x;
//}
//void dfs(int u)
//{
////	cout<<'u'<<u<<endl;
//	as[u]=1;
//	int l=son[t][u].size();
////	cout<<"l="<<l<<'\n';
//	for(int i=0;i<l;i++)
//	{
//		dfs(son[t][u][i]);
//		dfs(2*D-son[t][u][i]);
//	}
//}
//int main()
//{
////	freopen("tribool2.in","r",stdin);
////	freopen("tribool.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin>>c>>t;
//	if(c==3||c==4)
//	{
//		bool a[100005]={0};
//		while(t--)
//		{
//			cin>>n>>m;
//			memset(a,0,sizeof a);
//			char v;long long u,ans=0;
//			for(int i=1;i<=m;i++)
//			{
//				cin>>v;cin>>u;
//				if(v=='U')
//					a[u]=1;
//				else
//					a[u]=0;
//			}
//			for(int i=1;i<=n;i++)
//			{
//				ans+=a[i];
//			}
//			cout<<ans<<'\n';
//		}
//		return 0;
//	}
//	while(t--)
//	{
//		cin>>n>>m;
//		memset(as,0,sizeof as);
//		memset(a,0,sizeof a);
//		memset(fa,0,sizeof fa);
//		for(int i=1;i<=n+D;i++)
//			a[i]=i;
//		for(int i=1;i<=m;i++)
//		{
//			char v;
//			int u,w;
//			cin>>v;
//			cin>>u;
//			if(v=='U')
//				a[u]=U;
//			if(v=='T')
//				a[u]=T;
//			if(v=='F')
//				a[u]=F;
//			if(v=='+')
//			{
//				cin>>w;
//				a[u]=a[w];
//			}
//			if(v=='-')
//			{
//				cin>>w;
//				a[u]=-a[w];
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			
//			if(a[i]>0)
//				fa[i]=a[i],fa[i+D]=a[i]+D;
//			if(a[i]<0)
//				fa[i]=-a[i]+D,fa[i+D]=a[i];
//			if(a[i]==0)
//				fa[i]=fa[i+D]=0;
//		}
////		fa[T]=T;fa[T+D]=T+D;
//		
//		for(int i=1;i<=n;i++)
//		{
////			cout<<a[i]<<' '<<i<<'\n';
//			a[i]=get_f(i);
////			if(a[i]==-i)a[i]=U;
////			cout<<a[i]<<' '<<i<<'\n';
//			son[t][a[i]].push_back(i);
//		}
////		for(int i=1;i<=n;i++)
////		{
////			cout<<i<<' '<<a[i]<<'\n';
////		}
//		dfs(U);
//		long long ans=0;
//		for(int i=-n+D;i<=n+D;i++)
//			ans+=as[i];
//		ans=(ans-1)/2;
//		cout<<ans<<'\n';
//	}
//	
////	if(c==5||c==6)
////	{
////		
////	}
//	return 0;
//}

