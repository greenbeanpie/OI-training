#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){int ret = 0 , f = 1;char ch =getchar() ; for(;!isdigit(ch) ; ch=getchar()) if ( ch == '-')f=-f;for(;isdigit(ch) ;ch=getchar())ret = (ret<<3)+(ret<<1)+(ch & 15);return ret * f;}
const int TT = (1e9) + 7, maxn = (1e5) + 5,inf = -1e13;
int n , m ,hsh[30],k,d;
int a[maxn];
int L[maxn], R[maxn],w[maxn];
inline void init(){
	int Max =0;
	n = read(), m =read(),k = read(), d=read();
	for(int i=1;i<=m;i++){
		int x =read() , y=read(), v=read();
		L[i] = x - y + 1, R [i] = x;w[i] =v;
	}
	for(int i= 0;i<(1<<n);i++){
		int x = i,now =0;
		for(int j = 1;j<=n;j++,x>>=1)now -= d* (a[j] = x & 1);
		for(int p=1;p +k<=n;p++){
			for(int j =0;j<=k;j++)if(!a[j+p])goto loop1;
			goto loop2;loop1:;
		}
		for(int j=1;j<=m;j++){
			for(int k=L[j];k<=R[j];k++)if(!a[k])goto loop;
			now += w[j];loop:;
		}
		if(now > Max)Max =now;
		loop2:;
	}
	printf("%lld\n",Max);
}
inline void init1(){
	int ans =0;
	n = read(), m =read(),k = read(), d=read();
	for(int i=1;i<=m;i++){
		int x =read() , y=read(), v=read();
		int l = x - y + 1, r = x;
		if( r - l>= k)continue;
		if(d * ( r - l + 1) <= v)ans+=v -  d* (r - l + 1);
	}
	printf("%lld\n",ans);
}
//bool vis[maxn];int lne[maxn],now[maxn];mt19937 rd (time(0));
//inline bool check(){
//	int A = 0,id = 0;
//	for(int i=1;i<=n;i++){
//		A += lne[i];
//		if( A== 0) id = i;
//		if( i - id >= k )return 0;
//	}return 1;
//	
//}
//inline int calc(){
//	int A = 0,id = 0;
//	for(int i=1;i<=n;i++){
//		a[i]=a[i-1]+lne[i];
//	}
//	int ret =0;
//	for(int j=1;j<=m;j++){
//		for(int k=L[j];k<=R[j];k++)if(!a[k])goto loopp;
//		ret += w[j];loopp:;
//	}return ret;
//}
//inline void init2(){
//	n = read(), m =read(),k =read(), d=read();
//	for(int i=1;i<=m;i++){
//		int x =read() , y=read(), v=read();
//		L[i] = x - y + 1, R [i] = x;w[i] =v;
//	}
//	double now =clock(),xd = now + 0.15 * CLOCKS_PER_SEC;int Max = 0;
//	for(int i =1;i<=m;i++)if(vis[i] = rd() &1)lne[L[i]]++,lne[R[i]+1]--;
//	while(clock() < xd){
//	int Maxq = 0;
//		for(double t =114514;t<=1e-5;t*=0.985){
//			int x= rd() % n +1;
//			if(vis[x])lne[L[x]]--,lne[R[x]+1]++;else ++lne[L[x]],--lne[R[x]+1];
//			vis[x] ^=1;
//			if(!check())continue;
//			int ne = calc();Maxq = max(Maxq,ne);
//			if( exp(-ne+Max)/t * RAND_MAX>rand() ){
//				if(vis[x])lne[L[x]]--,lne[R[x]+1]++;else ++lne[L[x]],--lne[R[x]+1];
//				vis[x] ^=1;
//			}
//		}
//		Max = max(Max, Maxq);
//	}
//	printf("%lld\n",Max);
//	memset(lne,0,sizeof lne);memset(vis,0,sizeof vis);
//}
main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c =read();
	if(c==1 or c ==2)for(int  t =read(); t--;)init();
	else {
		for(int  t =read(); t--;)init1();
	}return 0;
}
// wish this will be a good ending
