#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
const int M = 2e6 + 5;

int n, m;
int son[M][30], son_min[M], idx;
int cnt[M], tag[N];

bool cmp(int x, int y){
	return x > y;
}

struct Node{
	int sor[N];
}str[N];

void insert(int id){
	int p = 0;
	for (int i = 0;i < m; ++ i){
		int now = str[id].sor[i];
		if (!son[p][now]) son[p][now] = ++idx;
		son_min[p] = min(son_min[p], now);
		p = son[p][now];
	}cnt[p] = id;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d", &n, &m);
	memset(son_min, 0x3f, sizeof son_min);
	for (int i = 1;i <= n; ++ i){
		char cinp[m];
		scanf("%s", cinp);
		for (int j = 0;j < m; ++ j)
			str[i].sor[j] = cinp[j] - 'a' + 1;
		sort(str[i].sor, str[i].sor + m, cmp);
		insert(i);
	}
	
	for (int i = 1;i <= n; ++ i)
		reverse(str[i].sor, str[i].sor + m);
	
	for (int i = 1;i <= n; ++ i){
		int p = 0;bool flag = true;
		for (int j = 0;j < m; ++ j){
			int now = str[i].sor[j];
			if (now < son_min[p]) break;
			if (now > son_min[p]) {
				flag = false;
				break;
			}p = son[p][now];
			if (j == m - 1 && cnt[p] != i)
				flag = false;
		}
		if (flag) printf("%d", 1);
		else printf("%d", 0);
	}
	return 0;
}