#include<bits/stdc++.h>
using namespace std;
int n,m,pos;
char up[3030],dn[3030],tar,num;
string s[3030];
void read()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}
int main()
{
    read();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	tar='z'+1;
	for(int i=1;i<=n;i++)
	{
		dn[i]='z'+1;
		up[i]='a'-1;
		for(int j=0;j<m;j++)
		{
			dn[i]=min(dn[i],s[i][j]);
			up[i]=max(up[i],s[i][j]);
		}
		tar=min(tar,up[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(tar==up[i]&&dn[i]==up[i])
		{
			num++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if((tar==up[i]&&dn[i]>tar&&num==1)||((tar!=up[i]||num>1)&&dn[i]>=tar))
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	cout<<endl;
	return 0;
}
