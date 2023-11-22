#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
const int N=3005;
int n,m,tp;
char a[N][N],b[N][N],mn[N];
bool check(int y){
	for(register int i=1; i<=m; i++){
		if(mn[i]==b[y][i]) continue;
		else return mn[i]>b[y][i];
	}
	return 0;
}
void cop(int x){
	for(register int i=1; i<=m; i++) mn[i]=b[x][i];
}
bool check2(int x){
	for(register int i=1; i<=n; i++){
		if(a[x][i]>mn[i]) return 0;
		else if(a[x][i]<mn[i]) return 1;
	}
	return 1;
}
void sor1(int x){
//	for(int i=1; i<=m; i++) cout<<b[x][i];
//	cout<<endl;
	int cc[30];
	for(register int i=0; i<30; i++) cc[i]=0;
	for(register int i=1; i<=m; i++) cc[b[x][i]-'a']++;
	int tp='z'-'a';
	for(register int i=1; i<=m; i++){
		while(!cc[tp]) tp--;
		b[x][i]=tp+'a',cc[tp]--;
	}
//	for(int i=1; i<=m; i++) cout<<b[x][i];
//	cout<<endl;
}
void sor2(int x){
//	cout<<x<<":"<<endl;
//	for(int i=1; i<=m; i++) cout<<a[x][i];
//	cout<<endl;
	int cc[30];
	for(register int i=0; i<30; i++) cc[i]=0;
	for(register int i=1; i<=m; i++) cc[a[x][i]-'a']++;
	int tp=0;
	for(int i=1; i<=m; i++){
		while(!cc[tp]) tp++;
		a[x][i]=tp+'a',cc[tp]--;
	}
//	for(int i=1; i<=m; i++) cout<<a[x][i];
//	cout<<endl;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(register int i=1; i<=n; i++) scanf("%s",a[i]+1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) b[i][j]=a[i][j];
		sor1(i);
	}
	cop(1);
	for(register int j=2; j<=n; j++)
		if(check(j)) cop(j),tp=j;
//	for(int i=1; i<=m; i++ )cout<<mn[i];
//	cout<<endl;
	for(register int i=1; i<=n; i++){
		sor2(i);
//		for(int j=1; j<=m; j++) cout<<a[i][j];
//		cout<<endl;
		if(check2(i)) printf("1");
		else printf("0");
	}
}
