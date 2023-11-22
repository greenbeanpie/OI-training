#include<bits/stdc++.h>
using namespace std;
int q,n,m,a[100010],s,x,y,flag,b[100010];
char opt;
struct node {
	int val,num;
} c[100010];
int read() {
	int x=0,f=1;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if (ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-48;
	return x*f;
}
void qinkong() {
	for(int i=0; i<=n; i++) a[i]=i;
	a[100001]=100001;
	return;
}
int find(int x) {
	if (a[x]==x) return x;
	return a[x]=find(a[x]);
}
int pd(int x){
	if (x<0) x=-x;
	return x;
}
bool cmp(node a,node b){
	return pd(a.val)<pd(b.val);
}
signed main() {//si hu shi bing cha ji why I don't have zhongwen shuru fa.
	freopen("tribool1.in","r",stdin);
//	freopen("tribool.out","w",stdout);
	q=read();
	for(int T=read(); T; T--) {
		s=0;
		n=read();
		m=read();
		qinkong();
		for(int i=1; i<=m; i++) {
			scanf("%c",&opt);
			if (opt=='-') {
				x=read();
				y=read();
				a[x]=-a[y];

			} else if (opt=='+') {
				x=read();
				y=read();
				a[x]=a[y];
			} else if (opt=='T') {
				x=read();
				a[x]=100001;
			} else if (opt=='F') {
				x=read();
				a[x]=-100001;
			} else if (opt=='U') {
				x=read();
				a[x]=0;
			}
		}
		for(int i=1; i<=n; i++) {
			c[i].val=a[i],c[i].num=i;
			if (a[i]==-i) a[i]=0;
		}
		sort(c+1,c+1+n,cmp);
		for(int i=1; i<=n; i++) if (a[pd(a[c[i].num])]==0) s++,a[c[i].num]=0; //,printf("%d %d \n",i,c[i].num);
	printf("%d\n",s);
	}
	return 0;
}

