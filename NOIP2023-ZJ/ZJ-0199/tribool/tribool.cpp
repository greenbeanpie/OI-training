#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
char x[15],y[15];
int ans = 0x3f3f3f3f;
struct op{
	char v;
	int i,j;
} ops[100005];
void dfs(int u,int unknown){
	if(u>n){
		//jianyan
		memcpy(y,x,sizeof(x));
		for(int i = 1;i <= m;i++){
			if(ops[i].v=='T'||ops[i].v=='F'||ops[i].v=='U'){
				y[ops[i].i] = ops[i].v;
			}else if(ops[i].v=='+'){
				y[ops[i].i] = y[ops[i].j];
			}else if(ops[i].v=='-'){
				if(y[ops[i].j]=='T') y[ops[i].i] = 'F';
				else if(y[ops[i].j]=='F') y[ops[i].i] = 'T';
				else if(y[ops[i].j]=='U') y[ops[i].i] = 'U';
			}
		}
		bool flag = true;
		for(int i = 1;i <= n;i++){
			if(y[i]!=x[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			ans = min(ans,unknown);
			/*for(int i = 1;i <= n;i++){
				cout << x[i] << ' ';
			}
			cout << endl;*/
		}
		return;
	}
	x[u] = 'T';
	dfs(u+1,unknown);
	x[u] = 'F';
	dfs(u+1,unknown);
	x[u] = 'U';
	dfs(u+1,unknown+1);
}
bool uk[100005];
int main(){
	#ifndef LOCAL
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin >> c >> t;
	if(c<=2){
		//meiju
		while(t--){
			ans = 0x3f3f3f3f;
			cin >> n >> m;
			for(int i = 1;i <= m;i++){
				char v;
				cin >> v;
				ops[i].v = v;
				if(v=='T'||v=='F'||v=='U'){
					int j;
					cin >> j;
					ops[i].i = j;
				}else if(v=='+'||v=='-'){
					int j,k;
					cin >> j >> k;
					ops[i].i=j,ops[i].j=k;
				}
			}
			dfs(1,0);
			cout << ans << endl;
		}
		return 0;
	}
	if(3<=c&&c<=4){
		while(t--){
			memset(uk,0,sizeof(uk));
			cin >> n >> m;
			for(int i = 1;i <= m;i++){
				char v;
				cin >> v;
				if(v=='U'){
					int j;
					cin >> j;
					uk[j] = 1;
				}else if(v=='T'||v=='F'){
					int j;
					cin >> j;
					uk[j] = 0;
				}
			}
			int ans = 0;
			for(int i = 1;i <= n;i++) if(uk[i]) ans++;
			cout << ans << endl;
		}
		return 0;
	}
	
}