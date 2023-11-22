#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string s,mn1[3010],mn2[3010],t[3010];
int n,m,cs[3010][30];string res,ui;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,p=0;i<=n;i++){
		cin>>s,p=0;
		for(int j=0;j<m;j++)cs[i][s[j]-'a']++;
		for(int j=26;~j;j--)for(int k=1;k<=cs[i][j];k++)t[i]+=j+'a';
	}
	mn1[1]=t[1];
	for(int i=2;i<=n;i++)mn1[i]=min(mn1[i-1],t[i]);
	mn2[n]=t[n];
	for(int i=n-1;i;i--)mn2[i]=min(mn2[i+1],t[i]);
	for(int i=1,f=1;i<=n;i++){
		ui="",f=1;
		for(int j=0;j<=26;j++)for(int k=1;k<=cs[i][j];k++)ui+=j+'a';
		if(i!=1)f&=(ui<mn1[i-1]);
		if(i!=n)f&=(ui<mn2[i+1]);
		res+=(char)(f+'0');
	}
	cout<<res;
	return 0;
}
