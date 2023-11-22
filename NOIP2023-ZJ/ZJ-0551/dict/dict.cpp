#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){int ret = 0 , f = 1;char ch =getchar() ; for(;!isdigit(ch) ; ch=getchar()) if ( ch == '-')f=-f;for(;isdigit(ch) ;ch=getchar())ret = (ret<<3)+(ret<<1)+(ch & 15);return ret * f;}
const int TT = (1e9) + 7, maxn = (3005) + 5;
int n , m ,hsh[30];
string a[maxn],Max,now;
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);cin.tie(0);
	n = read() , m = read();if(n==1){
		return puts("1"),0;
	}
	for(int i = 1 ;i<=n ;i++)cin>>a[i];
	for(int i = 1 ;i<=n;i++){
		memset(hsh,0,sizeof hsh);
		for(int j=0;j<m;j++)hsh[a[i][j] - 'a' + 1]++;
		now = "";
		for(int j= 26;j;j--)	while(hsh[j]--)now += j + 'a' -1;
		if(i==1)Max = now;
		if(Max > now) Max = now;
	}
	for(int i=1 ;i<=n;i++){
		memset(hsh,0,sizeof hsh);
		for(int j=0;j<m;j++)hsh[a[i][j] - 'a' + 1]++;
		now = "";
		for(int j= 1;j<=26;j++)	while(hsh[j]--)now += j + 'a' -1;
		putchar((now <= Max)+'0');
	}
	puts("");return 0 ;
}
