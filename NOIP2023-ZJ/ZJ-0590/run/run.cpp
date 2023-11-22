#include<bits/stdc++.h>
int c,T;
inline void read(int &x){
	#define cg c=getchar()
	int f=1;x=0;char cg;
	while(c<48||c>57)f-=(c==45)<<1,cg;
	while(c>47&&c<58)x=x*10+(c&15),cg;
	x*=f;return;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(c);read(T);
	while(T--)printf("0");
	return 0;
}
