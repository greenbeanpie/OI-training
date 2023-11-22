#include<bits/stdc++.h>
using namespace std;
const int N=3050;
int n,m;
char minn[3050][3050],maxn[3050][3050];
bool cmp1(char x,char y)
{
	return x<y;
}
bool cmp2(char x,char y)
{
	return x>y;
}
bool compare(int x,int y)
{
	bool ok=false;
	for(int i=1;i<=m;i++)
	{
		if(minn[x][i]<maxn[y][i])
		{
			ok=true;
			break;
		}
		if(minn[x][i]>maxn[y][i])
			break;
	}
	return ok;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>minn[i][j];
			maxn[i][j]=minn[i][j];
		}
		sort(minn[i]+1,minn[i]+m+1,cmp1);
		sort(maxn[i]+1,maxn[i]+m+1,cmp2);
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(j==i)
				continue;
			if(!compare(i,j))
			{
				flag=false;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
