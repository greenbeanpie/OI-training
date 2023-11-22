#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
int n,m,mx[MAXN],mn[MAXN],ans[MAXN];
char ch[MAXN];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);
		mn[i]=27,mx[i]=0;
		for(int j=1;j<=m;j++)
		{
			mn[i]=min(mn[i],ch[j-1]-'a'+1);
			mx[i]=max(mx[i],ch[j-1]-'a'+1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(mn[i]>=mx[j]) ans[i]=0;
		}
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	puts("");
	return 0;
}
