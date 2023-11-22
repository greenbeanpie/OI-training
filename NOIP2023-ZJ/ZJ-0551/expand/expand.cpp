#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){int ret = 0 , f = 1;char ch =getchar() ; for(;!isdigit(ch) ; ch=getchar()) if ( ch == '-')f=-f;for(;isdigit(ch) ;ch=getchar())ret = (ret<<3)+(ret<<1)+(ch & 15);return ret * f;}
const int TT = (1e9) + 7, maxn = (3005) + 5;
int n , m ,hsh[30];
int a[maxn],Max,now,b[maxn],aa[maxn],bb[maxn];
bool f[2005][2005];

inline void init(){
//	if(a[1]==b[1])f[n][m] =0;
if((a[1] - b[1]) * (a[n] -b[m]) <=0) {putchar('0');return;}
if(a[1] > b[1]){
		for(int i =1;i<=n;i++){
			if(i==1){
				for(int j =1 ;j<=m;j++){
					if(a[i] <= b[j])break;
					f[i][j] =1;
				}
			}
			for(int j =1; j<=m;j++){
				if((f[i][j-1] or f[i-1][j] or f[i-1][j-1]) and a[i]>b[j])f[i][j] =1;
//				for(int k= j;k>=1;k--){
//					if(a[i] <= b[k])break;
//					if(f[i-1][k-1] or f[i-1][k] or f[i][j-1]){f[i][j]=1;break;}
//				}
				
			}
		}
	}else if ( a[1] < b[1]){
		for(int i =1;i<=n;i++){
			if(i==1){
				for(int j =1 ;j<=m;j++){
					if(a[i] >= b[j])break;
					f[i][j] =1;
				}
			}
			for(int j =1; j<=m;j++){
				if((f[i][j-1] or f[i-1][j] or f[i-1][j-1]) and a[i]<b[j])f[i][j] =1;
//				for(int k= j;k>=1;k--){
//					if(a[i] >= b[k])break;
//					if(f[i-1][k-1] or f[i-1][k] or f[i][j-1]){f[i][j]=1;break;}
//				}
			}
		}
	}
	putchar(f[n][m] + '0');for(int i=1;i<=n;i++)for(int j =1;j<=m;j++) f[i][j]=0;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c = read();n = read(), m=read();int  t =read();
	for(int i =1 ;i<=n;i++) a[i] = read();
	for(int i = 1;i<=m;i++) b[i] = read();
	init();
	while (t--){
	for(int i =1 ;i<=n;i++) aa[i] = a[i];
	for(int i = 1;i<=m;i++) bb[i] = bb[i];
		
		int A = read(),B = read();for(int i =1;i<=A;i++){
			int x= read() , y=read();
			a[x] = y;
		}
		for(int i =1;i<=B;i++){
			int x= read() , y=read();
			b[x] = y;
		}
		init();swap(a,aa),swap(b,bb);
	}
}
