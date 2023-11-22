#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[3010][28];
int b[3010][2];//b[k][0]min b[k][1]max
int c[2][3],f=0;
int ans[3010];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(c,0xF,sizeof(c));
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		char t;
		for(int j=1; j<=m; j++) {
			t=getchar();
			if(t-'a'+1<0) {
				j--;
				continue;
			}
			a[i][t-'a'+1]++;
		}
	}
	if(n==1) {
		for(int i=1; i<=n; i++) {
			printf("1");
		}
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=26; j++) {
			if(a[i][j]>0) {
				b[i][0]=j;
				break;
			}
		}
		for(int j=26; j>=1; j--) {
			if(a[i][j]>0) {
				b[i][1]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i][1]<=c[f][1]){
			f=1-f;
			c[f][1]=b[i][1];
			c[f][2]=i;
		}
	}
	for(int i=1; i<=n; i++) {
		int t=1;
		if(c[f][2]!=i){
			if(c[f][1]<=b[i][0]){
				t=0;
			}
		}else{
			if(c[1-f][1]<=b[i][0]){
				t=0;
			}
		}
		ans[i]=t;
	}
	for(int i=1; i<=n; i++) {
		printf("%d",ans[i]);
	}
	return 0;
}
