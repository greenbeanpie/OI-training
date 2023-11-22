#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,x[N],xiao[59500][15],xiao2[59500][15];
int main()
{
	//ATTENTION: CLEAR!!!!!!!!!!!!!!  \n\n\n\n\n\n\n\n\n
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);


	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/**/     memset(x,0,sizeof x);     /**/
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	ios::sync_with_stdio(0);
	cin>>c>>t;
	if(c==3||c==4) //TFU
	{
		while(t--)
		{
			memset(x,0,sizeof x);
			int n,m,ans=0;
			cin>>n>>m;
			for(int i=0;i<m;++i)
			{
				char ch;int idx;
				cin>>ch>>idx;
				if(ch=='U') x[idx]=2;
				if(ch=='T') x[idx]=1;
				if(ch=='F') x[idx]=0;
			}
			for(int i=1;i<=n;++i) if(x[i]==2) ans++;
			cout<<ans<<"\n";
		}
	}
	if(c==1||c==2)
	{
		while(t--)
		{
			memset(xiao,0,sizeof xiao);
			memset(xiao2,0,sizeof xiao2);
			int n,m,ans=10000;
			cin>>n>>m;
			for(int i=0;i<(int)pow(3,n);++i)
			{
				int now=i,cnt=0;
				while(now)
				{
					xiao[i][++cnt]=now%3;
					xiao2[i][cnt]=now%3;
					now/=3;
				}
			}
			for(int i=0;i<m;++i)
			{
				char ch;cin>>ch;
				if(ch=='U')
				{
					int idx;cin>>idx;
					for(int j=0;j<(int)pow(3,n);++j) xiao2[j][idx]=2;
				}
				if(ch=='T')
				{
					int idx;cin>>idx;
					for(int j=0;j<(int)pow(3,n);++j) xiao2[j][idx]=1;
				}
				if(ch=='F')
				{
					int idx;cin>>idx;
					for(int j=0;j<(int)pow(3,n);++j) xiao2[j][idx]=0;
				}
				if(ch=='+')
				{
					int a,b;cin>>a>>b;
					for(int j=0;j<(int)pow(3,n);++j) xiao2[j][a]=xiao2[j][b];
				}
				if(ch=='-')
				{
					int a,b;cin>>a>>b;
					for(int j=0;j<(int)pow(3,n);++j)
					{
						if(xiao2[j][b]==2) xiao2[j][a]=2;
						else xiao2[j][a]=1-xiao2[j][b];
					}
				}
			}
			for(int i=0;i<(int)pow(3,n);++i)
			{
				bool flag=true;
				for(int j=1;j<=n;++j) if(xiao[i][j]!=xiao2[i][j]) flag=false; 
				if(flag)
				{
					int geshu=0;
					for(int j=1;j<=n;++j) if(xiao[i][j]==2) geshu++;
					ans=min(ans,geshu);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
