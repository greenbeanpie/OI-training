#include<bits/stdc++.h>
#define F(i,l,r) for(int i=l,i##end=r;i<=i##end;++i)
using namespace std;
char s[3009][3009];
char t[3009][3009];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("sk.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		sort(s[i],s[i]+m);
	//	cout<<s[i]<<endl;
		for(int j=0;j<m;j++)t[i][j]=s[i][m-j-1];
	}
	F(i,1,n)
	{
		bool flag=1;
		F(j,1,n)
		{
			if(i==j)continue;
			if(s[i]==t[j])
			{
				flag=false;
				break;
			}
			F(k,0,m-1)
			{
				if(s[i][k]==t[j][k]) continue;
				if(s[i][k]<t[j][k])break;
				flag=false;
				break;
			}
		}
		cout<<flag;
	}
	cout<<endl;
}
/*
4 7
abandon
bananaa
baannaa
notnotn

*/