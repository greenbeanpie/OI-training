#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 10;
struct S{
	char a;
	int b, c;
} arr[MAXN];
int n, m;
int flag[MAXN], flag1[MAXN];
int vis[MAXN];
char cc[MAXN];
int esc = 0;
void dfs1(int cnt){
	if(esc == 1){
		return;
	}
	if(cnt == n + 1){
		int sum = 0;
		for(int i = 1; i <= n; i++){
			flag1[i] = flag[i];
			if(flag[i] == 0){
				sum++;
			}
		}
		for(int i = 0; i < m; i++){
			if(arr[i].a == 'T'){
				flag1[arr[i].b] = 1;
			}
			if(arr[i].a == 'F'){
				flag1[arr[i].b] = -1;
			}
			if(arr[i].a == 'U'){
				flag1[arr[i].b] = 0;
			}
			if(arr[i].a == '+'){
				flag1[arr[i].b] = flag1[arr[i].c];
			}
			if(arr[i].a == '-'){
				flag1[arr[i].b] = -flag1[arr[i].c];
			}
		}
		int k = 1;
		for(int i = 1; i <= n; i++){
			if(flag1[i] != flag[i]){
				k = 0;
				break;
			}
		}
		if(k){
			printf("%d\n", sum);
			esc = 1;
		}
		return;
	}
	flag[cnt] = 1;
	dfs1(cnt + 1);
	if(esc == 1){
		return;
	}
	flag[cnt] = -1;
	dfs1(cnt + 1);
	if(esc == 1){
		return;
	}
	flag[cnt] = 0;
	dfs1(cnt + 1);
	if(esc == 1){
		return;
	}
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int T, c;
	scanf("%d %d", &c, &T);
	while(T--){
		esc = 0;
		memset(flag, 0, sizeof(flag));
		memset(flag1, 0, sizeof(flag1));
		memset(vis, 0, sizeof(vis));
		memset(cc, 'T', sizeof(cc));
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++){
			char x;
			int y, z;
			cin >> x;
			if(x == 'T' || x == 'F' || x == 'U'){
				arr[i].a = x;
				scanf("%d", &arr[i].b);
			}
			else{
				arr[i].a = x;
				scanf("%d %d", &arr[i].b, &arr[i].c);
			}
		}
		if(c >= 3 && c <= 4){
			for(int i = m - 1; i >= 0; i--){
				if(vis[arr[i].b] == 0){
					vis[arr[i].b] = 1;
					cc[arr[i].b] = arr[i].a;
				}
			}
			int sum = 0;
			for(int i = 1; i <= n; i++){
				if(cc[i] == 'U'){
					sum++;
				}
			}
			printf("%d", sum);
		}
		else{
			dfs1(1);
		}
		
	}
	return 0;
}