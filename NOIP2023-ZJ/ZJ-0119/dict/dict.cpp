#include<bits/stdc++.h>
using namespace std;
int const N=3010;
int n,m;
string s,t1[N],t2[N],pre[N],suf[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		t1[i].resize(m);
		t2[i].resize(m);
		int c[26]={0};
		for(char j:s)
			c[j-97]++;
		for(int j=0,p=0;j<26;j++)
			for(int k=c[j];k--;)
				t1[i][p++]=j+97;
		for(int j=25,p=0;j>=0;j--)
			for(int k=c[j];k--;)
				t2[i][p++]=j+97;
	}
	pre[0]=suf[n+1]="~";
	for(int i=1;i<=n;i++)
		pre[i]=min(pre[i-1],t2[i]);
	for(int i=n;i;i--)
		suf[i]=min(suf[i+1],t2[i]);
	for(int i=1;i<=n;i++)
		cout<<(t1[i]<min(pre[i-1],suf[i+1]));
	cout<<"\n";
}
