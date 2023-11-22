#include<bits/stdc++.h>
using namespace std;
char c[10000000],c1[10000000],c2[10000000];//c1zuida c2zuixiao
bool vis[10000000];
long long int n,m;
void change()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	long long int p1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c1[i*m+j]=c[i*m+j];
			c2[i*m+j]=c[i*m+j];
		}
		int h=2;
		bool flag=1;
		while(flag)
		{
			p1=i*m+h-1;
			for(int j=h;j<=m;j++)
			{
				if(c[i*m+j]-'a'<=c[p1]-'a')
				{
					p1=i*m+j;
				}
			}
			if(p1!=i*m+h-1)
			{
				swap(c1[i*m+h-1],c1[p1]);
				flag=0;
			}
			h++;
		}
		flag=1;
		while(flag)
		{
			p1=i*m+h-1;
			for(int j=h;j<=m;j++)
			{
				if(c[i*m+j]-'a'>=c[p1]-'a')
				{
					p1=i*m+j;
				}
			}
			if(p1!=i*m+h-1)
			{
				swap(c2[i*m+h-1],c2[p1]);
				flag=0;
			}
			h++;
		}
	}
}
int main()
{
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{		
		for(int j=1;j<=m;j++)
		{
			cin>>c[j+i*m];
		}
	}
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			char f='1';
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					if(c[j]-'a'<c[i]-'a')
						f='0';
				}
			}
			cout<<f;
		}
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			char f='1';
			int p11=min(c[(i-1)*m+1]-'a',c[(i-1)*m+2]-'a');
			int p12=max(c[(i-1)*m+1]-'a',c[(i-1)*m+2]-'a');
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					int p21=min(c[(j-1)*m+1]-'a',c[(j-1)*m+2]-'a');
					int p22=max(c[(j-1)*m+1]-'a',c[(j-1)*m+2]-'a');
					if(p11>p22||(p11==p22&&p12>p21))
						f='0';
				}
			}
			cout<<f;
		}
		return 0;
	}
	
	change();
	
	for(int i=1;i<=n;i++)
	{
		char f='1';
		for(int j=1;j<=n;j++)	
		{
			if(i!=j)
			{
				for(int k=1;k<=m;k++)
				{
					if(c1[(i-1)*m+k]-'a'>c2[(j-1)*m+k]-'a')
					{
						f='0';
						break;
					}
					else 
					{
						if(c1[(i-1)*m+k]-'a'==c2[(j-1)*m+k]-'a')
							continue;
						else
							break;
					}
				}
			}
		}
		cout<<f;
	}
	return 0;
}

