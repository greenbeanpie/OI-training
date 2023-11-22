#include<bits/stdc++.h>
using namespace std;
char ans[3005],s[3005];
int n,m,ch[3005][35],k,l;
bool cst(int x,int y)
{
	for(int i=25;i>=0;--i)
		if(ch[x][i]!=ch[y][i]) return ch[x][i]<ch[y][i];
	return 1;
}
bool cpa(int x,int y)
{
	for(int i=0;i<26;++i)
		if(ch[x][i])
		{
			for(int j=25;j>i;--j)
				if(ch[y][j]) return 1;
			return 0;
		}
	return 0;
}
int main()
{
	freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1) {cout<<'1'<<'\n';return 0;}
	for(int i=0;i<n;++i)
	{
		cin>>s;
		for(int j=0;j<m;++j)
			++ch[i][s[j]-97];
	}
	if(cst(0,1)) k=0,l=1;
	else k=1,l=0;
	for(int i=2;i<n;++i)
	{
		if(cst(i,k)) l=k,k=i;
		else if(cst(i,l)) l=i;
	}
	for(int i=0;i<n;++i)
	{
		if(i!=k) 
		{
			if(cpa(i,k)) ans[i]='1';
			else ans[i]='0';
		}
		else
		{
			if(cpa(i,l)) ans[i]='1';
			else ans[i]='0';
		}
	}
	for(int i=0;i<n;++i) cout<<ans[i];
	cout<<'\n';
	return 0;
}