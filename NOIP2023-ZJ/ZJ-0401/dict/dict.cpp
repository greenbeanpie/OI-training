#include<bits/stdc++.h>
#define maxn 3005
#define inf 0x3ffff
using namespace std;
char ch[maxn][maxn], ch2[maxn][maxn];
struct node{
	int child[27], mincnt=inf, mxcnt=-1;
	int cnt, fa;
} T[maxn*maxn];
int n, m, tail;
void preT(int x) {
	int now = 1;
	for(int i = 1; i <= m; i++) {
		int nowch = ch2[x][i]-'a';
		if(!T[now].child[nowch]) {
			T[now].child[nowch] = ++tail;
			T[now].mxcnt = max(T[now].mxcnt, nowch);
			T[now].mincnt = min(T[now].mincnt, nowch);
//			cout << tail << ' ' << ch2[x][i] << endl;
			T[tail].fa = now;
			now = tail;
		} else now = T[now].child[nowch];
	}
	T[now].cnt++;
}
bool search(int x) {
	int now = 1;
	for(int i = 1; i <= m; i++) {
		int nowch = ch[x][i]-'a';
		if(T[now].mincnt>nowch) return true;
		if(!T[now].child[nowch]) return false;
		if(nowch!=T[now].mincnt) return false;
		now = T[now].child[nowch];
	}
	if(T[now].cnt>1) return false;
	else return true;
}
bool cmp(char a, char b) {return a>b;}
int chk(int x, int y) {
	for(int i = 1; i <= m; i++) {
		if(ch[x][i]<ch[y][i]) return x;
		if(ch[x][i]>ch[y][i]) return y;
	}
	return y;
}
void buc_sort(int x) {
	int buc[26]={0};
	for(int i = 1; i <= m; i++) buc[ch[x][i]-'a']++;
	int now=0;
	for(int i = 0; i < 26; i++) {
		for(int j = 1; j <= buc[i]; j++) ch[x][++now] = char(i+'a');
	}
	now=0;
	for(int i = 25; i>=0; i--) {
		for(int j = 1; j <= buc[i]; j++) ch2[x][++now] = char(i+'a');
	}
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==1) {
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin>>ch[i][j];
		}
		buc_sort(i);
//		sort(ch[i]+1, ch[i]+m+1);
//		sort(ch2[i]+1, ch2[i]+m+1, cmp);
	}
//	cout << endl;
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) cout << ch[i][j];
//		cout << endl;
//	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) cout << ch2[i][j];
//		cout << endl;
//	}
	tail=1;
	for(int i = 1; i <= n; i++) preT(i);
	int minstr=0;
	for(int i = 1; i <= n; i++) {
		if(minstr&&chk(minstr, i)==i) {
			cout << 1;
			minstr=i;
		} else if(search(i)) {
			cout << 1;
			if(!minstr) minstr=i;
//			else minstr=chk(minstr, i);
		} else cout << 0;
	}
		
	cout << endl;
	return 0;
}
