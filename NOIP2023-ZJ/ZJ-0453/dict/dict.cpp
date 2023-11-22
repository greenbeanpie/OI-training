#include<bits/stdc++.h>
#define LL long long
#define push_back pb
#define mk make_pair
#define debug cout<<"------------------------\n";
#define fi first
#define se second
#define ls s*2
#define rs s*2+1
#define mid (l+r)/2
#define tol ls,l,mid
#define tor rs,mid+1,r
using namespace std;
const int M=3030;
int n,m;
string s;
int a[M][M];
int b[M][M];
int t[M];
int mx[M];
int tot;
bool cmp(int x,int y){
	return x>y;
}
int check(int x){
	for(int i=1;i<=m;++i)
		if(mx[i]>a[x][i]) return -1;
		else if(mx[i]<a[x][i]) return 1;
	return 0;
}
int check2(int x){
	for(int i=1;i<=m;++i)
		if(mx[i]>b[x][i]) return -1;
		else if(mx[i]<b[x][i]) return 1;
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>s;
		for(int j=0;j<s.size();++j)
			a[i][j+1]=b[i][j+1]=(int)s[j]-'a';
		sort(a[i]+1,a[i]+m+1);
		sort(b[i]+1,b[i]+m+1,cmp);
	}
	for(int i=1;i<=m;++i) mx[i]=b[1][i];
	tot=1;
	for(int i=2;i<=n;++i){
		int op=check2(i);
		if(op==-1) {
			for(int j=1;j<=m;++j)
				mx[j]=b[i][j];
			tot=1;
		} else
		if(op==0) ++tot;
	}
	LL ans=0;
	for(int i=1;i<=n;++i){
		int op=check(i);
		if(op==-1) printf("1");
		else if(op==0&&tot==1) printf("1");
		else printf("0");
	}
//	cout<<ans;
	return 0;
}
//1526
