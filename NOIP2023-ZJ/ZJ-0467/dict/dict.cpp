#include<bits/stdc++.h>
using namespace std;
char ch[3001][3001],ch2[3001][3001],minn[3001];
int n,m,id=1;
inline bool pd(char a[],char b[]){
	for(int k=1;k<=m;k++){
		if(a[k]<b[k]) return 0;
		else if(a[k]>b[k]) return 1;
	}
	return 0;
}
inline bool cmp(char a,char b){
	return a<b;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		sort(ch[i]+1,ch[i]+m+1,cmp);
		for(register int j=1;j<=m;j++) ch2[i][j]=ch[i][m-j+1];
	}
	for(int i=1;i<=n;i++){
		if(pd(ch2[id],ch2[i])) id=i;
	}
	for(int i=1;i<=n;i++){
		if(i==id) printf("1");
		else{
			if(pd(ch[i],ch2[id])){
				printf("0");
			}
			else printf("1");
		}
	}
}
