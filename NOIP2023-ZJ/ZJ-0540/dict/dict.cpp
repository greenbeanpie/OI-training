#include <bits/stdc++.h>
using namespace std;

int n,m,num[3005][30];
char s[3005];

bool check(int x,int y)
{
	int l=0,r=25;
	while(!num[x][l]) l++;
	while(!num[y][r]) r--;
	
	return l<r;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++) num[i][s[j]-'a']++;
	}
	
	for(int i=1;i<=n;i++)
	{
		bool ok=true;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(!check(i,j))
			{
				ok=false;
				break;
			}
		}
		(ok) ? printf("1") : printf("0");
	}
	
	
	return 0;
	
}