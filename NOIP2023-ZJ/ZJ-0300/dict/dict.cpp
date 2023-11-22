#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
char s[3010][3010];
int cnt[3010][26];
int sum[3010][27];
int minn[3010];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
	{
		minn[i]=26;
		for(int j=1;j<=m;++j)
		{
			cnt[i][s[i][j]-'a']++;
			minn[i]=min(minn[i],s[i][j]-'a');
		}
		for(int j=25;j>=0;--j)
			sum[i][j]=sum[i][j+1]+cnt[i][j];
	}
	for(int i=1;i<=n;++i)
	{
		bool f=0;
		for(int j=1;j<=n;++j)
		{
			if(j==i)continue;
			if(sum[j][minn[i]+1]==0)
			{
				f=1;
				break;
			}
		}
		if(f)printf("0");
		else printf("1");
	}
	return 0;
}