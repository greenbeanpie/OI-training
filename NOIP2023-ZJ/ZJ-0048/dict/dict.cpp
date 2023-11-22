#include<bits/stdc++.h>
using namespace std;
constexpr int N=3010;

int n,m;
char ch[N];
int mx[N],mn[N];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		mn[i]=30;
		for (int j=1;j<=m;j++)
		{
			mx[i]=max(mx[i],ch[j]-'a'+1);
			mn[i]=min(mn[i],ch[j]-'a'+1);
		}
	}
	for (int i=1;i<=n;i++)
	{
		bool flag=1;
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			if (mx[j]<=mn[i])
			{
				flag=0;
				break;
			}
		}
		printf("%d",flag);
	}
	return 0;
}