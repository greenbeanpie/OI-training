#include<bits/stdc++.h>
using namespace std;
string a[3001],b[3001];
int c[3001];
int n,m,w;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		cin>>a[i];
		b[i]=a[i];
		for(int j=0;j<m;j++)
			c[j]=int(a[i][j]-'a')+1;
		sort(c,c+m,cmp);
		for(int j=0;j<m;j++)
		{
			a[i][j]=char(c[j]-1)+'a';
			b[i][j]=char(c[m-j-1]-1)+'a';
		}			
	}
	if(n==1)
		cout<<"1"<<"\n";
	else
	{
		for(int i=1;i<=n;i++)
		{
			int flag=0;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(a[i]>=b[j])
				{
					flag=1;
					break;
				}
			}
			if(flag)
				cout<<"0";
			else
				cout<<"1";
		}
	}
	cout<<"\n";
	return 0;
}
