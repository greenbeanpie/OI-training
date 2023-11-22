#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
int n, m, cnt[MAXN][30], ml[MAXN], mr[MAXN];
char ts[MAXN];
bool flg;
int cmp(int a, int b){
	for(int i = 25; i >= 0; --i)
		if(cnt[a][i] != cnt[b][i]){
			if(cnt[a][i] > cnt[b][i])
				return b;
			else
				return a;
		}
	return a;
}
char r1[MAXN], r2[MAXN];
bool cmp2(int mn, int mx){
	int ptr = 0;
	for(int i = 0; i < 26; ++i)
		for(int j = 0; j < cnt[mn][i]; ++j)
			r1[ptr++] = i;
	ptr = 0;
	for(int i = 25; i >= 0; --i)
		for(int j = 0; j < cnt[mx][i]; ++j)
			r2[ptr++] = i;
	for(int i = 0; i < m; ++i)
		if(r1[i] != r2[i]){
			if(r1[i] < r2[i])
				return true;
			else
				return false;
		}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> ts;
		for(int j = 0; j < m; ++j)
			ts[j] -= 'a';
		for(int j = 0; j < m; ++j)
			++cnt[i][ts[j]];
	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	ml[0] = 0;
	for(int i = 1; i < n; ++i){
		ml[i] = cmp(ml[i - 1], i);
	}
	mr[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; --i){
		mr[i] = cmp(mr[i + 1], i);
	}
	for(int i = 0; i < n; ++i){	
		flg = true;
		if(i > 0 && !cmp2(i, ml[i - 1]))
			flg = false;
		if(flg){
			if(i < n - 1 && !cmp2(i, mr[i + 1]))
				flg = false;
		}
		if(flg)
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
	return 0;
}