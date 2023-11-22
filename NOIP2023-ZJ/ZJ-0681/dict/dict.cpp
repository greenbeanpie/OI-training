#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 4e3+5;
int n,m;
struct node
{
	string str;
}a[N];
void read()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].str;
}
bool cmp(char a,char b)
{
	return a>b;
}
void init()
{
	for(int i=1;i<=n;i++)
		sort(&a[i].str[0],&a[i].str[m],cmp);
}
string _down(string str)
{
	int t=0,len=str.length();
	while(t<len/2)
	{
		swap(str[t],str[len-t-1]);
		t++;
	}
	return str;
}
bool check(string a,string b)
{
	for(int i=0;i<a.length();i++)
		if(a[i]<b[i])
			return 1;
	return 0;
}
void solve()
{
	string ans="";
	for(int i=1;i<=n;i++)
	{
		bool flag=1;
		a[i].str=_down(a[i].str);
		for(int j=1;j<n;j++)
		{
			if(i==j) continue;
			flag=check(a[i].str,a[j].str);
			if(flag==0) break;
		}	
		a[i].str=_down(a[i].str);
		if(flag)
			ans+="1";
		else
			ans+="0";
	}
	cout<<ans;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	read();
	init();
	solve();
	return 0;
}
