#include <bits/stdc++.h>
using namespace std;

int n,m;
//int s[3010][30];
char w;
bool pd=1;
vector <int> g[3010];
//multiset <char> g[3010];

bool comp(int i)
{
	pd=1;
	for(int j=1;j<=n;j++)
	{
		if(j==i) continue;
		pd=1;
		for(int k=0;k<m;k++)
		{
			if(!pd) continue;
			int l=m-k-1;
			if(g[i][k]>g[j][l]) return 0;
			if(g[i][k]<g[j][l]) pd=0;
		}
	}
	return 1;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>w;
			//g[i].push(w);
			g[i].push_back((int)(w-'a'));
			//s[i][w-'a']++;
		}
		sort(g[i].begin(),g[i].end());
	}
	pd=1;
	for(int i=1;i<=n;i++)
		cout<<comp(i);
	cout<<endl;
	return 0;
}