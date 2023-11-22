#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+10;
int n=0, m=0, tp[N][30];
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m; 
	for(int i=1; i<=n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++) tp[i][(s[j]-'a')] ++;
	}
	if(n == 1) return cout << 1 << endl, 0; 
	for(int i=1; i<=n; i++){
		int fg=0, x=0, c=0;
		for(int k=0; k<26; k++) if(tp[i][k]){ x=k, c=tp[i][k]; break; }
		for(int j=1; j<=n; j++){
			if(j == i) continue;
			fg=0;
			for(int k=25; k>x; k--) if(tp[j][k]){ fg=1; break;}
			if(! fg) break;
		} cout << fg;
	}
	return cout << endl, 0;
}
