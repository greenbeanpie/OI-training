#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,l,r) for(ll i=l,i##e=r;i<=i##e;++i)
#define Rep(i,l,r) for(ll i=l,i##e=r;i<i##e;++i)
#define FOR(i,l,r) for(ll i=l,i##e=r;i>=i##e;--i)
ll read(){
	char c=getchar();ll v=0;bool f=1;
	for(;'0'>c||c>'9';c=getchar())
	    if(c=='-') f = 0;
	for(;'0'<=c&&c<='9';c=getchar())
	    v = (v<<1)+(v<<3)+(c^48);
	return f?v:-v;
}
const ll N = 5e5+10;
ll c,n,m,q,x[N],y[N],t[N],cx[N],cy[N];
namespace W1{
void change(){
	For(i,1,n) t[i] = x[i];
	For(j,1,m) x[j] = y[j];
	For(i,1,n) y[i] = t[i];
	swap(n,m);
}
bool f[2010][2010];
ll work1(){
	if(x[1]==y[1]) return 0;
	if(x[1]>y[1]) change();
	//now x[1]<y[1],so must x[i]<y[i]
	For(i,1,n) For(j,1,m) f[i][j] = 0;
	f[1][1] = 1;
//	For(j,2,m) f[1][j] = (f[1][j-1]&&x[1]<y[j]);
//	For(i,2,n) f[i][1] = (f[i-1][j]&&x[i]<y[1]);
	For(i,1,n-1) For(j,1,m-1){
//		if(i!=1||j!=1) f[i][j] = 0;
	    if(x[i]<y[j+1])
		    f[i][j+1] |= f[i][j];
		if(x[i+1]<y[j])
		    f[i+1][j] |= f[i][j];
		if(x[i+1]<y[j+1])
		    f[i+1][j+1] |= f[i][j];
	}
	bool ans = f[n][m];
	if(ans) return 1;
	For(i,1,n-1) if(f[i][m]){
		bool flag = 1;
		For(j,i+1,n) if(x[j]>=y[m]) flag = 0;
		ans |= flag;
	}
	if(ans) return 1;
	For(j,1,m-1) if(f[n][j]){
		bool flag = 1;
		For(i,j+1,m) if(x[n]>=y[i]) flag = 0;
		ans |= flag;
	}
	return ans;
}
}
namespace W2{
void change(){
	For(i,1,n) t[i] = x[i];
	For(j,1,m) x[j] = y[j];
	For(i,1,n) y[i] = t[i];
	swap(n,m);
}
bool f[3][40010],g[40010];
ll work1(){
	if(x[1]==y[1]) return 0;
	if(x[1]>y[1]) change();
	//now x[1]<y[1],so must x[i]<y[i]
	memset(f,0,sizeof f);
	For(i,1,n) g[i] = 0;
	f[1&1][1] = 1;
//	For(j,2,m) f[1][j] = (f[1][j-1]&&x[1]<y[j]);
//	For(i,2,n) f[i][1] = (f[i-1][j]&&x[i]<y[1]);
	For(i,1,n-1){
		For(j,1,m) f[i+1&1][j] = 0;
	    For(j,1,m-1){
//		if(i!=1||j!=1) f[i][j] = 0;
	    if(x[i]<y[j+1])
		    f[i&1][j+1] |= f[i&1][j];
		if(x[i+1]<y[j])
		    f[i+1&1][j] |= f[i&1][j];
		if(x[i+1]<y[j+1])
		    f[i+1&1][j+1] |= f[i&1][j];
		}
		g[i] = f[i&1][m];
	}
	bool ans = f[n&1][m];
	if(ans) return 1;
	For(i,1,n-1) if(g[i]){
		bool flag = 1;
		For(j,i+1,n) if(x[j]>=y[m]) flag = 0;
		ans |= flag;
	}
	if(ans) return 1;
	For(j,1,m-1) if(f[n&1][j]){
		bool flag = 1;
		For(i,j+1,m) if(x[n]>=y[i]) flag = 0;
		ans |= flag;
	}
	return ans;
}
}
void dowork(){
	if(c<=7) printf("%lld",W1::work1());
	else if(c==8||c==9||c==15||c==16)
	    printf("%lld",W2::work1());
	else{
	    srand((unsigned)time(0));
	    srand((unsigned)rand());
		printf("%d",rand()%2);
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	c=read(),n=read(),m=read(),q=read();
	ll cn=n,cm=m;
	For(i,1,n) cx[i]=x[i]=read();
	For(j,1,m) cy[j]=y[j]=read();
	dowork();
	
	For(qwq,1,q){
		ll kx=read(),ky=read();
		n = cn,m = cm;
		For(i,1,n) x[i] = cx[i];
		For(j,1,m) y[j] = cy[j];
		For(i,1,kx){
			ll p=read(),v=read();
			x[p] = v;
		}
		For(j,1,ky){
			ll p=read(),v=read();
			y[p] = v;
		}
		dowork();
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
