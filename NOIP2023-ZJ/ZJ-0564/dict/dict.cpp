#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
char mx[N][N],mn[N][N];
int a[27];
int tr[N*N][26],cnt[N*N];
int id;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(!(c^'-')) f^=1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^'0');c=getchar();}
	return (f?s:~(s-1));
}
void insert(char s[]){
	int p=0;
	for(int i=1;i<=m;i++){
		int t=s[i]-'a';
		if(!tr[p][t]) tr[p][t]=++id;
		p=tr[p][t];
		cnt[p]++;
	}
}
bool check1(char s[]){
	int p=0;
	int sum=0;
	for(int i=1;i<=m;i++){
		int t=s[i]-'a';
		for(int j=0;j<t;j++) sum+=cnt[tr[p][j]];
		if(!tr[p][t]) break;
		p=tr[p][t];
	}
	//if(cnt[p]) sum+=cnt[p];
	if(sum) return 0;
	else return 1;
}
bool check(int x,int y){
	for(int i=1;i<=m;i++){
		if(mn[x][i]<mx[y][i]) return 1;
		if(mn[x][i]>mx[y][i]) return 0;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	int sum=0;
	for(int i=1;i<=n;i++){
		memset(a,0,sizeof a);
		char c;
		for(int j=1;j<=m;j++){
			c=getchar();
			while(c<'a'||c>'z') c=getchar();
			a[c-'a']++;
			sum++;
		}
		int cnt=0;
		for(int j=0;j<26;j++){
			for(int k=1;k<=a[j];k++) mn[i][++cnt]=j+'a',sum++;
		}
		cnt=0;
		for(int j=25;j>=0;j--){
			for(int k=1;k<=a[j];k++) mx[i][++cnt]=j+'a',sum++;
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(!check(i,j)){
				printf("%d",0);
				flag=0;
				break;
			}
		}
		if(flag) printf("%d",1);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<mx[i][j];
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<mn[i][j];
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++) insert(mx[i]);
//	for(int i=1;i<=n;i++){
//		if(!check1(mn[i])) printf("%d",0);
//		else printf("%d",1);
//	}
	return 0;
}