#include<bits/stdc++.h>
using namespace std;
const int N=3300;
int n,m;
char x;
int p[N][30];
bool compete(int a,int b) // a < b
{
	for(int i=0;i<26;i++) // a MIN 
	{
		if(p[a][i])
			for(int j=25;j>=0;j--)// b MAX 
			{
				if( p[b][j] )
				{
					if(j>i)  return true;
					else if(j==i) 
					{
						return p[b][j]>p[a][i];
					}
					else return false;
				}
			}
	}
	return false;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		x=getchar();
		for(int j=0;j<m;j++)
		{
			x=getchar();
			p[i][ x -'a' ]++;
		}
	}
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		f=true;
		for(int j=1;j<=n;j++)
		{
			if( i == j ) continue;
			if( ! compete(i,j) ) { f=false; putchar('0'); break; } // s[i] >= s[j]
		}
		if(f) putchar('1'); 
	}
	return 0;
}