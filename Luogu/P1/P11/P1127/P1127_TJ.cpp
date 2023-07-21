#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=1e5+5;
string a[maxn];
string ans[maxn];
string now[maxn];
int sum=0;
int len[maxn];
int book[maxn];
map<char,int> s1,s2;
int n;
int flag=0;
void dfs(int last,int step)
{
	if(flag==1)
	return;
	if(step==n)
	{
		flag=1;
		for(int i=1;i<=sum;i++)
		{
			ans[i]=now[i];
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==1)
		continue;
		if(a[last][a[last].length()-1]==a[i][0])
		{
			now[++sum]=a[i];
			book[i]=1;
			dfs(i,step+1);
			sum--;
			book[i]=0;
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("P1127.in", "r", stdin);
	freopen("P1127_TJ.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		len[i]=a[i].length();
		s1[a[i][0]]++;
		s2[a[i][len[i]-1]]++;
	}	
	int start=1;
	sort(a+1,a+1+n);
	char s,t;
	for(char c='a';c<='z';c++)
	{
		if(abs(s1[c]-s2[c])==1)
		{
			if(s1[c]-s2[c]==1)
			s=c;
			else
			if(s2[c]-s1[c]==1)
			t=c;
		}
	}
	int cnt=s2[t];
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]==s && (a[i][len[i]-1]!=t || cnt!=1))
		{
			start=i;
			break;
		}
	}
	book[start]=1;
	now[++sum]=a[start];
	dfs(start,1);
	if(flag==0)
	{
		printf("***\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		cout<<ans[i]<<".";
		else
		cout<<ans[i];
	}
	return 0;
}
