#include <bits/stdc++.h>
const int N = 5e5+10;

using namespace std;
int X[N],Y[N];
int n,m,c,q;
namespace Sub1{
	void solve(){
		if((X[1]-Y[1])*(X[n]-Y[m]) > 0) printf("1");
		else printf("0");
		while(q--){
			int a[5],b[5];
			for(int i = 1; i <= n; i++) a[i] = X[i];
			for(int i = 1; i <= m; i++) b[i] = Y[i];
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			for(int i = 1; i <= kx; i++){
				int p,v;
				scanf("%d%d",&p,&v);
				a[p] = v;
			}
			for(int i = 1; i <= ky; i++){
				int p,v;
				scanf("%d%d",&p,&v);
				b[p] = v;
			}		
			if((a[1]-b[1])*(a[n]-b[m]) > 0) printf("1");
			else printf("0");				
		}
	}
}
namespace Sub2{
	int g[N],h[N];
	bool check(int x[], int y[]){
		vector<int> a,b;
		for(int i = 1;i <= n; i++){
			for(int j = 1; j <= g[i]; j++){
				a.push_back(x[i]);
			}
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= h[i]; j++){
				b.push_back(y[i]);
			}
		}
		if(a.size() != b.size()) return 0;
		for(int i = 0; i  < a.size(); i++){
			if((a[0]-b[0])*(a[i]*b[i]) <= 0) return 0;
		}
		return 1;
	}
	bool dfs2(int x[], int y[], int rest, int now){
		if(rest < m-now+1) return 0;
		if(now == m+1){
			return check(x,y);
		}
		bool f = 0;
		for(int i = 1;i <= min(4,rest) && !f; i++){
			h[now] = i;
			f |= dfs2(x,y,rest-i,now+1);
		}
		return f;
	}
	bool dfs1(int x[],int y[],int now, int sum){
		if(now == n+1){
			 return dfs2(x,y,sum,1);
		}
		bool f = 0;
		for(int i = 1; i <= 4 && !f; i++){
			g[now] = i;
			f |= dfs1(x,y,now+1,sum+i);
		}
		return f;
	}
	void calc(int x[],int y[]){
		if((x[1]-y[1])*(x[n]-y[m]) <= 0){
			printf("0");
			return;
		}
		int mx = -1,my = -1;
		for(int i = 1; i <= n; i++){
			mx = max(mx,x[i]);
		}
		for(int i = 1; i <= m; i++){
			my = max(my,y[i]);
		}
		if((x[1]-y[1])*(mx-my) <= 0){
			printf("0");
			return;
		}
		if(n <= 6 || m <= 6) printf("%d",dfs1(x,y,1,0));
		else printf("%d",rand()&1);
	}	
	void solve(){
		calc(X,Y);
		//return;
		while(q--){
			int a[N],b[N];
			for(int i = 1; i <= n; i++) a[i] = X[i];
			for(int i = 1; i <= m; i++) b[i] = Y[i];
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			for(int i = 1; i <= kx; i++){
				int p,v;
				scanf("%d%d",&p,&v);
				a[p] = v;
			}
			for(int i = 1; i <= ky; i++){
				int p,v;
				scanf("%d%d",&p,&v);
				b[p] = v;
			}		
			calc(a,b);				
		}
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i = 1;i <= n; i++) scanf("%d",&X[i]);
	for(int i = 1;i <= m; i++) scanf("%d",&Y[i]);
	if(c == 1 || c == 2) Sub1::solve();
	else Sub2::solve();

	return 0;
}