#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=3e3+10;
const ull M=998244853;
int n,m;
int c[N][26];
ull hash_minn[N][N],hash_maxx[N][N];
char minn[N][N],maxx[N][N];
inline int read_int(){
	char ch=getchar();
	int ret=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
inline char read_char(){
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	return ch;
}
inline bool check(const int &x,const int &y){
	int l=1,r=m,ret=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(hash_minn[x][mid]==hash_maxx[y][mid]){
			ret=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(ret==m)return 0;
	return minn[x][ret+1]<maxx[y][ret+1]; 
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read_int(),m=read_int();
	for(int i=1,cnt;i<=n;i++){
		for(int j=1;j<=m;j++)
			c[i][read_char()-'a']++;
		cnt=0;
		for(int j=0;j<26;j++){
			char ls=(j+'a');
			for(int k=1;k<=c[i][j];k++){	
				minn[i][++cnt]=ls;
				hash_minn[i][cnt]=hash_minn[i][cnt-1]*M+ls;
			}
		}
		cnt=0;
		for(int j=25;j>=0;j--){
			char ls=(j+'a');
			for(int k=1;k<=c[i][j];k++){
				maxx[i][++cnt]=ls;
				hash_maxx[i][cnt]=hash_maxx[i][cnt-1]*M+ls;
			}
		}
	}
	for(int i=1;i<=n;i++){
		bool flg=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(!check(i,j)){
				flg=0;
				break;
			}
		}
		if(flg)putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}
/*
9:02 dayangli all accepted
nice 
9:05 next problem
*/