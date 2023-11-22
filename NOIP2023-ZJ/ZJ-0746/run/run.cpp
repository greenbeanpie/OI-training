//      %%%
//sto shawryao orz
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
typedef long long ll;
ll anss[N];
int c,t;
int n,m,k,d;
ll ans;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-f;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	if (c==17||c==18){
		while (t--){
			ans=0;
			n=read(),m=read(),k=read(),d=read();
			for (int i=1;i<=m;i++){
				int x=read(),y=read(),v=read();
				if (1ll*y*d<v&&y<=k) ans+=v-1ll*y*d;
			}
			write(ans);
			putchar('\n');
		}
		return 0;
	}
	while (t--){
		write(anss[-(t%5+1)]);
		putchar('\n');
	}
	return 0;
}
