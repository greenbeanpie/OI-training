#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define ull unsigned ll
#define Tp template<typename _T>
Tp _T mabs(_T x){ return x<0?-x:x; }
Tp _T mmin(_T x,_T y){ return x<y?x:y; }
Tp _T mmax(_T x,_T y){ return x<y?y:x; }
Tp void mswap(_T &x,_T &y){ _T t=x; x=y; y=t; return; }
using namespace std;
#define maxn 3039
int n,m; char s[maxn][maxn];
int cmp(char x,char y){ return x>y; }
int check(int x,int y){
	int i;
	for(i=1;i<=m;i++) if(s[x][i]!=s[y][i]) return s[x][i]<s[y][i];
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.ans","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin>>n>>m; int i,j,flag;
	for(i=1;i<=n;i++){ cin>>(s[i]+1); sort(s[i]+1,s[i]+m+1,cmp); }
	for(i=1;i<=n;i++){
		reverse(s[i]+1,s[i]+m+1);
		flag=1;
		for(j=1;j<=n;j++) if(i!=j) if(!check(i,j)) flag=0;
		reverse(s[i]+1,s[i]+m+1);
		cout<<flag;
	} cout<<'\n';
	return 0;
}
