#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
char a[100010];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4)
	{
		for(int i=1;i<=t;i++)
		{
			int ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++)a[i]='a';
			for(int j=1;j<=m;j++)
			{
				char x;
				int k;
				scanf("%s%d",&x,&k);
				a[k]=x;
			}
			for(int i=1;i<=n;i++)if(a[i]=='U')ans++;
			cout<<ans<<endl;
		}	
	}
	
}
