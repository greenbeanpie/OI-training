#include<bits/stdc++.h>
using namespace std;
int q,n,m,a[100010],s,x,y,flag,b[100010];
char opt;
int read() {
	int x=0,f=1;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if (ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-48;
	return x*f;
}
int find(int x){
	if (a[x]==x) return x;
	return a[x]=find(a[x]);
}
signed main() {//si hu shi bing cha ji why I don't have zhongwen shuru fa.
//	freopen("tribool3.in","r",stdin);
//	freopen("tribool.out","w",stdout);
	q=read();
	for(int T=read(); T; T--) {
		s=0;
		n=read();
		m=read();
		for(int i=0; i<=n; i++) a[i]=i;
		for(int i=1; i<=m; i++) {
			scanf("%c",&opt); 
			if (opt=='+') {
				x=read();
				y=read();
				a[x]=find(y);
			} 
			else if (opt=='U') {
				x=read();
				a[x]=0;
			}
		}
		for(int i=1;i<=n;i++) if (a[find(i)]==0) s++;
		printf("%d\n",s);
	}
	return 0;
}

