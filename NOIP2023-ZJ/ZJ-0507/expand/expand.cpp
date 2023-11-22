#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,k1,k2,t1,t2;
int a[10050];
int b[10050];
bool f[105][105][105][105];
bool flag;
void solve(int x)
{
	memset(f,0,sizeof(f));
	for(int len1=1;len1<=n;len1++)
	{
		for(int i=1;i<=n-len1+1;i++)
		{
			int j=i+len1-1;
			for(int len2=1;len2<=m;len2++)
			{
				for(int k=1;k<=m-len2+1;k++)
				{
					int l=k+len2-1;
					//cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
					if(l==k && i==j)
					{
						if(a[i]<b[k] && x==0)
							f[i][j][k][l]=true;
						if(a[i]>b[k] && x==1)
							f[i][j][k][l]=true;
						//cout<<f[i][j][k][l]<<endl;
						continue;
					}
					if(l==k)
					{
						if(x==0)
						{
							if(f[i][j-1][k][l] && a[j]<b[k])
							{
								f[i][j][k][l]=true;
							}
							if(f[i+1][j][k][l] && a[i]<b[k])
							{
								f[i][j][k][l]=true;
							}
						}
						else
						{
							if(f[i][j-1][k][l] && a[j]>b[k])
							{
								f[i][j][k][l]=true;
							}
							if(f[i+1][j][k][l] && a[i]>b[k])
							{
								f[i][j][k][l]=true;
							}
						}
						//cout<<f[i][j][k][l]<<endl;
						continue;
					}
					if(i==j)
					{
						if(x==0)
						{
							if(f[i][j][k+1][l] && a[i]<b[k])
							{
								f[i][j][k][l]=true;
							}
							if(f[i][j][k][l-1] && a[i]<b[l])
							{
								f[i][j][k][l]=true;
							}
						}
						else
						{
							if(f[i][j][k+1][l] && a[i]>b[k])
							{
								f[i][j][k][l]=true;
							}
							if(f[i][j][k][l-1] && a[i]>b[l])
							{
								f[i][j][k][l]=true;
							}
						}
						//cout<<f[i][j][k][l]<<endl;
						continue;
					}
					if(x==0)
					{
						if(a[j]<b[l] && (f[i][j-1][k][l-1] || f[i][j-1][k][l] || f[i][j][k][l-1]))
						{
							f[i][j-1][k][l-1]=true;
							continue;
						}
						if(a[i]<b[k] && (f[i+1][j][k+1][l] || f[i+1][j][k][l] || f[i][j][k+1][l]))
						{
							f[i][j][k][l]=true;
							continue;
						}
						//cout<<f[i][j][k][l]<<endl;
					}
					if(x==1)
					{
						if(a[j]>b[l] && (f[i][j-1][k][l-1] || f[i][j-1][k][l] || f[i][j][k][l-1]))
						{
							f[i][j-1][k][l-1]=true;
							continue;
						}
						if(a[i]>b[k] && (f[i+1][j][k+1][l] || f[i+1][j][k][l] || f[i][j][k+1][l]))
						{
							f[i][j][k][l]=true;
							continue;
						}
						//cout<<f[i][j][k][l]<<endl;
					}
				}
			}
		}
	}
	if(f[1][n][1][m])
		flag=true;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++)
		cin>>b[j];
	flag=false;
	solve(0);
	solve(1);
	cout<<flag;
	//cout<<q<<endl;
	while(q--)
	{
		//cout<<"!"<<endl;
		cin>>k1>>k2;
		for(int i=1;i<=k1;i++)
		{
			cin>>t1>>t2;
			a[t1]=t2;
		}
		for(int i=1;i<=k2;i++)
		{
			cin>>t1>>t2;
			b[t1]=t2;
		}
		flag=false;
		solve(0);
		solve(1);
		cout<<flag;
	}
	return 0;
}
