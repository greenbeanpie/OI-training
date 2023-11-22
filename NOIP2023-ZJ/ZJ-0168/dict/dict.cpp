#include<bits/stdc++.h>
#define N 3005
using namespace std;
int n,m;
char s[N][N],ans[N];
int cmp(char x,char y){
	return x>y;
}
int check(int x){
	for(int i=1;i<=m;i++)
		if(ans[i]<s[x][i])return 0;
			else if(ans[i]>s[x][i])return 1;
	return 1;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		sort(s[i]+1,s[i]+m+1,cmp);
		if(i==1)for(int j=1;j<=m;j++)ans[j]=s[i][j];
			else if(check(i))for(int j=1;j<=m;j++)ans[j]=s[i][j];
	}
	for(int i=1;i<=n;i++){
		reverse(s[i]+1,s[i]+m+1);
		printf("%d",check(i));
	}
	return 0;
}

