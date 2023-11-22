#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int n,m,sum[maxn][30],Min[maxn];
char s[maxn];
bool vis[30];
int read(){
	int ret=0,y=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*y;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		Min[i]=1e9;
		scanf("%s",s+1);
		memset(vis,0,sizeof vis);
		for(int j=1;j<=m;j++){
			if(!vis[s[j]-'a']) vis[s[j]-'a']=1,Min[i]=min(Min[i],s[j]-'a');
			sum[i][s[j]-'a']++;
		}
		for(int j=25;j>=0;j--) sum[i][j]+=sum[i][j+1];
//		printf("%d\n",Min[i]);
	}
	for(int i=1;i<=n;i++){
		bool flg=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(sum[j][Min[i]+1]>0) continue;
			if(sum[i][Min[i]]-sum[i][Min[i]+1]<sum[j][Min[i]]-sum[j][Min[i]+1]
			 &&sum[i][Min[i]+1]==0) continue;
			if(sum[i][Min[i]]-sum[i][Min[i]+1]==sum[j][Min[i]]-sum[j][Min[i]+1]
			 &&sum[i][Min[i]+1]==0&&sum[j][0]-sum[j][Min[i]]>0) continue;
			flg=0;
//			printf("%d:%d\n",i,j);
			break;
		}
		printf("%d",flg);
	}
	puts("");
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/