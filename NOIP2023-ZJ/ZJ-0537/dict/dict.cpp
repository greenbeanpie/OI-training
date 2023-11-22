#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
string st[3005],stmax[3005],stx[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i];
		k=0;
		for(int j=1;j<m;j++)
			if(st[i][j]>st[i][k])
				k=j;
		stmax[i]=st[i][k];
		for(int j=1;j<m;j++)
			if(j!=k)stmax[i]+=st[i][j];
				else stmax[i]+=st[i][0];
		k=0;
		for(int j=1;j<m;j++)
			if(st[i][j]<st[i][k])
				k=j;
		stx[i]=st[i][k];
		for(int j=0;j<m;j++)
			if(j!=k)stx[i]+=st[i][j];
				else stmax[i]+=st[i][0];
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(stx[i]>=stmax[j])
				{
					cout<<0;
					t=1;
					break;
				}
			}
		}
		if(!t)cout<<1;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}