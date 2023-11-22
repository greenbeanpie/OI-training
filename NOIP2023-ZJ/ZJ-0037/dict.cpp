#include <bits/stdc++.h>
using namespace std;
constexpr int max_n=/*3000*/6000;
int mx[max_n+1],mn[max_n+1];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i){
		mx[i]=0,mn[i]=256;
		for(int j=1,ch; j<=m; ++j)
			if((ch=getchar()^96)<=26){
				if(ch>mx[i])
					mx[i]=ch;
				if(ch<mn[i])
					mn[i]=ch;
			}
			else
				--j;
	}
	for(int i=1; i<=n; ++i){
		bool flg=1;
		for(int j=1; j<=n; ++j)
			if(j!=i&&mx[j]<=mn[i]){
				flg=0;
				break;
			}
		putchar(int(flg)|'0');
	}
	putchar('\n');
	return 0;
}