#include <bits/stdc++.h>

namespace Solve {

const int maxn=3000, maxs=26;
int n, m;
char s[maxn+5];

struct node {
	int cnt[maxs+5];
	
	node() {
		for(int i=0; i<maxs; ++i) {
			cnt[i]=0;
		}
	}
	
	bool Bigless(const node &x) const {
		for(int i=maxs-1; i>=0; --i) {
			if(cnt[i]!=x.cnt[i]) {
				return cnt[i]<x.cnt[i];
			}
		}
		return true;
	}
	
	bool SmalllessBig(const node &x) const {
		int pos1=0, pos2=maxs-1;
		while(!cnt[pos1]) {
			++pos1;
		}
		while(!x.cnt[pos2]) {
			--pos2;
		}
		if(pos1!=pos2) {
			return pos1<pos2;
		}
		return false;
	}
	
	bool operator == (const node &x) const {
		for(int i=0; i<maxs; ++i) {
			if(cnt[i]!=x.cnt[i]) {
				return false;
			}
		}
		return true;
	}
}t[maxn+5], mini1, mini2;

void solve() {
	mini1.cnt[maxs-1]=2100000000;
	mini2.cnt[maxs-1]=2100000000;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i) {
		scanf("%s", s);
		for(int j=0; j<m; ++j) {
			++t[i].cnt[s[j]-'a'];
		}
		if(t[i].Bigless(mini1)) {
			mini2=mini1;
			mini1=t[i];
		} else if(t[i].Bigless(mini2)) {
			mini2=t[i];
		}
	}
	for(int i=0; i<n; ++i) {
		if(t[i]==mini1) {
			if(t[i].SmalllessBig(mini2)) {
				putchar('1');
			} else {
				putchar('0');
			}
		} else {
			if(t[i].SmalllessBig(mini1)) {
				putchar('1');
			} else {
				putchar('0');
			}
		}
	}
	putchar('\n');
	return ;
}

}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	Solve::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}