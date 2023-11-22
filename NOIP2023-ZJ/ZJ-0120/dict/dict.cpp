#include<bits/stdc++.h>
using namespace std;
#define ll int
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
const ll N = 3010;
ll n,m;
char a[N<<1][N];
void rcopy(ll to,ll fm){
	For(j,1,m) a[to][j]=a[fm][m-j+1];
}
ll bs[30];
void dsort(ll wh){
	For(i,0,25) bs[i] = 0;
	For(j,1,m) ++bs[a[wh][j]-'a'];
	ll now = 0;
	For(i,0,25) for(;bs[i];--bs[i])
	    a[wh][++now] = i+'a';
}
ll fr[N<<1],ft[N<<1];
void asort(){
	ll nn = 2*n;
	For(i,1,nn) fr[i] = i;
	FOR(j,m,1){
	    For(i,0,25) bs[i] = 0;
	    For(i,1,nn) ++bs[a[i][j]-'a'];
	    For(i,1,25) bs[i] += bs[i-1];
		FOR(i,nn,1){
			ll now = bs[a[fr[i]][j]-'a']--;
			ft[now] = fr[i];
		}
		For(i,1,nn) fr[i] = ft[i];
//		For(i,1,nn) printf("%lld ",fr[i]);puts("");
	}
}
void print(ll wh){
	For(j,1,m) printf("%c",a[wh][j]);puts("");
}
bool ok[N];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
//	ll fir = clock();
	n=read(),m=read();
	For(i,1,n) scanf("%s",a[i]+1);
	
	//warn : int = ll
//	if(n==1) puts("1");else{
//	For(i,1,n) a[i].i = i;
	For(i,1,n) dsort(i);
	For(i,1,n) rcopy(i+n,i);
//	For(i,1,n) print(i);
	asort();
	ll cnt = 0;
	FOR(i,2*n,1){
		if(fr[i]>n) ++cnt;
		if(fr[i]<=n) ok[fr[i]] = (cnt==n);
	}
	For(i,1,n) printf("%d",ok[i]);
//	}
//	cerr<<clock()-fir;
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define ll int
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
const ll N = 3010;
ll n,m;
struct Node{
	char s[N];
	ll i;
}a[N<<1];
void rcopy(ll to,ll fm){
	a[to].i = a[fm].i;
	For(j,1,m) a[to].s[j]=a[fm].s[m-j+1];
}
ll bs[30];
void dsort(ll wh){
	For(i,0,25) bs[i] = 0;
	For(j,1,m) ++bs[a[wh].s[j]-'a'];
	ll now = 0;
	For(i,0,25) for(;bs[i];--bs[i])
	    a[wh].s[++now] = i+'a';
}
ll fr[N<<1],ft[N<<1];
void asort(){
	ll nn = 2*n;
	For(i,1,nn) fr[i] = i;
	FOR(j,m,1){
	    For(i,0,25) bs[i] = 0;
	    For(i,1,nn) ++bs[a[i].s[j]-'a'];
	    For(i,1,25) bs[i] += bs[i-1];
		FOR(i,nn,1){
			ll now = bs[a[fr[i]].s[j]-'a']--;
			ft[now] = fr[i];
		}
		For(i,1,nn) fr[i] = ft[i];
//		For(i,1,nn) printf("%lld ",fr[i]);puts("");
	}
}
void print(ll wh){
	For(j,1,m) printf("%c",a[wh].s[j]);puts("");
}
bool ok[N];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	n=read(),m=read();
	For(i,1,n) scanf("%s",a[i].s+1);
	
	//warn : int = ll
//	if(n==1) puts("1");else{
	For(i,1,n) a[i].i = i;
	For(i,1,n) dsort(i);
	For(i,1,n) rcopy(i+n,i);
//	For(i,1,n) print(i);
	asort();
	ll cnt = 0;
	FOR(i,2*n,1){
		if(fr[i]>n) ++cnt;
		if(fr[i]<=n) ok[fr[i]] = (cnt==n);
	}
	For(i,1,n) printf("%d",ok[i]);
//	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
*/
