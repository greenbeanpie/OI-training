#include<bits/stdc++.h>
using namespace std;
int q1[100010],q2[100010],q3[100010],l=1;
char f[100010];
/*int to[100010],val[100010],nxt[100010],h[100010],vis[100010],count[100010];
queue<int>q;
void add(int a,int b,int c)
{
	to[l]=a;
	val[l]=1;
	nxt[l]=h[b];
	h[b]=l;
	l++;
}
void spfa()
{
	for(int i=1;i<=n;i++)
	{
		if(h[i]!=0)
		{
			q.push(i);
			vis[i]=1;
			count
		}
	}
}*/
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	long long int n,m;
	cin>>c>>t;
	if(c==1||c==2||c==9||c==10||c==7||c==8)
	{
		for(int ii=1;ii<=t;ii++)
		{
			memset(f,'T',sizeof(f));
			cin>>n>>m;
			int iii=1,tot=1,sum=0,o=0;
			char v;
			for(int i=1;i<=m;i++)
			{
				cin>>v;
				if(v=='T'||v=='F'||v=='U')
				{
					cin>>iii;
					f[iii]=v;
				}
				if(v=='+')
				{
					cin>>q1[tot]>>q2[tot];
					f[q1[tot]]=f[q2[tot]];
				}
				if(v=='-')
				{
					cin>>q1[tot]>>q2[tot];
					if(f[q2[tot]]=='T')
						f[q1[tot]]='F';
					if(f[q2[tot]]=='F')
						f[q1[tot]]='T';
					if(f[q2[tot]]=='U')
						f[q1[tot]]='U';
					o++;
				}
				tot++;
			}
			for(int i=1;i<=n;i++)
			{
				if(f[i]=='U')
					sum++;
			}
			if(o==n)
				sum=n;
			cout<<sum<<endl;
		}
		return 0;
	}
	if(c==3||c==4)
	{
		for(int ii=1;ii<=t;ii++)
		{
			int sum=0,iii;
			cin>>n>>m;
			char v;
			for(int i=1;i<=n;i++)
				f[i]='T';
			for(int i=1;i<=m;i++)
			{
				cin>>v;
				cin>>iii;
				f[iii]=v;
			}
			for(int i=1;i<=n;i++)
			{
				if(f[i]=='U')
					sum++;
			}
			cout<<sum<<endl;
		}
		return 0;
	}
	if(c==5||c==6)
	{
		for(int ii=1;ii<=t;ii++)
		{
			int sum=0,iii,tot=1;
			cin>>n>>m;
			char v;
			for(int i=1;i<=n;i++)
				f[i]='T';
			for(int i=1;i<=m;i++)
			{
				cin>>v;
				if(v=='U')
				{
					cin>>iii;
					f[iii]=v;
				}
				if(v=='+')
				{
					cin>>q1[tot]>>q2[tot];
					tot++;
				}
			}
			for(int i=1;i<tot;i++)
			{
				f[q1[i]]=f[q2[i]];
			}
			for(int i=1;i<=n;i++)
			{
				if(f[i]=='U')
					sum++;
			}
			cout<<sum<<endl;
		}
		return 0;
	}
	/*if(c==7||c==8)
	{
		for(int ii=1;ii<=t;ii++)
		{
			memset(to,0,sizeof(to));
			memset(val,0,sizeof(val));
			memset(nxt,0,sizeof(nxt));
			memset(h,0,sizeof(h));
			cin>>n>>m;
			char v;
			int tot=1;
			memset(f,'T',sizeof(f));
			for(int i=1;i<=m;i++)
			{
				//int from,towhere;
				cin>>v;
				//cin>>towhere>>from;
				cin>>q1[tot]>>q2[tot];
				if(v=='+')
				{
					q3[tot]=1;
				}
				else
				{
					q3[tot]=0;
				}
				tot++;
			}
		}
		return 0;
	}*/
	return 0;
}

