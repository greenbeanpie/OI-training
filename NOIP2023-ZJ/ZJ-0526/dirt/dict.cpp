#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=3e3+10;
int n,m,idx,ans[MAXN],flag=0;
char s[MAXN][MAXN];
bool cmp(char a,char b){
	return a>b;
}
bool cop(int x,int y){
	for(int i=1;i<=m;i++){
		if(s[x][i]<s[y][i])return 1;
		if(s[x][i]>s[y][i])return 0;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dirt.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		sort(s[i]+1,s[i]+m+1,cmp);
		if(!idx||cop(i,n+1)){
			for(int j=1;j<=m;j++){
				s[n+2][j]=s[n+1][j];
			}
			idx=i;
			for(int j=1;j<=m;j++){
				s[n+1][j]=s[i][j];
			}
		}else if(!flag||cop(i,n+2)){
			for(int j=1;j<=m;j++){
				s[n+2][j]=s[i][j];
			}
			flag=1;
		}
		sort(s[i]+1,s[i]+m+1);
	}
	if(n==1){printf("1\n"); return 0;}
	for(int i=1;i<=n;i++){
		if(i!=idx&&cop(i,n+1))ans[i]=1;
		else if(i==idx&&cop(i,n+2))ans[i]=1;
		else ans[i]=0;
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}