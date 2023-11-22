#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,cnt,x[N],y[N],g[N],czz[N];
char a[N],cz,gz[N],fz[N];
int zhh(char ch)
{
	if(ch=='T')
		return 1;
	else if(ch=='F')
		return 2;
	else if(ch=='U')
		return 3;
	else if(ch=='+')
		return 4;
	else
		return 5;
}
char zhs(int ch)
{
	if(ch==1)
		return 'T';
	else if(ch==2)
		return 'F';
	else 
		return 'U';
}
char zh(char ch)
{
	if(ch=='T')
		return 'F';
	else if(ch=='U')
		return 'U';
	return 'T';
}
bool yz()
{
	for(int i=1;i<=n;i++)
	{
		fz[i]=gz[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(czz[i]==1||czz[i]==2||czz[i]==3)
		{
			fz[i]=zhs(czz[i]);
		}
		else if(czz[i]==4)
		{
			fz[x[i]]=fz[y[i]];
		}
		else 
		{
			fz[x[i]]=zh(fz[y[i]]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(fz[i]!=gz[i])
			return 0;
	}
	return 1;
}
void bs(int k,int num,int orz)
{
	if(cnt!=99)
		return ;
	if(k==n+1)
	{
		if(num==0&&yz())
		{
			cnt=min(cnt,orz);
		}
		return ;
	}
	gz[k]='T';
	bs(k+1,num,orz);
	gz[k]='F';
	bs(k+1,num,orz);
	if(num)
	{
		gz[k]='U';
		bs(k+1,num-1,orz);
	}
}


signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4)
	{
		while(t--)
		{
			cnt=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				a[i]='T';
			}
			for(int i=1,p;i<=m;i++)
			{	
				char hh;
				cin>>hh>>p;
				a[p]=hh;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]=='U')
					cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	else if(c==5||c==6)
	{
		while(t--)
		{
			cnt=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				a[i]='T';
			}
			for(int i=1;i<=m;i++)
			{
				cin>>cz;
				if(cz=='U')
				{
					cin>>g[i];
					if(a[g[i]]!='U')
					{
						cnt++;
						a[g[i]]='U';
					}
				}
				else
				{
					cin>>x[i]>>y[i];
					if(a[y[i]]=='U'&&a[x[i]]!='U')
					{
						cnt++;
						a[x[i]]='U';
					}
						
					else if(a[y[i]]!='U'&&a[x[i]]=='U')
					{
						a[x[i]]='T';
						cnt--;
					}
						
				}
			}
			cout<<cnt<<endl;
		}
	}
	else if(c<=2)
	{
		while(t--)
		{
			cnt=99;
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				cin>>cz;
				czz[i]=zhh(cz);
				if(cz=='T'||cz=='F'||cz=='U')
				{
					cin>>g[i];
				}
				else
				{
					cin>>x[i]>>y[i];
				}
			}
			for(int i=0;i<=n;i++)
			{
				if(cnt!=99)
					break;
				bs(1,i,i);
			}
			cout<<cnt<<endl;
		}
	}
	
	return 0;
}

