#include<bits/stdc++.h>
using namespace std;
string st;
int a;
int Min[6001],Max[6001],B[6001];
int n,m;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		getline(cin,st);
		Min[i]='z';
		Max[i]='a';
		for(int j=1;j<=m;j++)
		{
			a=getchar();
			Min[i]=min(Min[i],a);
			Max[i]=max(Max[i],a);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		if(j!=i)
		{
			if(Max[j]<=Min[i])
			{
				B[i]=1;
				break;
			}
		}
		putchar(!B[i]+'0');
	}
	return 0;
}