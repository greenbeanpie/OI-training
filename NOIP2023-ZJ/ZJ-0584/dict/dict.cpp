#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define G 1
#define E 0
#define L -1

int n,m;
string w[3010];

int cmp2(string a,string b)
{
	for(int i=m-1;i>=0;i--)
	{
		if(a[i]>b[i])return G;
		else if(a[i]<b[i])return L;
	}
	return E;
}

int cmp3(string a,string b)
{
	for(int i=0;i<m;i++)
	{
		if(a[i]>b[m-i-1])return G;
		else if(a[i]<b[m-i-1])return L;
	}
	return E;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	int mini=0,maxi=0;
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
		sort(w[i].begin(),w[i].end());
		if(cmp2(w[i],w[maxi])==L)maxi=i;
	}
	for(int i=0;i<n;i++)
	{
		if(i==maxi||cmp3(w[i],w[maxi])==L)cout<<1;
		else cout<<0;
	}
	return 0;
}