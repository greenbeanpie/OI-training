#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = (l); i <= (r); ++i)
#define per(i,r,l) for(int i = (r); i <= (l); --i)
#define N 3005
using namespace std;

int read(){
	int x = 0, w = 1; char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x<<1) + (x<<3) + (ch^48), ch = getchar();
	return x*w;
}

int n,m,pos;
char ch[N];
int a[N][N],b[N],mx1[N],mx2[N],ans[N];

bool cmp(int x,int y){
	return x > y;
}
bool check(int a[],int b[]){
	rep(i,1,m) {
		if(a[i] > b[i]) return 0;
		else if(a[i] < b[i]) return 1;
	}
	return 0;
}

signed main(){
	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	n = read(); m = read();
	rep(i,1,n) mx1[i] = 1e9, mx2[i] = 1e9;
	rep(i,1,n){
		scanf("%s",ch + 1);
		rep(j,1,m) a[i][j] = ch[j] -'a'+1,b[j] = a[i][j];
		sort(b+1,b+1+m,cmp); 
		if(check(b,mx1)) {
			rep(j,1,m) mx2[j] = mx1[j], mx1[j] = b[j];  
			pos = i;
		}
		else if(check(b,mx2)){
			rep(j,1,m) mx2[j] = b[j];
		}
	}
	rep(i,1,n){
		rep(j,1,m) b[j] = a[i][j];
		sort(b+1,b+1+m);
		if(i == pos){
			if(check(b,mx2)) ans[i] = 1;
		}
		else{
			if(check(b,mx1)) ans[i] = 1;
		}
	}
	rep(i,1,n) printf("%d",ans[i]);
	return 0;
}
