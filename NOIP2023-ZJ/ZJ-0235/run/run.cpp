#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = (l); i <= (r); ++i)
#define per(i,r,l) for(int i = (r); i >= (l); --i)
#define int long long
#define N 100005
using namespace std;

int read(){
	int x = 0, w = 1; char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x<<1) + (x<<3) + (ch^48), ch = getchar();
	return x*w;
}

int c,T,n,m,k,d;
int maxn[N];
struct node{int l,r,w;} q[N];
bool cmp(node x,node y){
	return x.l< y.l;
}

signed main(){
	
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	c = read(); T = read();
	while(T--){
		n = read(); m = read(); k = read(); d = read();
		rep(i,1,m){
			int x = read(),y =read(),z = read();
			q[i].r = x;q[i].l = x-y+1; q[i].w = z;
		}
		sort(q+1,q+1+m,cmp);
	    memset(maxn,0,sizeof(maxn));
		rep(i,1,n) {
			maxn[i] = maxn[i-1];
			int t = m,val = 0;;
			per(j,i,max(1ll,i-k+1)){
				while(t > 0){
					if(q[t].r > i) {
						t--;continue;
					}
					if(q[t].l >= j ) val += q[t].w;
					else break;
					t--;
				}
				if(j>2) maxn[i] = max(maxn[i],maxn[j-2] + val - d*(i-j+1));
				else maxn[i] = max(maxn[i], val - d*(i-j+1));
			}
		}
		printf("%lld\n",maxn[n]);
	}
	return 0;
}
// HAPPY END OF MY THREE YEAR's OI CAREER
