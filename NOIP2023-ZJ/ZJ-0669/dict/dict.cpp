#include<iostream>
#include<string>
using namespace std;
long long n,m;
string s;
int mxid[3001],mnid[3001],mxnum=27;
int id,mx[3001];
int num[3001][27];
void fz(int x)
{
	id=x;
	for(int i=1;i<=26;i++)
	{
		mx[i]=num[x][i];
	}
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mnid[i]=27;
		for(int j=0;j<m;j++)
		{
			num[i][s[j]-96]++;
			if(s[j]-96>mxid[i])
			mxid[i]=s[j]-96;
			if(s[j]-96<mnid[i])
			mnid[i]=s[j]-96;
		}
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(mxid[i]>=mxnum) continue;
		if(mxid[i]==mxnum) 
		{
			for(int j=mxid[i];j>=1;j--)
			{
				if(num[i][j]<mx[j])
				fz(j);
			}
			mxnum=mxid[i];
		}
		else
		{
			fz(i);
			mxnum=mxid[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool f=1;
		if(i==id)
		{
			cout<<1;
			continue;
		}
		else if(mnid[i]<mxid[id])
		{
			cout<<1;
			continue;
		}
		else
		for(int j=1;j<=26;j++)
		{
			if(num[i][j]>mx[j])
			{
				cout<<1;
				break;
			}
			if(num[i][j]<mx[j])
			{
				cout<<0;
				break;
			}
		}
	}
	return 0;
}
