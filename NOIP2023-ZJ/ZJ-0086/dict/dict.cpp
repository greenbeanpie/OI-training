//Private Eye,dancing with the wind.The last time.
#include<bits/stdc++.h>
using namespace std;

#define MAXN 3005
char s[MAXN];
int n,m,maxn[MAXN],minn[MAXN];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		minn[i]=1e9;
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			int t=int(s[j])-'a'+1;
			maxn[i]=max(maxn[i],t);
			minn[i]=min(minn[i],t);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(minn[i]>=maxn[j])
			{
				flag=0;
				break;
			}
		}
		printf("%d",flag);
	}
	return 0;
}
