#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+5;
inline ll read() {
	ll f=1,x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f*x;
}
int n,m;
char s[N][N],ma[N][N],mi[N][N];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	if (n==1) {
		printf("1");
		return 0;
	}
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++) 
			mi[i][j]=s[i][j];
		sort(mi[i]+1,mi[i]+m+1);
		for (int j=m;j>=1;j--) ma[i][m-j+1]=mi[i][j];
	}
	for (int i=1;i<=n;i++) {
		int op=1;
		for (int j=1;j<=n;j++) {
			if (i==j) continue;
			for (int t=1;t<=m;t++) {
				if (mi[i][t]>ma[j][t]) {
					op=0;
					break;
				} else if (mi[i][t]<ma[j][t])  break;
			}
			if (!op) break;
		}
		printf("%d",op);
	}
	return 0;
}
