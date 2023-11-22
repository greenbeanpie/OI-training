#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int c,N,M,Q,A[maxn],B[maxn],C[maxn],D[maxn];
bool F[maxn][maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
bool check(){
	F[0][0]=1;for(int i=1;i<=N;i++)	for(int j=1;j<=M;j++) if(C[i]>D[j]) F[i][j]=F[i-1][j-1]|F[i][j-1]|F[i-1][j];else F[i][j]=0;
	if(F[N][M]) return 1;
	F[0][0]=1;for(int i=1;i<=M;i++)	for(int j=1;j<=N;j++) if(D[i]>C[j]) F[i][j]=F[i-1][j-1]|F[i][j-1]|F[i-1][j];else F[i][j]=0;
	if(F[M][N]) return 1;
	return 0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),N=read(),M=read(),Q=read();
	for(int i=1;i<=N;i++) C[i]=A[i]=read();
	for(int i=1;i<=M;i++) D[i]=B[i]=read();
	if(check()) putchar('1');else putchar('0');
	while(Q--){
		int Len1=read(),Len2=read();
		for(int i=1;i<=N;i++) C[i]=A[i];
		for(int i=1;i<=M;i++) D[i]=B[i];
		for(int i=1;i<=Len1;i++){int x=read(),y=read();C[x]=y;}
		for(int i=1;i<=Len2;i++){int x=read(),y=read();D[x]=y;}
		if(check()) putchar('1');else putchar('0');
	}
	return 0;
}