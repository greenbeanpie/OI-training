#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,N3,P,N0,N1,N2;
struct node{
	int a,b,c;
	bool operator<(const node &rhs) const {
		if(a!=rhs.a) return a<rhs.a;
		if(b!=rhs.b) return b<rhs.b;
		return c<rhs.c; 
	}
};
int tot;
vector<node> ans;
void pri(int a,int b,int c){
	++tot;
	if(tot<=1e5) ans.emplace_back(node{a,b,c});
} 
signed main(){
	freopen("enumeration.in","r",stdin);
	freopen("enumeration.out","w",stdout);
	scanf("%lld%lld%lld",&N,&N3,&P);
	N0=N*N+1;
	for(int a=1;a<=P;++a){
		N1=N0%a;
		for(int b=max(0ll,N3-N1);b<=P;++b){
			N2=N1+b;
			int tmp=N2-N3;
			if(tmp==0){
				for(int c=N3+1;c<=P;++c) pri(a,b,c);
			}else{
				int k=1;
				for(k=1;k*k<=tmp;++k){
					if(tmp%k) continue;
					int c=k;
					if(c<=P&&c>N3) pri(a,b,c);
				}
				--k;
				if(k*k==tmp) --k;
				for(;k;--k){
					if(tmp%k) continue;
					int c=tmp/k;
					if(c<=P&&c>N3) pri(a,b,c);
				}
				
			}
		}
	}
	
	printf("%lld\n",tot);
	sort(ans.begin(),ans.end());
	for(auto iter:ans) printf("%lld %lld %lld\n",iter.a,iter.b,iter.c);
}
