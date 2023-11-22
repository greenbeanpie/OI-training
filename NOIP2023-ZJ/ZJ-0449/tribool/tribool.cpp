#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int Cas, T;
int n, m;
const int maxn = (int)1e5 + 114;
struct valref{
	int bindwith;
	char sign;
};
valref reftab[maxn];
char reverse(char cc) {
	if (cc=='U') return 'U';
	if (cc=='T') return 'F';
	if (cc=='F') return 'T';
	if (cc=='+') return '-';
	if (cc=='-') return '+';
	return '?';
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin>>Cas>>T;
	char opt; int u, v;
	if (Cas == 3 || Cas == 4) {
		while (T--){
			cin>>n>>m;
			for (int i=1;i<=n;i++) reftab[i].sign='/';
			
			for (int i=0;i<m;i++){
				cin>>opt>>u;
				reftab[u].sign = opt;
			}
			int answer = 0;
			for (int i=1;i<=n;i++) answer += (reftab[i].sign=='U'?1:0);
			cout<<answer<<endl;
		}
	} else {
		while (T--){
			cin>>n>>m;
			for (int i=0;i<=n;i++){
				reftab[i].bindwith=i;
				reftab[i].sign = '+';
			}
			for (int i=0;i<m;i++){
				cin>>opt;
				switch (opt) {
					case 'T':
					case 'F':
					case 'U':{
						cin>>u;
						reftab[u].bindwith=0;
						reftab[u].sign = opt;
						break;
					}
					case '+':
					case '-':{
						cin>>u>>v;
						while (reftab[v].bindwith!=v and reftab[v].bindwith!=0) {
							if (opt == reftab[v].sign) opt='+';
							else opt='-';
							v=reftab[v].bindwith;
						}
						if (reftab[v].bindwith != 0){
							reftab[u].bindwith=v;
							reftab[u].sign=opt;
						} else {
							reftab[u].bindwith=0;
							if (reftab[u].sign == '-') reftab[u].sign=reverse(reftab[v].sign);
							else reftab[u].sign=reftab[v].sign;
						}
						break;
					}
				}
			}
			int answer = 0;
			for (int i=1;i<=n;i++) {
				if (reftab[i].bindwith==i && reftab[i].sign=='-') {
					reftab[i].bindwith=0; reftab[i].sign='U';
				}
			}
			for (int ti=1;ti<=n;ti++){
				for (int i=1;i<=n;i++){
					if (reftab[i].bindwith==i) continue;
					if (reftab[i].bindwith==0) continue;
					if (reftab[reftab[i].bindwith].bindwith != 0)
						reftab[i].sign = (reftab[i].sign==reftab[reftab[i].bindwith].sign?'+':'-');
					else reftab[i].sign =
						(reftab[i].sign=='+'?reftab[reftab[i].bindwith].sign:reverse(reftab[reftab[i].bindwith].sign));
					reftab[i].bindwith = reftab[reftab[i].bindwith].bindwith;
				}
			}
			for (int i=1;i<=n;i++) answer+=(reftab[i].sign=='U'?1:0);
			cout<<answer<<endl;
		}
	}
	return 0;
}