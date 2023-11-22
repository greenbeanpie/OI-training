#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}

void desync() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}

int n, m;
char str[3030][3030];
string smin[3030];
string smax[3030];

bool cmp(char a, char b) {return a>b;}

int main() {
	file();
	desync();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> str[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		smin[i]="";smax[i]="";
		sort(str[i]+1,str[i]+1+m);
		for (int j = 1; j <= m; j++) smin[i]+=str[i][j];
		sort(str[i]+1,str[i]+1+m,cmp);
		for (int j = 1; j <= m; j++) smax[i]+=str[i][j];
	}
	for (int i = 1; i <= n; i++) {
		bool flag = 1;
		for (int j = 1; j <= n; j++) {
			if (i==j) continue;
			if (smin[i]>smax[j]) flag = 0;
		}
		cout << flag;
	}
	return 0;
}
