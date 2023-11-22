#include<bits/stdc++.h>
using namespace std;
int a[3001][3001];
int n,len,t[26],xb;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>len;
	for(int i=1;i<=n;i++){
		char x;xb=0;
		memset(t,0,sizeof(t));
		for(int j=1;j<=len;j++)
			cin>>x,t[x-'a']++;
		for(int j=0;j<26;j++)
			for(int k=1;k<=t[j];k++)
				a[i][++xb]=j;
	}
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=1;j<=n;j++) if(i!=j)
			if(a[i][1]>=a[j][len]){
				flag=1;
				break;
			}
		if(flag) putchar('0');
		else putchar('1');
	}
	return 0;
}
