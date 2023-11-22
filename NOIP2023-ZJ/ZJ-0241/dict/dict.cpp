#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int siz[N][30];
int n,m;
bool checkmn(int x,int y)
{
	for(int i=25;i>=0;i--)
	{
		if(siz[x][i]>siz[y][i])	return 0;
		if(siz[x][i]<siz[y][i])	return 1;
	}
	return 1;
}
bool check(int x,int y)
{
	int totx=0;
	while(siz[x][totx]==0)	totx++;
	int toty=25;
	while(siz[y][toty]==0)	toty--;
	if(totx<toty)	return 1;
	if(totx>toty)	return 0;
	return 0;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++)
		{
			siz[i][s[j]-'a']++;
		}
	}
	int k=1;
	int kk=2;
	if(checkmn(1,2)==0)
	{
		kk=1;
		k=2;
	}
	for(int i=3;i<=n;i++)
	{
		if(checkmn(i,kk)){
			kk=i;
			if(checkmn(i,k))	swap(kk,k);
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool b=1;
		if(i==k){
			b=check(i,kk);
		}else{
			b=check(i,k);
		}
		if(b==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	cout<<"\n";
	return 0;
}




