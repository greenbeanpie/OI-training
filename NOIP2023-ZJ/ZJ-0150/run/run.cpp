#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0; bool f=1; char c=getchar();
	while(c<48||c>57) f^=(c==45), c=getchar();
	while(c>=48&&c<=57) x=x*10+(c^48), c=getchar();
	return (f?x:-x);
}
int n, m, k;
long long d;
struct chl{
	int l, r; long long v;
	chl(){}
	chl(int _l, int _r, int _v) : l(_l), r(_r), v(_v) {}
	bool operator<(const chl &y) const{
		if(l!=y.l) return l<y.l;
		if(r!=y.r) return r<y.r;
		return v<y.v;
	}
}w[100105];
namespace bf{
	long long check(int st){
		for(int i=0, f=(1<<(k+1))-1; i<n-k; i++)
			if((st|(f<<i))==st)
				return 0;
		long long res=0;
		for(int i=1; i<=m; i++){
			int f=(1<<(w[i].r-w[i].l+1))-1;
			if((st|(f<<(w[i].l-1)))==st)
				res+=w[i].v;
		}
		while(st) res-=d, st&=st-1;
		return res;
	}
	long long solve(){
		long long ans=0;
		for(int st=0; st<(1<<n); st++)
			ans=max(ans, check(st));
		return ans;
	}
}
namespace pos_sum{
	long long solve(){
		long long ans=0;
		for(int i=1; i<=m; i++)
			if(w[i].r-w[i].l+1<=k)
				ans+=max(w[i].v-d*(w[i].r-w[i].l+1), 0ll);
		return ans;
	}
}
int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	for(int id=read(), _=read(); _; --_){
		n=read(), m=read(), k=read(), d=read();
		for(int i=1; i<=m; i++){
			int x=read(), y=read(), v=read();
			w[i]=chl(x-y+1, x, v);
		}
		switch(id){
			case 1: case 2:
				printf("%lld\n", bf::solve()); break;
			default:
				printf("%lld\n", pos_sum::solve());
		}
	}
	return 0;
}