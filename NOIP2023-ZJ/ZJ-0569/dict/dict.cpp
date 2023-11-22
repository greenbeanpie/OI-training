#include<bits/stdc++.h>
using namespace std;
char s[3010][3010];
char qmin[3010][3010];
char qmax[3010][3010];
long long cmp1(char c1,char c2) {
	return c1<c2;
}
long long cmp2(char c1,char c2) {
	return c1>c2;
}
long long n,m;
long long comp(long long x,long long y) {
	for(long long i=1; i<=m; i++) {
		if(qmin[x][i]<qmax[y][i]) return 1;
		if(qmin[x][i]>qmax[y][i]) return 0;
	}
	return 0;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1; i<=n; i++) {
		scanf("%s",s[i]+1);
//		printf("%s\n",s[i]+1);
		for(long long j=1; j<=m; j++) {
			qmin[i][j]=s[i][j];
			qmax[i][j]=s[i][j];
		}
		sort(qmin[i]+1,qmin[i]+m+1,cmp1);
		sort(qmax[i]+1,qmax[i]+m+1,cmp2);
//		printf("%s\n",qmin[i]+1);
//		printf("%s\n",qmax[i]+1);
	}
//	cout<<endl<<endl;
	for(long long i=1; i<=n; i++) {
		long long flag=1;
//		printf("%s\n",qmin[i]+1);
		for(long long j=1; j<=n; j++) {
			if(i==j) continue;
//			printf("	%s\n",qmax[j]+1);
			if(!comp(i,j)) {
				flag=0;
				break;
			}
		}
		printf("%lld",flag);
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/