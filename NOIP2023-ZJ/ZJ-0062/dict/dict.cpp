#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int n,m;
int mx[N],mn[N];
char ch[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%s",ch+1);
		mx[i] = 0;
		mn[i] = 30;
		for(int j = 1;j <= m;j++)
		{
			int x = ch[j] - 'a' + 1;
			mx[i] = max(mx[i],x);
			mn[i] = min(mn[i],x);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		int flag = 1;
		for(int j = 1;j <= n;j++)
		{
			if(i == j) continue;
			if(mn[i] >= mx[j]) flag = 0;
		}
		printf("%d",flag);
	}
	puts("");
	return 0;
}