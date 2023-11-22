#include<bits/stdc++.h>
using namespace std;
int n, m;
char ch[3005][3005];
struct point{
	int s[26];
	int i;
}p[3005];
bool cmp(point x, point y){
	for(int i = 25; i >= 0; i--){
		if(x.s[i] < y.s[i])return 1;
		if(y.s[i] < x.s[i])return 0;
	}
	return x.i < y.i;
}
int ans[3005];
int a[3005], lena;
int b[3005], lenb;
bool check(int x, int y){
	lena = lenb = 0;
	for(int i = 0; i < 26; i++){
		int sheng = p[x].s[i];
		while(sheng--){
			a[++lena] = i;
		}
	}
	for(int i = 25; i >= 0; i--){
		int sheng = p[y].s[i];
		while(sheng--){
			b[++lenb] = i;
		}
	}
	for(int i = 1; i <= m; i++){
		if(a[i] < b[i])return 1;
		if(a[i] > b[i])return 0;
	}
	return 0;
}
signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%s",ch[i]+1);
		for(int j = 1; j <= m; j++){
			p[i].s[ch[i][j] - 'a']++;
		}
		p[i].i = i;
	}
	if(n == 1){
		printf("1");
		return 0;
	}
	sort(p + 1, p + 1 + n, cmp);
	memset(ans, 0, sizeof(ans));
	for(int i = n; i > 1; i--){
		ans[p[i].i] = check(i, 1);
	}
	ans[p[1].i] = check(1, 2);
	for(int i = 1; i <= n; i++)printf("%d", ans[i]);
	return 0;
}

