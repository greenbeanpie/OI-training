#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
char smax[3010][3010],smin[3010][3010];

bool cmp(char x,char y){return x > y;}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%s",&smax[i]);
		for(int j = 0;j < m;j++) smin[i][j] = smax[i][j];
		sort(smin[i],smin[i] + m);
		sort(smax[i],smax[i] + m,cmp);
	}
	//Point 1;
	if(n == 1)
	{
		printf("1");
		return 0;
	}
	//Other Points;
	bool flag;
	for(int i = 1;i <= n;i++)
	{
		flag = true;
		for(int j = 1;j <= n;j++)
		{
			if(i == j) continue;
			if(strcmp(smin[i],smax[j]) != -1)
			{
				flag = false;
				break;
			}
		}
		if(flag) printf("1");
		else printf("0");
	}
	return 0;
}