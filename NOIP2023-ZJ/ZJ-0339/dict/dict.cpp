//20min打完了
//真好 
#include<bits/stdc++.h>
#define N 3020
using namespace std;
char ch1[N][N],ch2[N][N];
//ch1[i]是最小 ch2[i]是最大 
string s;
int n,m;
bool cmp1(char x,char y){return x<y;}
bool cmp2(char x,char y){return x>y;}
int work(int pos)
{
	for(int i=1;i<=n;i++)
	{
		if(i==pos)continue;
		for(int j=1;j<=m;j++)
		{
			if(ch1[pos][j]>ch1[i][m-j+1])return 0;
			if(ch1[pos][j]<ch1[i][m-j+1])break;
		}
	}
	return 1;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=1;j<=m;j++)ch1[i][j]=ch2[i][j]=s[j-1];
		sort(ch1[i]+1,ch1[i]+m+1,cmp1);
//		sort(ch2[i]+1,ch2[i]+m+1,cmp2);
	}
	for(int i=1;i<=n;i++)cout<<work(i);
}
