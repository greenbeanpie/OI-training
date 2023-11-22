#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	char w[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	if(n==1) cout<<"1"<<endl;
	else if(n!=1&&m==1)
	{
		int minn=1;
		for(int i=2;i<=n;i++)
		{
			if(w[i]<w[minn]) minn=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=minn) cout<<"0";
			else cout<<"1";
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
