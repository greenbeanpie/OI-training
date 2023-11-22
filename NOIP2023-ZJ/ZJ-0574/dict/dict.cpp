#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>void read(T &x){x=0;char ch;bool f=0;while(!isdigit(ch=getchar())) f|=ch=='-';while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();x=f?-x:x;}
template<typename T1,typename ...T2>void read(T1 &x,T2& ...y){read(x);read(y...);}
int n,m;
char a[3005][3005];
int mi=1,mii=1;
bool check(int x,int y){
	for(int i=1,j=m;i<=n&&j;j--,i++){
		if(a[x][i]^a[y][j]){
			if(a[x][i]<a[y][j])return 1;
			else return 0;
		}
	}
	return 1;
}
bool rcheck(int x,int y){
	for(int i=m;i;i--){
		if(a[x][i]^a[y][i]){
			if(a[x][i]<a[y][i])return 1;
			else return 0;
		}
	}
	return 1;
}
signed main(){
//	return system("fc dict.out dict1.ans")&0;
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	read(n,m);
	if(n==1){return 0&(puts("1"));}
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		sort(a[i]+1,a[i]+1+m);
	}
	for(int i=2;i<=n;i++){
		if(rcheck(i,mi)){
			mii=mi;
			mi=i;
		}else if(rcheck(i,mii))
			mii=i;
	}
	for(int i=1;i<=n;i++){
		if(i==mi){
			putchar(check(i,mii)+48);
		}else putchar(check(i,mi)+48);
	}
	return 0;
}

