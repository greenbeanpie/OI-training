#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int N,M,id[maxn];
int A[maxn][maxn],B[maxn][maxn];
char S[maxn][maxn],T[maxn][maxn];
bool cmp(int x,int y){
	for(int i=1;i<=M;i++)
	 if(B[x][i]<B[y][i]) return 1;else
	 if(B[x][i]>B[y][i]) return 0;
	return 1;
}
bool check(int x){
	for(int i=1;i<=M;i++)
	 if(A[x][i]<B[id[1]][i]) return 1;else
	 if(A[x][i]>B[id[1]][i]) return 0;
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		id[i]=i;
		scanf("%s",S[i]+1);
		for(int j=1;j<=M;j++) A[i][j]=S[i][j]-'a'+1;
		sort(A[i]+1,A[i]+1+M);
		for(int j=1;j<=M;j++) B[i][j]=A[i][M-j+1];
	}
	for(int i=2;i<=N;i++) if(cmp(i,id[1])) id[1]=i;
//	sort(id+1,id+1+N,cmp);
	for(int i=1;i<=N;i++)
	 if(check(i)) putchar('1');else putchar('0');
	putchar('\n');
//	cerr<<clock()<<endl;
	return 0;
}