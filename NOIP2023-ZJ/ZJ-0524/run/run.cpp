#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m,k,d;
int cnt=0;
struct Node
{
	int ti,len,val,de;
}a[100001];
bool cmp(Node x,Node y)
{
	return x.de>y.de;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>T;
	while(T--)
	{
		cnt=0;
		cin>>n>>m>>k>>d;
		while(m--)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(y<=k&&y*d<z)
			{
				cnt++;
				a[cnt].ti=x;
				a[cnt].len=y;
				a[cnt].val=z;
				a[cnt].de=z-y*d;
			}
		}
		if(cnt==0)
		{
			cout<<0<<'\n';
			continue;
		}
		sort(a+1,a+1+cnt,cmp);
		cout<<a[1].de<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}