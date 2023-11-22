#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+10;
int o=0, t=0, n=0, m=0, x=0, y=0, ansu=0, f[N];
char op, s[N];
inline int fid(int x){ return (x == f[x] ? x : f[x]=fid(f[x]));}
inline void cpt(){
	for(int i=1; i<=n; i++) f[i]=fid(i);
	for(int i=1; i<=n; i++) if(s[f[i]] == 'U') s[i]='U';
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> o >> t;
	if(o == 3 || o == 4){
		for(; t; t--){
			cin >> n >> m; ansu=0;
			for(int i=1; i<=n; i++) s[i]='U';
			for(int i=1; i<=m; i++){ cin >> op >> x; s[x]=op;}
			for(int i=1; i<=n; i++){ if(s[i] == 'U') ansu ++;}
			cout << ansu << endl;
		}
	}
	if(o == 5 || o == 6){
		for(; t; t--){
			cin >> n >> m; ansu=0;
			for(int i=1; i<=n; i++) s[i]='T', f[i]=i;
			for(int i=1; i<=m; i++){
				cin >> op;
				if(op == 'U'){ cin >> x; s[x]='U';}
				else{
					cin >> x >> y;
					if(x == y) continue;
					f[x]=fid(y); cpt();
				}
			} cpt();
			for(int i=1; i<=n; i++){ if(s[i] == 'U') ansu++;} 
			cout << ansu << endl;
		}
	}else{
		for(; t; t--){
			cout << 0 << endl;
		}
	}
	return 0;
}
