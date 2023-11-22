#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
char maxstr[N][N],minstr[N][N];
char str[N][N];
int n,m;
int strmax[N],strmin[N];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i]+1;		
		memcpy(maxstr[i],str[i],sizeof(str[i]));
		memcpy(minstr[i],str[i],sizeof(str[i]));
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(m==1)
	{
		int f=1;
		char ch='z';
		for(int i=1;i<=n;i++)
		{
			if(str[i][1]<ch)
			{
				ch=str[i][1];
				f=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i==f)
				cout<<1;
			else cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		char chmin='z'+1,chmax='a'-1;
		for(int j=m;j>0;j--)
		{			
			if(str[i][j]<chmin)
			{
				chmin=str[i][j];
				strmin[i]=j;
			}
			if(str[i][j]>chmax)
			{
				chmax=str[i][j];
				strmax[i]=j;
			}
		}
		swap(maxstr[i][1],maxstr[i][strmax[i]]);
		swap(minstr[i][1],minstr[i][strmin[i]]);
	}
	for(int i=1;i<=n;i++)
	{
		bool one=false,mo=false;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			one=false;
			for(int o=1;o<=m;o++)
			{
				char a=minstr[i][o],b=maxstr[j][o];
				if(a<b)
				{
					one=true;
					break;
				}
				if(b<a)
					break;
			}
			if(one==false)
			{
				mo=false;
				break;
			}
		}
		if(one==true) mo=true;
		if(mo==false)
			cout<<0;
		else cout<<1;
	}

	return 0;
}
