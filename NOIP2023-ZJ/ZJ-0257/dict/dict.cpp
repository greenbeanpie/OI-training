// Last affectioness leave for Mao
#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,m;
int a[N][N],c[N];
bool cmp(int x[],int y[])
{
	for(int i=1;i<=m;i++)
		if(x[i]<y[i]) return 1;
		else if(x[i]>y[i]) return 0; 
	return 1;
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			a[i][j]=int(ch)-97;
		}
		sort(a[i]+1,a[i]+m+1,greater<int>());
		if(cmp(a[i],c) || i==1) for(int j=1;j<=m;j++) c[j]=a[i][j];
//		for(int j=1;j<=m;j++) cout<<c[j]<<' ';
//		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		reverse(a[i]+1,a[i]+m+1);
//		for(int j=1;j<=m;j++) cout<<a[i][j]<<' ';
//		cout<<endl;
		cout<< cmp(a[i],c) ? 1:0 ;
	}
}