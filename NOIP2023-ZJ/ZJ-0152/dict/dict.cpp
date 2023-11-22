#include<bits/stdc++.h>
using namespace std;
int n,m;
int cntl[3010][3010],cntr[3010][3010],c[26];
char mnl[3010][3010],mnr[3010][3010],st[3010][3010];
int main()
{
	freopen("dict4.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++)st[0][i]='z'+1;
	for(i=1;i<=n;i++){
		cin>>st[i]+1;
		for(j=1;j<=m;j++)c[st[i][j]-'a']++;
		int t=0;
		for(j=25;j>=0;j--)
			while(c[j])st[i][++t]=j+'a',c[j]--;
	}
	for(i=1;i<=m;i++){
		mnl[0][i]='z'+1;
		for(j=1;j<=n;j++){
			char x=mnl[j-1][i];
			if(x==st[j][i])mnl[j][i]=x,cntl[j][i]=cntl[j-1][i]+1;
			else if(st[j][i]<x)mnl[j][i]=st[j][i],cntl[j][i]=1;
			else mnl[j][i]=x,cntl[j][i]=cntl[j-1][i];
		}
	}
	for(i=1;i<=m;i++){
		mnr[n+1][i]='z'+1;
		for(j=n;j>=1;j--){
			char x=mnr[j+1][i];
			if(x==st[j][i])mnr[j][i]=x,cntr[j][i]=cntr[j+1][i]+1;
			else if(st[j][i]<x)mnr[j][i]=st[j][i],cntr[j][i]=1;
			else mnr[j][i]=x,cntr[j][i]=cntr[j+1][i];
		}
	}
	for(i=1;i<=n;i++){
		bool f=0;
		reverse(st[i]+1,st[i]+m+1);
		for(j=1;j<=m;j++){
			if(mnl[i-1][j]<st[i][j])break;
			if(mnr[i+1][j]<st[i][j])break;
			if(st[i][j]<min(mnl[i-1][j],mnr[i+1][j])){f=1;break;}
		}
		cout<<f;
	}
}
/*
genshin!
zzrs!
*/