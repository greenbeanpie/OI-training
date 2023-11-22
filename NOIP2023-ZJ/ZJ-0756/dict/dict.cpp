#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,tj[3001][31],uj[3001][31];//,sumi[3001][31],sumx[3001][31];
bool vis[3001];
char x[3001],y[3001],s[3001][3001],mi[3001],mx[3001];
//string mi,mx;
bool judge(char a[],char b[])
{
	int i;
	for(i=0;i<m;i++)
	{
		if(a[i]<b[i])
		{
			return true;
		}
		if(a[i]>b[i])
		{
			return false;
		}
	}
	return false;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j;
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(i=0;i<m;i++)
	{
		mi[i]='z';
		mx[i]='z';
	}
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			if(judge(s[i],mi))
			{
				for(j=0;j<m;j++)
				{
					mi[j]=s[i][j];
				}
				k=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i==k)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		return 0;
	}
	if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			x[i]=min(s[i][0]-'a',s[i][1]-'a')+'a';
			y[i]=max(s[i][0]-'a',s[i][1]-'a')+'a';
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				if(x[i]>=y[j])
				{
					vis[i]=true;
					break;
				}
			}
			cout<<1-vis[i];
		}
		return 0;
	}
	char si[n+1][m+1],sm[n+1][m+1];
	int num,cm;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			tj[i][s[i][j]-'a']++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=25;j++)
		{
			uj[i][j]=tj[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		num=0;
		for(j=0;j<m;j++)
		{
			while(tj[i][num]<=0)
			{
				num++;
				if(num>=26)
				{
					break;
				}
			}
			si[i][j]=num+'a';
			tj[i][num]--;
		}
		cm=25;
		for(j=0;j<m;j++)
		{
			while(uj[i][cm]<=0)
			{
				cm--;
				if(cm<0)
				{
					break;
				}
			}
			sm[i][j]=cm+'a';
			uj[i][cm]--;
		}
	}
	for(i=0;i<m;i++)
	{
		mi[i]='z';
	}
	for(i=1;i<=n;i++)
	{
		if(judge(sm[i],mi))
		{
			for(j=0;j<m;j++)
			{
				mi[j]=sm[i][j];
			}
			k=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(judge(sm[i],mx) && i!=k)
		{
			for(j=0;j<m;j++)
			{
				mx[j]=sm[i][j];
			}
			l=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i!=k)
			if(!judge(si[i],mi))
			{
				vis[i]=true;
			}
		else
		{
			if(!judge(si[i],mx))
			{
				vis[i]=true;
			}
		}
		cout<<1-vis[i];
	}
	return 0;
}
