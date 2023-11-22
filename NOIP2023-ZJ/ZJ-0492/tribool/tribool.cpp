#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=2e6+10;
int c,t,n,m;
char ch[maxn];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			char chr;cin>>chr;
			int x;scanf("%d",&x);
			ch[x]=chr;
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(ch[i]=='U') ans++;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


