#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int a[maxn][maxn],b[maxn][maxn];
int n,m;
bool check(char c){
	if(c>'z'||c<'a') return 1;
	return 0; 
}
bool cmp(int a,int b){
	return a>b;
}
char c;
int ans[maxn][2],pla[maxn],res[maxn];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		ans[i][1]=ans[i][0]=1e9;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c=getchar();
			while(check(c)) c=getchar();
			b[i][j]=a[i][j]=c-'a';
		}
		sort(a[i]+1,a[i]+m+1);
		for(int j=1;j<=m;j++){
			b[i][j]=a[i][m-j+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]<ans[j][0]){
				ans[j][1]=ans[j][0];
				ans[j][0]=b[i][j];
				pla[j]=i;
			}
			else if(b[i][j]<ans[j][1]){
				ans[j][1]=b[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(pla[j]==i){
				if(ans[j][1]<a[i][j]) {
					res[i]=-1;
					break;
				}
				else if(ans[j][1]>a[i][j]) {
					res[i]=1;
					break;
				}
			}
			else {
				if(ans[j][0]<a[i][j]){
					res[i]=-1;
					break;
				}
				else if(ans[j][0]>a[i][j]){
					res[i]=1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(res[i]<=0) {
			printf("0");
		}
		else printf("1");
	}
	return 0;
}
