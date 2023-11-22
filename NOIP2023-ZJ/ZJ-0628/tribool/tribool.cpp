#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;

struct node{
	int to;
	int val;
	node(int a,int b){
		to=a,val=b;
	}
	node(){
		to=val = 0;
	}
};

vector<node> e[N];

int dfn[N],low[N],tot;
bitset<N> instk;
stack<int> stk;
int val[N]; // -2: not visited -1: U: 
int dfn1[N];

void tarjan(int u,int val1 = 0){
	dfn[u] = low[u] = ++tot;
	dfn1[tot] = u;
	instk[u] = 1;
	stk.push(u);
	val[u] = val1;
	for(auto i:e[u]){
		if(!dfn[i.to]){
			tarjan(i.to,val1^i.val);
			low[u] = min(low[u],low[i.to]);
		}
		else if(instk[i.to]){
			low[u]=min(low[u],dfn[i.to]);
			if(val1^val[i.to]^i.val){
				val[i.to] = val[u] = -1;
			}
		}
	}
	if(dfn[u]==low[u]){
		while(stk.top()!=u){
			val[stk.top()] = val[u];
			instk[stk.top()]=0;
			stk.pop();
		}
		instk[stk.top()] = 0;
		stk.pop();
	}
}

queue<node> q;

deque<node> dq;

signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int id,t;
	cin >> id >> t;
	while(t--){
		
		int n,m;
		cin >> n >> m;
		fill(val,val+n+1,-2);
		fill(low,low+n+1,0);
		fill(dfn,dfn+n+1,0);
		for(int i=1;i<=n;i++){
			e[i].clear();
		}

		char op;
		int u,v;
		if(id==3||id==4){
			for(int i=1;i<=m;i++){
				cin >> op >> u;
				if(op=='U'){
					val[u]=-1;
				}
				else{
					val[u] = 0;
				}
			}
			int cnt = 0;
			for(int i=1;i<=n;i++){
				if(val[i]==-1){
					++cnt;
				}
			}
			cout << cnt << endl;
			continue;
		}
		if(id==5||id==6){
			for(int i=1;i<=m;i++){
				cin >> op;
				if(op=='+'){
					cin >> u >> v;
					// e[u].emplace_back(v,0);
					// e[v].emplace_back(u,0);
					// if(val[v] == -1){
					val[u] = val[v];
					// }
				}
				else{
					cin >> u;
					val[u] = -1;
				}
			}
			for(int i=1;i<=n;i++){
				if(val[u] == -1){
					q.push({i,0});
					while(q.size()){
						auto now = q.front();
						q.pop();
						for(auto j:e[now.to]){
							if(val[j.to]!=-1){
								val[j.to] = -1;
								q.push({j.to,0});
							}
						}
					}
				}
			}
			int cnt = 0;
			for(int i=1;i<=n;i++){
				if(val[i]==-1){
					++cnt;
				}
			}
			cout << cnt << endl;
			continue;
		}
		for(int i=1;i<=m;i++){
			tot = 0;
			cin >> op >> u;
			if(op=='U'){
				val[u] = -1;
			}
			else if(op=='T'){
				val[u] = 1;
			}
			else if(op=='F'){
				val[u] = 0;
			}
			else if(op=='+'){
				cin >> v;
				// if(val[v]!=-2){
				// 	// val[u].to = u;
				// 	if(val[v] == -1){
				// 		val[u] = -1;
				// 	}
				// 	else{
				// 		val[u] = val[v];
				// 	}
				// }
				// else{
					e[v].emplace_back(u,0);
				// }
			}
			else if(op=='-'){
				cin >> v;
				// if(val[v]!=-2){
				// 	// val[u].to = u;
				// 	if(val[v] == -1){
				// 		val[u] = -1;
				// 	}
				// 	else{
				// 		val[u] = val[v] ^ 1;
				// 	}
				// }
				// else{
					e[v].emplace_back(u,1);
				// }
			}
		}
		for(int i=1;i<=n;i++){
			if(val[i]!=-2){
				q.push({i,val[i]});
				while(q.size()){
					auto now = q.front();
					q.pop();
					for(auto j:e[now.to]){
						if(val[j.to] == -1){
							continue;
						}
						if(now.val == -1){
							val[j.to] = -1;
						}
						else{
							val[j.to] = now.val ^ j.val;
							// val[j.to].to = j.to;
						}
						q.push({j.to,val[j.to]});
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(val[i]==-2){
				tarjan(i);
			}
		}

		for(int i=1;i<=n;i++){
			if(val[i]==-1){
				q.push({i,0});
				while(q.size()){
					auto now = q.front();
					q.pop();
					for(auto j:e[now.to]){
						if(val[j.to]!=-1){
							val[j.to] = -1;
							q.push(j);
						}
					}
				}
			}
		}

		int cnt=0;

		for(int i=1;i<=n;i++){
			if(val[i]==-1){
				++cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}