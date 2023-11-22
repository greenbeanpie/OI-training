#include<bits/stdc++.h>
using namespace std;
int n,m;
string cc[3005],c[5][3005];
int minn[3005],maxn[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>cc[i];
		c[0][i]=cc[i];
		c[1][i]=cc[i];
	}
	for(int i=0;i<m;i++)
	{
		minn[i]=1e9;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(cc[i][j]-'a'<minn[i])
			{
				minn[i]=cc[i][j]-'a';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(cc[i][j]-'a'>maxn[i])
			{
				maxn[i]=cc[i][j]-'a';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[0][i][j]-'a'==minn[i]) continue;
			int minx=1e9,minp;
			for(int k=j+1;k<m;k++)
			{
				if(cc[i][k]<minx)
				{
					minx=cc[i][k];
					minp=k;
				}
			}
			if(minx==1e9) continue;
			char s1=c[0][i][minp],s2=c[0][i][j];
			c[0][i][j]=s1,c[0][i][minp]=s2;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[1][i][j]-'a'==maxn[i]) continue;
			int minx=-1,minp;
			for(int k=j+1;k<m;k++)
			{
				if(cc[i][k]>minx)
				{
					minx=cc[i][k];
					minp=k;
				}
			}
			if(minx==-1) continue;
			char s1=c[1][i][minp],s2=c[1][i][j];
			c[1][i][j]=s1,c[1][i][minp]=s2;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		bool flag=1;
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(c[0][i]>=c[1][j])
			{
				flag=0;
				break;
			}
		}
		if(flag==0) cout<<"0";
		else cout<<"1";
	}
	return 0;
}
