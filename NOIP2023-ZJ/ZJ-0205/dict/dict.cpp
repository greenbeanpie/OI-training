#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int n,m;
int v[N],t[30];
string s,a[N],b[N],st,Min1,Min2;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m+1;i++)
	Min2+='z';
	Min1=Min2;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		memset(t,0,sizeof(t));
		for(int j=0;j<m;j++)
			t[s[j]-'a']++;
		st="";
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<t[j];k++)
				st+=(char)('a'+j);
		}
		a[i]=st;//min
		st="";
		for(int j=25;j>=0;j--)
		{
			for(int k=0;k<t[j];k++)
				st+=(char)('a'+j);
		}
		b[i]=st;//max
		if(Min1>=st)
		{
			Min2=Min1;
			Min1=st;
		}
		else if(Min2>st)
			Min2=st;
//		cout<<a[i]<<' '<<b[i]<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<Min1) 
		{
			v[i]=1;
		}
		else if(a[i]==Min1)
		{
			if(a[i]==b[i]&&a[i]<Min2)
			{
				v[i]=1;	
			}	
		}
		printf("%d",v[i]);
	}
	return 0;
}
