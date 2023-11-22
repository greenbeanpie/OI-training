#include<bits/stdc++.h>
using namespace std;
char str[3005][3005];
int cnt[26][3005];
bool cmp(int x,int y)
{
	int i=0,j=25;
	while(cnt[i][x]==0)i++;
	while(cnt[j][y]==0)j--;
	return (i<j);
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%s",str[i]);
		for(int j=0;j<m;++j)
		{
			cnt[str[i][j]-'a'][i]++;
		}
	}
	for(int i=0;i<n;++i)
	{
		bool flag=1;
		for(int j=0;j<n;++j)
		{
			if(i!=j&&(!cmp(i,j)))
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("1");
		else printf("0");
	}
}
