#include<bits/stdc++.h>
using namespace std;
int n,m;
char st[3010][3010];
string s[3010];
int main(){
	// double stm=clock();
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("1\n");return 0;
	}
	for(int i=1;i<=n;++i){
		scanf("%s",st[i]+1);
		sort(st[i]+1,st[i]+m+1);reverse(st[i]+1,st[i]+m+1);
		for(int j=1;j<=m;++j) s[i]+=st[i][j];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;++i){
		string tmp;
		for(int j=m;j>=1;--j) tmp+=st[i][j];
		if(tmp<=s[1]&&tmp<s[2]) printf("1");else printf("0");
	}
		// cerr<<(clock()-stm)/CLOCKS_PER_SEC<<"\n";
	return 0;
}