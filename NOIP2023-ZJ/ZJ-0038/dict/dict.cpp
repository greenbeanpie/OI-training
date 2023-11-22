#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,c[N][30],L[N],R[N];
char s[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			c[i][s[j]-'a'+1]++;
		for(int j=1;j<=26;j++)
			if(c[i][j]){if(!L[i])L[i]=j;R[i]=j;}
	}for(int i=1;i<=n;i++){
		int flag=1;
		for(int j=1;j<=n;j++)
			if(i^j)if(R[j]<=L[i]){flag=0;break;}
		printf("%d",flag);
	}
}
