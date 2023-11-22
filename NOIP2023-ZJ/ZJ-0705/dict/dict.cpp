#include<bits/stdc++.h>

using namespace std;

typedef long long int LL;
const int N=3050;

int n,m;
//string s;
string ans;
string mn2,mn;
char bk[N];
char s[N][N];

bool cmp(char a,char b)
{
	return a>b;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	mn='z'*N;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		sort(s[i],s[i]+m,cmp);
		if(s[i]<mn)
		{
			mn2=mn;
			mn=s[i];
		}
		else if(s[i]<mn2)
		{
			mn2=s[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			bk[m-1-j]=s[i][j];
		}
		//cout<<mn<<endl;
		if(mn!=s[i])
		{
			if(bk<mn) ans=ans+'1';
			else ans=ans+'0';
		}
		else
		{
			if(bk<mn2) ans=ans+'1';
			else ans=ans+'0';
		}
		
	}
	
	cout<<ans<<endl;
	return 0;
}

