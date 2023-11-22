#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,m,a,b;
long long sum,num;
char v;
int x[1000001];
int s[1000001];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		for(int i=1;i<=10000;i++)
		x[i]=0;
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>v;
			if(v=='U')
			{
				cin>>a;
				x[a]=2;
				sum++;
			}
			else if(v=='+')
			{
				int x1,x2;
				cin>>x1>>x2;
				if(x[x1]==2&&x[x2]!=2)
				sum--;
				if(x[x1]!=2&&x[x2]==2)
				sum++;
			}
		}
		cout<<sum<<endl;
	}
}
