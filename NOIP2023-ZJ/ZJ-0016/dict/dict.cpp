#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,cnt[N][30],fir[N],lst[N];char s[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)++cnt[i][s[j]-'a'];
		for(int j=0;j<26;j++)if(cnt[i][j]){fir[i]=j;break;}
		for(int j=25;j>=0;j--)if(cnt[i][j]){lst[i]=j;break;}
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++)
			if(j!=i&&fir[i]>=lst[j])flag=0;
		putchar('0'+flag);
	}
	return 0;
}