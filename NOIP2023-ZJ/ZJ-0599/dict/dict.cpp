#include<bits/stdc++.h>
using namespace std;
int c[3001][27];
string x[3001],y[3001];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m,i,j,k;
	bool flag;
	char xx;
	string s;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		xx=getchar();
		while(xx<'a'||xx>'z')
		{
			xx=getchar();
		}
		c[i][(int)(xx)-96]++;
		for(j=2;j<=m;j++)
		{
			xx=getchar();
			c[i][(int)(xx)-96]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		x[i]="";
		for(j=1;j<=26;j++)
		{
			for(k=1;k<=c[i][j];k++)
			{
				x[i]=x[i]+(char)(j+96);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		y[i]="";
		for(j=26;j>=1;j--)
		{
			for(k=1;k<=c[i][j];k++)
			{
				y[i]=y[i]+(char)(j+96);			
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		flag=true;
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(x[i]>y[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			s=s+'1';
		}
		else
		{
			s=s+'0';
		}
	}
	cout<<s<<endl;
}
