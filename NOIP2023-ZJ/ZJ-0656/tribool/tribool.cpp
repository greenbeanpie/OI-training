/*#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,m;
int a[N*2];
int f[N*2];
int C,T;
inline int read(){
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x*10+ch-'0',ch = getchar();
	return x;
}
int find(int x){
	if(x!=f[x]) return find(f[x]);
	return f[x];
}
void combine(int x,int y){
	if(find(x) != find(y)){
		f[find(x)] = find(y);
	}
}
int ans;
int cnt[N*2];
int idx;
struct node{
	char v;
}mem[N*2];
int main()
{
	C = read();
	T = read();
	while(T--){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		n = read();
		m = read();
		for(int i = 1;i <= n*2;i++) f[i] = i;
		for(int i = 1;i <= m;i++){
			char ch = getchar();
			int x,y;
			if(ch == '-' || ch == '+'){
				x = read(),y = read();
				if(ch == '-'){
					combine(x,y+n);
					combine(y,x+n);
				}
				else combine(x,y);
			}
			else{
				x = read();
				mem[x].v = ch;
			}
		}
		for(int i = 1;i <= n;i++){
			if(mem[i].v == 'U'){
				combine(i,i+n);
				combine(i+n,i);
			}
		}
		for(int i = 1;i <= n;i++){
			if(find(i) == find(i+n)) ans++;
		}
		cnt[++idx] = ans;
		ans = 0;
	}
	for(int i = 1;i <= idx;i++) cout << cnt[i] << endl;
	return 0;
}*/
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int h[N],e[N],ne[N],idx;
void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int n,m;
struct node{
	char v;
}mem[N];
int ans[N];
int cnt;
int f[N*2];
int C,T;
inline int read(){
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x*10+ch-'0',ch = getchar();
	return x;
}
int find(int x){
	if(x!=f[x]) return find(f[x]);
	return f[x];
}
void combine(int x,int y){
	if(find(x) != find(y)){
		f[find(x)] = find(y);
	}
}
bool flag;
int vis[N*2];
struct node1{
	int from;
	char v;
}action[N*2];
void dfs(int x,int t){
	if(x == t){
		flag = 1;
		return;
	}
	if(vis[x]){
		return;
	}
	vis[x] = 1;
	for(int i = h[x];~i;i = ne[i]){
		int j = e[i];
		dfs(j,t);
	}
	return;
}
int tem;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	C = read();
	T = read();
	while(T--){
		memset(h,-1,sizeof(h));
		n = read();
		m = read();
//		for(int i = 1;i <= n*2;i++) f[i] = i;
		for(int i = 1;i <= m;i++){
			char id = getchar();
			int x,y;
			if(id == '-'||id == '+'){
				x = read();
				y = read();
				action[x].from = y;
				action[x].v = id;
			}
			else{
				x = read();
				mem[x].v = id;
			}
		}
		for(int i = 1;i <= n;i++){
			if(action[i].from){
			    if(action[i].v == '-'){
			    	add(action[i].from+n,i);
			    	add(action[i].from,i+n);
				}
				else add(action[i].from,i);
			}
			if(mem[i].v == 'U'){
				add(i+n,i);
				add(i,i+n);
			}
		}
		for(int i = 1;i <= n;i++){
			memset(vis,0,sizeof(vis));
			flag = false;
			dfs(i,i+n);//yu chu li;
			dfs(i+n,i);
			if(flag) cnt++;
		}
		ans[++tem] = cnt;
		cnt = 0;
	}
	for(int i = 1;i <= tem;i++) cout << ans[i] << endl;
	return 0;
}
