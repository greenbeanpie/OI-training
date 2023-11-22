#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0)
using namespace std;
int n,m,f;
string s;
char a[10005][10];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		a[i][0]=s[0];a[i][1]=s[0];
		for(int j=1;j<m;j++)
		if(s[j]<a[i][0]) a[i][0]=s[j];
		else if(s[j]>a[i][1]) a[i][1]=s[j];
	}
	for(int i=1;i<=n;i++)
	{
		f=0;
		for(int j=1;j<=n;j++)
		if(i!=j&&a[i][0]>=a[j][1]) {f=1;break;}
		if(f==0) cout<<"1";else cout<<"0";
	}
	return 0;
}
