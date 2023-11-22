#include <bits/stdc++.h>
using namespace std;
int n,m,ct[3001][31];
char c[3001];
int ck(int p){
	if(n==1) return 1;
	for(int i=1;i<=n;i++){
		if(i!=p){
			int a=0,b=25;
			while(ct[p][a]==0&&a<25) a++;
			while(ct[i][b]==0&&b>0) b--;
			if(a>=b) return 0;	
		}
	}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("\n%s",c+1);
		for(int j=1;j<=m;j++) ct[i][c[j]-'a']++;
	}
	for(int i=1;i<=n;i++) printf("%d",ck(i));
	return 0;
}
