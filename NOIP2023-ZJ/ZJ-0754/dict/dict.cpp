#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,f[3003]={};
struct str
{
	char st[3003];
}s[3003];
bool cmp1(char a,char b)
{
	return a<b;
}
bool cmp2(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i].st;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(m!=1)
			for(int j=0;j<n;j++)
				if(j==i)
					sort(s[j].st,s[i].st+m,cmp1);
				else
					sort(s[j].st,s[j].st+m,cmp2);	
			//	cout<<"**"<<s[j].st<<"**";
		ll fla=1,ff=0,flag=0;
		for(int j=0;j<n;j++)
		{	
			if(j!=i)
				for(int o=0;o<m;o++)
				{
					if(s[i].st[o]!=s[j].st[o])
						flag=1;
					if(flag)
					{
						if(s[i].st[o]>s[j].st[o])
						{
							fla=0;
							ff=1;
						}
						break;
					}
				}
			if(ff) 
				break;
			if(j!=i&&flag==0)
			{
				fla=0;
				break;
			}
		}
		if(fla&&flag)
			f[i]=1;
	}
	for(int i=0;i<n;i++)
		cout<<f[i];
	return 0;
}
