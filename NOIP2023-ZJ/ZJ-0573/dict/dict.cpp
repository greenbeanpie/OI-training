#include<bits/stdc++.h>
using namespace std;

const int N=3e3+10;

int n,m;
struct node
{
	int id;
	char maxx[N];
}a[N];

char w[N][N],minn[N][N];
bool judge(char x[],char y[])
{
	for(int i=0;i<m;i++)
	{
		if(x[i]<y[i])
			return true;
		else if(x[i]>y[i])
			return false;
	}
	return false;
}

bool cmp(node x,node y)
{
	return judge(x.maxx,y.maxx);
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		for(int j=0;j<m;j++)
		{
			cin>>w[i][j];
			a[i].maxx[j]=minn[i][j]=w[i][j];
		}
		
		int id=0;
		for(int j=0;j<m-1&&minn[i][j+1]>=minn[i][j];j++)
			id=j+1;
		id++;
		for(int j=id+1;j<m;j++)
			if(minn[i][id]>=minn[i][j])
				id=j;
		if(id<m)
		{
			for(int j=0;j<id;j++)
				if(minn[i][j]>minn[i][id])
				{
					swap(minn[i][j],minn[i][id]);
					break;
				}
		}
		
		id=0;
		for(int j=0;j<m-1&&a[i].maxx[j+1]<=a[i].maxx[j];j++)
			id=j+1;
		id++;
		for(int j=id+1;j<m;j++)
			if(a[i].maxx[id]<=a[i].maxx[j])
				id=j;
		if(id<m)
		{
			for(int j=0;j<id;j++)
				if(a[i].maxx[j]<a[i].maxx[id])
				{
					swap(a[i].maxx[j],a[i].maxx[id]);
					break;
				}
		}
	}
	
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j].id==i)
				continue;
			if(judge(minn[i],a[j].maxx))
				cout<<1;
			else
				cout<<0;
			break;
		}
	}
	cout<<endl;
	return 0;
}
