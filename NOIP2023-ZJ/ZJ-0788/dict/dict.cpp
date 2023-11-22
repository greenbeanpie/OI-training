#include<bits/stdc++.h>
#define _ 5005
using namespace std;

int n,m;
char dic[_][_];
string tpsup[_],tpsdown[_];

bool cmp1(char a,char b) {
	return a < b;
}
bool cmp2(char a,char b) {
	return a > b;
}
int main() {
	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> dic[i][j];
		}
		sort(dic[i] + 1, dic[i] + 1 + m,cmp1);
		for(int j = 1; j <= m; j ++) {
			tpsup[i] += dic[i][j];
		}
		sort(dic[i] + 1, dic[i] + 1 + m,cmp2);
		for(int j = 1; j <= m; j ++) {
			tpsdown[i] += dic[i][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		int f = 1;
		for(int j = 1; j <= n; j ++) {
			if(i == j) continue;
			if(tpsup[i] >= tpsdown[j]) {
				f = 0;
				break;
			}
		}
		printf("%d",f);
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
