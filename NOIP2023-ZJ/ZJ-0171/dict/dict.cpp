#include<bits/stdc++.h>
using namespace std;
bool ans[6005];
long long n,m;
struct chuan
{
	int id,op;
	char c[3005];
}a[6005];
bool cmp(chuan a,chuan b)
{
//	bool flag=0;
	for(int i=1;i<=m;i++)
	{
		if(a.c[i]!=b.c[i])
			return a.c[i]<b.c[i];
	}
	
	if(a.id==b.id)
	{
		return a.op<b.op;
	}
	else
	{
		return a.op>b.op;
	}
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==1)
	{
		for(int i=1;i<=n;i++)
			cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i].c[j];
			a[i+n].c[j]=a[i].c[j];
		}
		a[i].op=1;
		a[i].id=i;
		
		a[i+n].op=2;
		a[i+n].id=i;
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<a[i].c+1<<'\n'<<a[i+n].c+1<<'\n';
		long long tong[128]={0};
		for(int j=1;j<=m;j++)
		{
			tong[a[i].c[j]]++;
		}
//		for(int i=0;i<26;i++)
//		{
//			cout<<tong[i+'a']<<'\n';
//		}
		long long cnt=0;
		for(int k='a';k<='z';k++)
		{
			for(int j=1;j<=tong[k];j++)
			{
				a[i].c[++cnt]=k;
//				cout<<a[i].c[cnt];
			}
		}
//		cout<<endl;
		cnt=0;
		for(int k='z';k>='a';k--)
		{
			for(int j=1;j<=tong[k];j++)
			{
				a[i+n].c[++cnt]=k;
			}
		}
//		cout<<a[i].c+1<<'\n'<<a[i+n].c+1<<'\n';
//		sort(a[i].c+1,a[i].c+m+1);//ji_shu_pai_xu
//		sort(a[i+n].c+1,a[i+n].c+m+1,greater<char>());
//		cout<<a[i].c+1<<'\n'<<a[i+n].c+1<<'\n';
	}
	sort(a+1,a+n+n+1,cmp);
//	for(int i=1;i<=n*2;i++)
//	{
//		cout<<a[i].c+1<<' '<<a[i].id<<' '<<a[i].op<<'\n';
//	}
	for(int i=1;i<=n*2;i++)
	{
		if(a[i].op==2)
			break;
		ans[a[i].id]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i])
			cout<<1;
		else
			cout<<0;
	}
	return 0;
}

