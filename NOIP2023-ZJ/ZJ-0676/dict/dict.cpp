#include <bits/stdc++.h>
using namespace std;
char maxi[3005][3005];
bool cmp(char a,char b)
{
	return a>b;
}
char x[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;	
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		stable_sort(x,x+m,cmp);
		for(int j=0;j<m;j++)
		{
			maxi[j][i]=x[j];
		}
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	bool flag=true;
	bool flag2=true;
	char p,q;
	for(int i=1;i<=n;i++)
	{
		flag2=true;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			flag=true;
			for(int k=0;k<m;k++)
			{
				p=maxi[m-k-1][i];
				q=maxi[k][j];
				if(p>q)
				{
					flag=false;
					break;
				}
				else if(p<q)
				{
					break;
				}
				else if(k==m-1)
				{
					break;flag=false;
				}
			}
			if(!flag)
			{
				flag2=false;
				break;
			}
		}
		if(flag2==false)
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}
	return 0;
}
//It is true that I don't have any greater ideas to do this job,What a pity!
