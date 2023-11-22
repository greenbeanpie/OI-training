#include <bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
int dict[N][28];
int chuan[N][28];
char mtr[N][28];
int len[N];
int work(int x,int y)
{
	int p=len[x],q=1;
	while(p>0 && q<=len[y])
	{
		if(mtr[x][p]>mtr[y][q]) return 0;
		if(mtr[x][p]<mtr[y][q]) return 1;
		if(mtr[x][p]==mtr[y][q])
		{
			if(chuan[x][p]>chuan[y][q]) return 0;
			if(chuan[x][p]<chuan[y][q]) return 1;
			else
			{
				p--;
				q++;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char y;
			cin>>y;
			int pos=int(y)-'a';
			dict[i][pos]++;
		}
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=25;j>=0;j--)
		{
			if(dict[i][j]>0)
			{
				chuan[i][++(len[i])]=dict[i][j];
				mtr[i][(len[i])]=char(j+'a');
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int ans=1;
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				ans=work(i,j);
				if(ans==0) break; 
			}
		}
		cout<<ans;
	}
	return 0;
}