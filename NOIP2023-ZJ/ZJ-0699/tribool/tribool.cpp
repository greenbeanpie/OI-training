#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,w,k;
char v;
struct node{
	char v;
	int i;
	int j;
};
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=c;i++)
	{
		cin>>n>>m;
		node a[110000];
		for(int j=1;j<=n;j++)
		{
			if(v=='T'||v=='U'||v=='F')
			{
				cin>>w;
				a[j].v=v,a[j].i=w;
			}
			if(v=='+'||v=='-')
			{
				cin>>w>>k;
				a[j].v=v,a[j].i=w,a[j].j=k;
			}
		}
	char p[11000];
	bool l[11000];
	int ans=0;
	p[a[n].i]='T';
	for(int j=n;j>=1;j--);
	{
		if(a[j].v=='T'||a[j].v=='F'||a[j].v=='U')
			p[a[j].i]=v,l[a[j].i]=true;
		if(a[i].v=='+')
			p[a[j].j]=p[a[j].i],l[a[j].i]=true;
		if(a[j].v=='-')
		{
			if(p[a[j].i]=='T')
			{
				if(p[a[j].j]!='T'&&l[a[j].j]==true)
					return -1;
				else
					p[a[j].j]='F';
			}
			if(p[a[j].i]=='F')
			{
				if(p[a[j].j]!='F'&&l[a[j].j]==true)
					return -1;
				else
					p[a[j].j]='F';
			}
			if(p[a[j].i]=='U')
			{
				if(p[a[j].j]!='F'&&l[a[j].j]==true)
					return -1;
				else
					p[a[j].j]='F';
			}	
		}
	} 
		for(int k=1;k<=n;k++)
			if(p[k]=='U'||l[k]==false)
				ans++;
		cout<<ans<<endl;
	}
	
}
