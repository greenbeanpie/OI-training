#include<iostream>
#define int long long
using namespace std;
int cnt=0;
int f1[10005],f2[10005],cnt1,cnt2;
struct T{int a,b,c;}ans[100005];
void output()
{
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;++i)
		cout<<ans[i].a<<' '<<ans[i].b<<' '<<ans[i].c<<'\n';
	exit(0);
}
int p;
void work(int a,int b,int n2,int n3)
{
	int x=n2-n3;
	cnt1=cnt2=0;
	for(int i=1;i*i<=x;++i)
	{
		if(x%i)continue;
		f1[++cnt1]=i;
		if(x/i!=i)
			f2[++cnt2]=x/i;
	}
	for(int i=1;i<=cnt1;++i)
	{
		if(n2%f1[i]==n3&&f1[i]<=p)
		{
			ans[++cnt]={a,b,f1[i]};
			if(cnt==100000)
				output();
		}
	}
	for(int i=cnt2;i>=1;--i)
	{
		if(n2%f2[i]==n3&&f2[i]<=p)
		{
			ans[++cnt]={a,b,f2[i]};
			if(cnt==100000)
				output();
		}
	}
}
signed main()
{
	freopen("enumeration.in","r",stdin);
	freopen("enumeration.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,n3;
	cin>>n>>n3>>p;
	int n0=n*n+1;
	for(int a=1;a<=p;++a)
	{
		int n1=n0%a;
		for(int b=max(n3-n1,0ll);b<=p;++b)
		{
			int n2=n1+b;
			work(a,b,n2,n3);
			if(n2==n3)
			{
				for(int i=n2+1;i<=p;++i)
				{
					ans[++cnt]={a,b,i};
					if(cnt==100000)
						output();
				} 
			}
		}
	}
	output();
} 
