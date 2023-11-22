#include <bits/stdc++.h>
using namespace std;

int c,t;
int n,m,ans,tb[114514];
char op;

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	cin >> c >> t;
	
	if(c==3 || c==4)
	{
		while(t--)
		{
			memset(tb,0,sizeof(tb));
			ans=0;
			cin >> n >> m;
			
			for(int i=1;i<=m;i++)
			{
				int x;
				cin >> op >> x;
				if(op=='T') tb[x]=1;
				if(op=='F') tb[x]=0;
				if(op=='U') tb[x]=2;
			}
			for(int i=1;i<=n;i++) if(tb[i]==2) ans++;
			
			cout << ans << '\n';
		}
	}
	else
	{
		while(t--)
		{
			ans=0;
			cin >> n >> m;
			
			for(int i=1;i<=n;i++) tb[i]=2;
			for(int i=1;i<=m;i++)
			{
				int x;
				cin >> op >> x;
				if(op=='T') tb[x]=1;
				if(op=='F') tb[x]=0;
				if(op=='U') tb[x]=2;
			}
			for(int i=1;i<=n;i++) if(tb[i]==2) ans++;
			
			cout << ans << '\n';
		}
	}
	
	
	return 0;
	
}