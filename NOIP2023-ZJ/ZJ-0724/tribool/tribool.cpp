#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m,a,b,e,cnt=0;
		cin>>n>>m;
		int x[n+1];
		memset(x,-2,sizeof(x));
		for(int i=1;i<=m;i++)
		{
			char v;
			cin>>v;
			if(v=='+') 
			{
				cin>>a>>b;
				x[a]=x[b];
			}
			else if(v=='-')
			{
				cin>>a>>b;
				x[a]=-x[b];
			}
			else if(v=='T')
			{
				cin>>e;
				x[e]=1;
			}
			else if(v=='F')
			{
				cin>>e;
				x[e]=-1;
			}
			else if(v=='U')
			{
				cin>>e;
				x[e]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(x[i]==0) cnt+=1;
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
