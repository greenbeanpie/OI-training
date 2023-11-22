#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#define N 100005
using namespace std;

int c, t, n, m, fa[N], size[N], edge[N], ans[N], tot, tmp1[N], tmp2[N], minn;//T:1 F:2 U:3
struct oper{
	char type;
	int x, y;
}a[N];

int find1(int x){
	if(x == fa[x]) return x;
	fa[x] = find1(fa[x]);
	return fa[x];
}

pair<int, int> find(int x){
	if(fa[x] == x) return make_pair(x, 1);
	pair<int, int> tmp = find(fa[x]);
	if(edge[x] == 1){
		fa[x] = tmp.first;
		edge[fa[x]] = tmp.second;
		return tmp;
	} else {
		fa[x] = tmp.first;
		edge[fa[x]] = -tmp.second;
		return make_pair(tmp.first, -tmp.second);
	}
}

int check(){
	for(int i = 1; i <= n; i++){
		tmp2[i] = tmp1[i];
	}
	for(int i = 1; i <= m; i++){
		if(a[i].type == '+'){
			tmp2[a[i].x] = tmp2[a[i].y];
		} else if(a[i].type == '-'){
			if(tmp2[a[i].y] == 1){
				tmp2[a[i].x] = 2;
			} else if(tmp2[a[i].y] == 2){
				tmp2[a[i].x] = 1;
			} else {
				tmp2[a[i].x] = 3;
			}
		} else if(a[i].type == 'T'){
			tmp2[a[i].x] = 1;
		} else if(a[i].type == 'F'){
			tmp2[a[i].x] = 2;
		} else {
			tmp2[a[i].x] = 3;
		}
	}
	for(int i = 1; i <= n; i++){
		if(tmp1[i] != tmp2[i]){
			return 0;
		}
	}
	return 1;
}

void dfs(int now, int cc){
	if(cc >= minn) return;
	if(now == n + 1){
		if(check()){
			minn = cc;
		}
		return;
	}
	tmp1[now] = 1;
	dfs(now + 1, cc);
	tmp1[now] = 2;
	dfs(now + 1, cc);
	tmp1[now] = 3;
	dfs(now + 1, cc + 1);
	tmp1[now] = 0;
}

char type;
int x, y;

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		tot = 0;
		memset(ans, 0, sizeof(ans));
		memset(edge, 0, sizeof(edge));
		for(int i = 1; i <= n; i++){
			fa[i] = i;
		}

		scanf("%d%d", &n, &m);
		if(c == 1 || c == 2){
			minn = N;
			for(int i = 1; i <= m; i++){
				a[i].type = getchar();
				while(a[i].type != '+' && a[i].type != '-' && !isalpha(a[i].type)){
					a[i].type = getchar();
				}
				scanf("%d", &a[i].x);
				if(a[i].type == '+' || a[i].type == '-'){
					scanf("%d", &a[i].y);
				}
			}
			dfs(1, 0);
			printf("%d\n", minn);
		} else if(c == 3 || c == 4){
			for(int i = 1; i <= m; i++){
				a[i].type = getchar();
				while(!isalpha(a[i].type)){
					a[i].type = getchar();
				}
				scanf("%d", &a[i].x);
				ans[a[i].x] = a[i].type - 'A';
			}
			for(int i = 1; i <= n; i++){
				if(ans[i] == 'U' - 'A'){
					tot++;
				}
			}
			printf("%d\n", tot);
		} else if(c == 5 || c == 6){
			for(int i = 1; i <= m; i++){
				type = getchar();
				while(type != '+' && type != '-' && !isalpha(type)){
					type = getchar();
				}
				scanf("%d", &x);
				if(type == '+'){
					scanf("%d", &y);
					int xx = find1(x), yy = find1(y);
					if(ans[yy] == 0)
					if(xx != yy) fa[xx] = yy;
				} else {
					ans[find1(x)] = 1;
				}
			}
			for(int i = 1; i <= n; i++){
				tot += ans[find1(i)];
			}
			printf("%d\n", tot);
		} else {
			for(int i = 1; i <= m; i++){
				type = getchar();
				while(type != '+' && type != '-' && !isalpha(type)){
					type = getchar();
				}
				scanf("%d", &x);
				if(type == '+' || type == '-'){
					scanf("%d", &y);
				}

				if(type == 'T'){
					pair<int, int> tmp = find(x);
					if(tmp.second == 1){
						if(ans[tmp.first] == 2){
							ans[tmp.first] = 3;
						} else {
							ans[tmp.first] = 1;
						}
					} else {
						if(ans[tmp.first] == 1){
							ans[tmp.first] = 3;
						} else {
							ans[tmp.first] = 2;
						}
					}
				}

				if(type == 'F'){
					pair<int, int> tmp = find(x);
					if(tmp.second == 1){
						if(ans[tmp.first] == 1){
							ans[tmp.first] = 3;
						} else {
							ans[tmp.first] = 2;
						}
					} else {
						if(ans[tmp.first] == 2){
							ans[tmp.first] = 3;
						} else {
							ans[tmp.first] = 1;
						}
					}
				}
			}
		}
	}
	return 0;
}