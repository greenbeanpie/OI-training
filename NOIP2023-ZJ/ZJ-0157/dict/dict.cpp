#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0, f=0; char c=getchar();
	while (!isdigit(c)) f|=c=='-', c=getchar();
	while (isdigit(c)) x=(x<<3)+(x<<1)+(c^48), c=getchar();
	return f ? -x : x;
}

const int N=6e3+10;
int n, m;
char st[N];
struct qwqwq{
	string s;
	bool flag;
	int id;
} a[N];
string s[N], t[N];
bool ans[N];

bool cmp(qwqwq a, qwqwq b) {
	return a.s<b.s;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n=read(), m=read();
	for (int i=1; i<=n; i++) {
		scanf("%s", st+1);
		sort(st+1, st+m+1); for (int j=1; j<=m; j++) a[i].s+=st[j]; a[i].id=i; a[i].flag=0; a[i].s+='0';
		reverse(st+1, st+m+1); for (int j=1; j<=m; j++) a[i+n].s+=st[j]; a[i+n].id=i; a[i+n].flag=1; a[i+n].s+='1';
	}
	sort(a+1, a+n+n+1, cmp);
	for (int i=1; i<=n+n; i++) {
		if (a[i].flag) break;
		ans[a[i].id]=1;
	}
	for (int i=1; i<=n; i++) printf("%d", ans[i]);
	return 0;
}