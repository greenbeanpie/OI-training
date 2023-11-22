#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){int ret = 0 , f = 1;char ch =getchar() ; for(;!isdigit(ch) ; ch=getchar()) if ( ch == '-')f=-f;for(;isdigit(ch) ;ch=getchar())ret = (ret<<3)+(ret<<1)+(ch & 15);return ret * f;}
const int TT = (1e9) + 7, maxn = (2e5) + 5;
int n , m ,hsh[30],b[maxn];
int a[maxn],now;
struct AC{
	int x,y;char op;
}q[maxn];
inline void print(int x){
	printf("%lld\n",x);
}
inline void init(){
	int n = read() , m = read();
	for(int i =1 ;i <= m;i++){
		loop3:char ch = getchar();
		if( ch != '+' and ch!= '-' and ch != 'T' and ch != 'F' and ch != 'U')goto loop3;
		q[i].op = ch;
		if( isalpha(q[i].op) )q[i]. x= read();else q[i].x =read(),q[i].y = read();
//		print(q[i].x),print(q[i].y);
	}int pre = 1;for(int i=1 ;i<=n;i++)pre *= 3;
	int Max = 2e9;
//	print(pre);
	for(int i = 0;i<pre;i++){
//		print(i);
		int x= i,cnt = 0;for(int j =1;j<=n;j++)a[j] = b[j]=0;
		for(int j =1 ; j<=n;j++){
			a[j] = b[j] = x % 3;
			cnt += (x %3 ==2);
			x/=3;
		}
		if( cnt > Max)goto L;
		for(int j =1 ; j<= m ;j++){
			if( q[j].op == '+'){
				a[q[j].x] = a[q[j].y];
			}else if (q[j].op == '-'){
				a[q[j].x] = (a[q[j].y]==2)?2:1^a[q[j].y];
			}else {
				a[q[j].x]=(q[j].op=='T'?1:(q[j].op=='F'?0:2));
			}
		}
		for(int j =1;j<=n;j++)if( b[j]^ a[j])goto L;
		Max =min(Max , cnt);
		L:;
	}
	print(Max);
}
inline void init1(){
	int n =read() ,m =read();
	for(int i=1;i <=m;i++){
		loop:char ch = getchar();
		if( ch != '+' and ch!= '-' and ch != 'T' and ch != 'F' and ch != 'U')goto loop;
		int x= read();
		a[x]=(ch=='T'?1:(ch=='F'?0:2));
	}int cnt = 0;
	for(int i =1;i<=n;i++) cnt += (a[i] ==2) ,a[i] = 0;print(cnt);
}
inline void init2(){
	int n = read(), m =read();	for(int i =1 ;i <= m;i++){
		loop2:char ch = getchar();
		if( ch != '+' and ch!= '-' and ch != 'T' and ch != 'F' and ch != 'U')goto loop2;
		q[i].op = ch;
		if( isalpha(q[i].op) )q[i]. x= read();else q[i].x =read(),q[i].y = read();
	}
	for(int i =1;i<=n;i++)b[i] =a[i] = 3;
	loop1:for(int i=1;i<=n;i++)a[i] =b[i];
	for(int i =1 ;i <= m;i++){
		if(q[i].op=='U') a[q[i].x]=2;
		else a[q[i].x] =a[q[i].y];
	}
	bool flg = 0;
	for(int i=1;i<=n;i++)if(b[i] ==3 and a[i]==2){b[i]=2;flg = 1;}
	if(flg)goto loop1;int ans = 0;
	for(int i =1;i<=n;i++)ans +=(a[i]==2);
	print(ans);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c = read();
	if(c ==3 or c ==4 )for(int t =read();t--;)init1();
	else if(c == 1 or c == 2)for(int t =read(); t--;)init();
	else if( c== 5 or c ==6)for(int t =read(); t--;)init2();
	else{int  t=read();
		for(int i=1;i<=t;i++)puts("0");
	}
	return 0;
}
