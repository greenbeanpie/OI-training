#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = (l); i <= (r); ++i)
#define per(i,r,l) for(int i = (r); i <= (l); --i)
#define N 100005
using namespace std;

int read(){
	int x = 0, w = 1; char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x<<1) + (x<<3) + (ch^48), ch = getchar();
	return x*w;
}

int c,T,n,m,ans;
int f[N<<1],val[N<<1],a[N],b[N];

int find(int x){
	if(x == f[x] || abs(x-f[x]) == n) return max(x,f[x]);
	return f[x] = find(f[x]);
}
struct node{
	char ch;
	int x,y;
}q[N];

int work(int x){
	if(x == 1 || x == 2) return 3-x;
	return x;
}
int work1(char ch){
	if(ch == 'T') return 1;
	else if(ch == 'F') return 2;
	return 3;
}
bool check(){
	rep(i,1,n) b[i] = a[i];
	rep(i,1,m){
		if(q[i].ch == '+') b[q[i].x] = b[q[i].y];
		else if(q[i].ch == '-') b[q[i].x] = work(b[q[i].y]);
		else b[q[i].x] = work1(q[i].ch);
	}
	rep(i,1,n) if(a[i] != b[i]) return 0;
	return 1;
}
void dfs(int x){
	if(x == n+1){
		if(!check()) return ;
		int sum = 0;
		rep(i,1,n) if(a[i] == 3) sum++;
		if(sum < ans){
			ans = sum;
			//rep(i,1,n) printf("%d ",a[i]);puts("");
		}
		return ;
	}
	a[x] = 1; dfs(x+1);
	a[x] = 2; dfs(x+1);
	a[x] = 3; dfs(x+1);
}

signed main(){
	
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	c = read(); T = read();
	if(c == 1|| c ==2){
		while(T--){
			n = read(); m = read(); ans = n+1;
			rep(i,1,n) a[i] = 0;
			rep(i,1,m) {
				cin>>q[i].ch;
				if(q[i].ch == '+' || q[i].ch == '-') q[i].x = read(),q[i].y = read();
				else q[i].x= read();
			}
			dfs(1);
			printf("%d\n",ans);
		}
		return 0;
	}
		while(T--){
		n = read(); m = read();
		rep(i,1,n*2) f[i] = i,val[i] = 0;
		rep(i,1,m){
			char ch; cin>>ch;
			if(ch == '+'){
				int x = read(), y = read();
				if(val[y]) {
					val[x] = val[y], val[x+n] = val[y+n];
					f[x] = x,f[x+n] = x+n;
				}
				else {
					if(find(y) == x) f[x] = x, f[x+n] = x+n;
					else if(find(y) == x+n) f[x] = x+n, f[x+n] = x;
					else f[x] = find(y), f[x+n] = find(y+n);
				}        
			}                            
			else if(ch == '-'){
				int x = read(), y = read();
				if(val[y]) {
					val[x] = work(val[y]), val[x+n] = work(val[y+n]);
					f[x] = x,f[x+n] = x+n;
				}

				else {
					val[x] = 0; val[x+n] = 0;
					if(find(y) == x) f[x] = x+n,f[x+n] = x;
					else if(find(y) == x+n) f[x] = x, f[x+n] = x+n;
					else f[x] = find(y+n), f[x+n] = find(y); 
				}
			}
			else{
				int x = read(); 
				f[x] = x; f[x+n] = x+n; 
				val[x] = work1(ch); val[x+n] = work(val[x]);
			}
		}
		int ans = 0;
		if(c == 3 || c == 4){
			rep(i,1,n) if(val[i] == 3) ans ++;
		}
		else{
			rep(i,1,n){
				if(i+n == find(i) || val[i] == 3) ans ++, val[i] = 3,val[i+n] = 3;
			}      
			rep(i,1,n){
				if(!val[i] && val[f[i]] == 3) ans ++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 1
10 5
U 1
U 2
U 3
T 1
F 2
如果有人看到了这段话，那么祝你们OI生涯一帆风顺。
我这下真退役了。 
*/
