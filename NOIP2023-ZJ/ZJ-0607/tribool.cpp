#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,T;
int n,m,ans;
char opt;
map<int,int> Map;
int cnt;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		typedef pair<int,char> PII;
		PII ord[N];
		Map.clear();
		cnt=0;
		ans=0;int x;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			cin>>opt;
			scanf("%d",&x);
			ord[++cnt].first=x;
			ord[cnt].second=opt;
		}
		for(int i=cnt;i>=1;i--)
		{
			if(Map[ord[i].first]) continue;
			Map[ord[i].first]++;
			if(ord[i].second=='U') ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}