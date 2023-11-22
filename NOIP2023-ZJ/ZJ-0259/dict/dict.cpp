#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
string s[3005];
int Mi[3005];
int Ma[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		Mi[i]=26;
		Ma[i]=1;
		for(int j=0;j<m;j++)
		{
			Mi[i]=min(Mi[i],s[i][j]-'a'+1);
			Ma[i]=max(Ma[i],s[i][j]-'a'+1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(j!=i&&Ma[j]<=Mi[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)cout<<1;else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}