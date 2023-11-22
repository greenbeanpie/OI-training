#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
int x,y,z;
struct node{
	int x;
	int y;
	int d;
	int f;
	int e;
};
bool cmp(node x,node y)
{
	return x.e>y.e;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long s=0,cnt=0;
		cin>>n>>m>>k>>d;
		node a[50000];
		bool p[50000];
		for(long i=1;i<=m;i++)
		{
			cin>>x>>y>>z;
			if(z-y*d>0&&y<=k)
			{
				cnt++;
				a[i].x=x,a[i].y=y,a[i].d=z;
				a[i].f=a[i].d-a[i].y*d;
				a[i].e=a[i].f/y;
			}
		}
		sort(a+1,a+1+m,cmp);
		for(long i=1;i<=cnt;i++)
		{
			bool h=true;
			for(long j=max(a[i].x-k+1,1);j<=min(a[i].x-a[i].y+k+1,n);j++)
				if(p[j]==true)
					h=false;
			if(h==true)
			{
				s+=a[i].f;
				for(long j=a[i].x-a[i].y+1;j<=a[i].x;j++)
					p[j]=true;
			}
		}
		cout<<s<<endl;
	}
	
	
	
}
